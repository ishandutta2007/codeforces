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

map<int, int> chc;
int ask(int d) {
  if (chc.count(d)) return chc[d];
  vector<ipair> a;
  for (int x = 1; x <= 200; ++x)
    if (x % (1 << d) == 0)
      for (int y = 1; y <= 200; ++y)
        a.push_back({x, y});
  if (a.empty()) return chc[d] = 0;
  cout << "? " << sz(a) << "\n";
  for (auto p : a) cout << p.X << " " << p.Y << " ";
  cout << "\n";
  cout.flush();
  int n;
  cin >> n;
  return chc[d] = n;
}

void answer(int x) {
  cout << "! " << x << "\n";
  cout.flush();
}

void solve() {
  chc.clear();
  int total = ask(0);
  int cl = 0, cr = 8;
  while (cr - cl > 1) {
    int mid = (cl + cr) / 2;
    if (ask(mid))
      cl = mid;
    else
      cr = mid;
  }
  int x = abs(ask(cl) - ask(cr) * 2);
  answer((x - 1 + (total / x - 1)) * 2);
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}