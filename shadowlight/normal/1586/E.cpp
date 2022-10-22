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
 
struct DSU {
  int n;
  vector<int> r, p;
 
  DSU(int n) : n(n), r(n), p(n) {
    iota(all(p), 0);
  }
 
  int get(int v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
  }
 
  bool uni(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u) return false;
    if (r[v] == r[u]) ++r[u];
    if (r[v] > r[u]) swap(v, u);
    p[v] = u;
    return true;
  }
};
 
 
vector<vector<pair<int, int>>> gr;
vector<int> counts;
vector<vector<int>> paths;
vector<int> path;
 
bool dfs(int v, int p, int t) {
  path.pb(v);
  if (v == t) {
    return true;
  }
  for (auto [u, id] : gr[v]) {
    if (u == p) continue;
    ++counts[id];
    if (dfs(u, v, t)) {
      return true;
    }
    --counts[id];
  }
  path.pop_back();
  return false;
}
 
const int N = 3e5 + 7;
 
int res = 0;
bool used[N];
 
int dp_dfs(int v, int p) {
  used[v] = true;
  int sum = 0;
  for (auto [u, id] : gr[v]) {
    if (u == p) continue;
    int add = dp_dfs(u, v);
    if (counts[id] % 2) {
        ++sum;
    } else {
        res += add;
    }
  }
  //per(v, sum);
  res += sum / 2;
  return sum % 2;
}
 
int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
  int n, m;
  cin >> n >> m;
 
  DSU dsu(n);
  gr.resize(n);
 
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    if (dsu.uni(v, u)) {
      //per(v, u);
      gr[v].pb({u, counts.size()});
      gr[u].pb({v, counts.size()});
      counts.pb(0);
    }
  }
 
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    dfs(v, -1, u);
    paths.pb(path);
    path.clear();
  }
  //per(counts);
 
  bool is_even = true;
  for (int x : counts) {
    is_even &= (x % 2 == 0);
  }
  if (is_even) {
    cout << "YES\n";
    for (auto path : paths) {
      cout << path.size() << "\n";
      for (int x : path) {
        cout << x + 1 << " ";
      }
      cout << "\n";
    }
    return 0;
  }
  cout << "NO\n";
 
  res += dp_dfs(0, -1);
  cout << res << "\n";
}