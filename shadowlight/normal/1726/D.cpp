#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

vector<vector<pair<int, int>>> gr;
string res;
vector<bool> used;
vector<int> pr, he;

void dfs(int v, int p) {
  used[v] = true;
  if (p != -1) he[v] = he[p] + 1;

  for (auto [u, id] : gr[v]) {
    if (u == p) continue;
    if (!used[u]) {
      res[id] = '1';
      dfs(u, v);
      pr[u] = id;
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  gr.assign(n, {});
  used.assign(n, false);
  pr.assign(n, -1);
  he.assign(n, 0);
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb({u, i});
    gr[u].pb({v, i});
    edges.pb({v, u});
  }
  res = string(m, '0');
  dfs(0, -1);
  vector<int> cnt(n, 0);
  for (int i = 0; i < m; ++i) {
    if (res[i] == '1') continue;
    auto [v, u] = edges[i];
    ++cnt[v], ++cnt[u];
  }
  bool even = true;
  for (int i = 0; i < n; ++i) {
    even &= ((cnt[i] % 2) == 0);
  }
  //per(cnt);
  if (even && m != n - 1) {
    int mn = n + 1, id = -1;
    for (int i = 0; i < m; ++i) {
      if (res[i] == '1') continue;
      auto [v, u] = edges[i];
      if (mn > min(he[v], he[u])) {
        id = i;
        mn = min(he[v], he[u]);
      }
    }
    res[id] = '1';
    auto [v, u] = edges[id];
    if (he[v] < he[u]) swap(v, u);
    res[pr[v]] = '0';
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}