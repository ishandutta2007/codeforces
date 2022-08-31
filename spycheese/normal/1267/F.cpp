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

int main() {
  ios::sync_with_stdio(false);

  int n, m, k1, k2;
  cin >> n >> m >> k1 >> k2;
  vector<int> a1(k1), a2(k2);
  cin >> a1 >> a2;
  for (int& i : a1) --i;
  for (int& i : a2) --i;
  if (k1 > m - 1) {
    cout << "No\n";
    return 0;
  }
  if (k2 > n - 1) {
    cout << "No\n";
    return 0;
  }
  while (sz(a1) < m - 1) a1.push_back(rnd(0, n - 1));
  while (sz(a2) < n - 1) a2.push_back(n + rnd(0, m - 1));

  vector<int> cnt(n + m);
  for (int i : a1) ++cnt[i];
  for (int i : a2) ++cnt[i];
  reverse(all(a1));
  reverse(all(a2));
  set<ipair> cnts;
  for (int i = 0; i < n + m; ++i)
    cnts.emplace(cnt[i], i);
  cout << "Yes\n";
  vector<int> used(n + m);
  for (int i = 0; i < n + m - 2; ++i) {
    int v1 = cnts.begin()->Y;
    used[v1] = true;
    cnts.erase(cnts.begin());
    int v2;
    if (v1 < n) {
      v2 = a2.back();
      a2.pop_back();
    } else {
      v2 = a1.back();
      a1.pop_back();
    }
    cout << v1 + 1 << " " << v2 + 1 << "\n";
    cnts.erase({cnt[v2], v2});
    cnts.insert({--cnt[v2], v2});
  }
  int v = 0;
  while (used[v]) ++v;
  cout << n + m << " " << v + 1 << "\n";

  return 0;
}