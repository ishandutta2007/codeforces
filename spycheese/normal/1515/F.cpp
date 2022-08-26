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
const int MOD = 1000000007;
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

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }

// ========================================================================= //

int getRoot(vector<int> &p, int v) {
  return p[v] == -1 ? v : p[v] = getRoot(p, p[v]);
}

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  ll x;
  cin >> n >> m >> x;

  vector<vector<ipair>> e(n);
  vector<ll> w(n);
  cin >> w;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    e[a].push_back({b, i});
    e[b].push_back({a, i});
  }

  vector<int> pp(n, -1);
  set<pair<ll, int>> ws;
  ll ss = 0;
  for (int i = 0; i < n; ++i) {
    ws.emplace(w[i], i);
    ss += w[i];
  }

  if (ss < x * (n - 1)) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";

  for (int iter = 0; iter < n - 1; ++iter) {
    int v1 = ws.rbegin()->Y;
    int v2 = -1;
    int ei = -1;
    while (true) {
      v2 = getRoot(pp, e[v1].back().X);
      ei = e[v1].back().Y;
      e[v1].pop_back();
      if (v2 != v1)
        break;
    }
    ws.erase({w[v1], v1});
    ws.erase({w[v2], v2});
    pp[v2] = v1;
    w[v1] += w[v2] - x;
    ws.insert({w[v1], v1});
    if (sz(e[v1]) < sz(e[v2]))
      swap(e[v1], e[v2]);
    e[v1].insert(e[v1].end(), all(e[v2]));
    e[v2].clear();
    cout << ei + 1 << "\n";
  }

  return 0;
}