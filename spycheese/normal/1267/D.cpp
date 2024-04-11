#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#define all(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ipair;
typedef pair <ll, ll> lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = numeric_limits<double>::infinity();
const double DNAN = numeric_limits<double>::quiet_NaN();
const double EPS = 1e-9;
const double PI = acos((double)-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

ll divFloor(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b : (a - b + 1) / b; }
ll divCeil(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b : a / b; }
ll divFloorS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b - 1 : a / b - 1; }
ll divCeilS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b + 1 : (a - b + 1) / b + 1; }

template<typename K, typename V> V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename K, typename V> V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }
template<typename T> istream& operator >> (istream& in, vector<T>& a) { for (T& x : a) in >> x; return in; }
template<typename T> ostream& operator << (ostream& out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) out << " ";
    f = false;
    out << x;
  }
  return out;
}

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

const int N = 333;
int n;
int g1[N], g2[N];
bool vis[N];
bool noT[N];
vector<ipair> e;

void dfs(int v) {
  if (vis[v]) return;
  vis[v] = 1;
  for (int nv = 0; nv < n; ++nv) {
    if (vis[nv]) continue;
    if ((noT[v] ? g1[v] : g2[v]) == g1[nv]) {
      e.push_back({v, nv});
      dfs(nv);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    g1[i] = x + y * 2 + z * 4;
  }
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    cin >> x >> y >> z;
    g2[i] = (x + y * 2 + z * 4) & g1[i];
  }

  dfs(0);
  while (true) {
    bool was = false;
    for (int q1 : {1, 2, 4})
      for (int q2 : {1, 2, 4}) {
        if (q1 >= q2) continue;
        int q = q1 + q2;
        vector<int> vs;
        for (int i = 0; i < n; ++i)
          if (!vis[i] && g1[i] == q)
            vs.push_back(i);
        if (vs.empty()) continue;
        int w1 = -1, w2 = -1;
        for (int i = 0; i < n; ++i)
          if (vis[i]) {
            if (g2[i] == q1) w1 = i;
            if (g2[i] == q2) w2 = i;
          }
        if (w1 == -1 || w2 == -1)
          continue;
        if (sz(vs) == 1) {
          int v0 = vs[0];
          e.push_back({w1, v0});
          e.push_back({w2, v0});
          dfs(v0);
          was = true;
          continue;
        }
        int v0 = -1;
        for (int v : vs)
          if (g2[v] == q || g2[v] == 0)
            v0 = v;
        if (v0 != -1) {
          noT[v0] = 1;
          e.push_back({w1, v0});
          e.push_back({w2, v0});
          dfs(v0);
          was = true;
          continue;
        }
        int v1 = -1, v2 = -1;
        int v1c = 0, v2c = 0;
        for (int v : vs)
          if (g2[v] == q1)
            v1 = v, ++v1c;
          else if (g2[v] == q2)
            v2 = v, ++v2c;
        if (v1c) {
          e.push_back({w1, v1});
          e.push_back({w2, v1});
          noT[v1] = (v1c > 1);
          dfs(v1);
        }
        if (v2c && !vis[v2]) {
          e.push_back({w1, v2});
          e.push_back({w2, v2});
          noT[v2] = (v2c > 1);
          dfs(v2);
        }
        was = true;
      }
    if (!was) break;
  }

  for (int i = 0; i < n; ++i)
    if (g1[i] && !vis[i]) {
      cout << "Impossible\n";
      return 0;
    }

  cout << "Possible\n";
  for (int i = 0; i < n; ++i)
    cout << !noT[i] << " ";
  cout << "\n";
  cout << sz(e) << "\n";
  for (auto const& x : e)
    cout << x.X + 1 << " " << x.Y + 1 << "\n";

  return 0;
}