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
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

template<typename T>
istream & operator >> (istream &in, vector<T> &a) {
  for (T& x : a) in >> x;
  return in;
}

template<typename T>
ostream & operator << (ostream &out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) {
      out << ' ';
    } 
    f = false;
    out << x;
  }
  return out;
}

// ========================================================================= //

int solve1(vector<int> const& col, vector<set<int>> e, int cc) {
  int n = sz(col);
  set<int> leafs[3];
  for (int i = 0; i < n; ++i)
    if (sz(e[i]) <= 1)
      leafs[col[i]].insert(i);

  int rem = n;
  int ans = 0;

  vector<char> deld(n, 0);
  auto vdel = [&] (int v) {
    if (deld[v]) return;
    --rem;
    assert(sz(e[v]) <= 1);
    leafs[col[v]].erase(v);
    deld[v] = 1;
    if (sz(e[v]) == 1) {
      int nv = *e[v].begin();
      e[v].clear();
      if (deld[nv]) return;
      e[nv].erase(v);
      if (sz(e[nv]) <= 1)
        leafs[col[nv]].insert(nv);
    }
  };

  for (; rem > 0; cc = 3 - cc) {
    ++ans;
    while (true) {
      if (!leafs[0].empty()) {
        vdel(*leafs[0].begin());
      } else if (!leafs[cc].empty()) {
        vdel(*leafs[cc].begin());
      } else {
        break;
      }
    }
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> col(n);
  cin >> col;
  vector<set<int>> e(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    e[x].insert(y);
    e[y].insert(x);
  }

  cout << min(solve1(col, e, 1), solve1(col, e, 2)) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

  return 0;
}