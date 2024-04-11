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

const int LOGN = 30;

vector<int> res;
vector<int> a;
vector<vector<int>> gr;
vector<int> h;
int timer = 0;
vector<int> tin, tout;

void dfs(int v, int p) {
  if (p != -1) h[v] = h[p] + 1;
  res[v] ^= a[v];
  tin[v] = timer++;
  for (int u : gr[v]) {
    if (u == p) continue;
    dfs(u, v);
    res[v] ^= res[u];
  }
  tout[v] = timer++;
}

bool isPred(int v, int u) {
  return tin[v] <= tin[u] && tout[u] <= tout[v];
}

void solve() {
  int n, k;
  cin >> n >> k;

  int total = 0;
  timer = 0;
  res.assign(n, 0);
  h.assign(n, 0);
  a.assign(n, 0);
  tin.assign(n, 0);
  tout.assign(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    total ^= a[i];
  }

  gr.assign(n, {});
  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
  }
  dfs(0, -1);

  if (!total) {
    cout << "YES\n";
    return;
  }

  if (k == 2) {
    cout << "NO\n";
    return;
  }

  vector<int> vs, us;
  for (int v = 0; v < n; ++v) {
    if (res[v] == total) vs.pb(v); 
    if (!res[v]) us.pb(v);
  }
  sort(all(vs), [&](int v, int u) {
    return h[v] > h[u];
  });

  for (int i = 1; i < (int) vs.size(); ++i) {
    if (!isPred(vs[i], vs[0])) {
      cout << "YES\n";
      return;
    }
  }
  for (int u : us) {
    if (isPred(u, vs[0])) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}