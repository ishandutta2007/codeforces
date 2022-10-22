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

int n;
vector <int> cnt;
vector <int> a;
vector <int> par;
vector <vector <int>> gr;

const int INF = 1e9 + 7;

void dfs(int v, int p) {
  par[v] = p;
  for (int u : gr[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
}

void solve() {
  cin >> n;
  a.assign(n, 0);
  gr.assign(n, {});
  cnt.assign(n, 0);
  par.assign(n, -1);

  bool has_one = false;
  bool has_two = false;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 1) {
      has_one = true;
    } else if (a[i] == 2) {
      has_two = true;
    }
  }

  vector <int> leaves[3];
  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
    ++cnt[v], ++cnt[u];
  }

  if (n < 3) {
    cout << max(1, has_one + has_two) << "\n";
    return;
  }

  auto cntw = cnt;

  int res = INF;

  for (int turn = 0; turn < 2; ++turn) {
    int uk = turn + 1;
    cnt = cntw;

    vector <bool> deleted(n, false);

    int now = 0;
    for (int v = 0; v < n; ++v) {
      if (cnt[v] == 1) {
        leaves[a[v]].pb(v);
      }
    }

    int total = n;
    while (total) {

      while (leaves[0].size() || leaves[uk].size()) {
        while (leaves[0].size()) {
          int v = leaves[0].back();
          leaves[0].pop_back();
          --total;

          for (int p : gr[v]) {
            --cnt[p];
            if (cnt[p] == 1) {
              leaves[a[p]].pb(p);
            }
          }
        }
        while (leaves[uk].size()) {
          int v = leaves[uk].back();
          leaves[uk].pop_back();
          --total;

          for (int p : gr[v]) {
            --cnt[p];
            if (cnt[p] == 1) {
              leaves[a[p]].pb(p);
            }
          } 
        }
      }
      uk = 3 - uk;
      ++now;
    }
    res = min(res, now);
  }

  cout << res << "\n";
}

int main(){
#ifdef LOCAL
 freopen("E_input.txt", "r", stdin);
 //freopen("E_output.txt", "w", stdout);
#endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 int t;
 cin >> t;

 for (int i = 0; i < t; ++i) {
  solve();
 }
}