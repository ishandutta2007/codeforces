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

vector<int> sparseD = {0, 0};
void updateSparseD(int n) {
  for (int i = sz(sparseD); i <= n; ++i) {
    int v = sparseD.back();
    if (i >= (1 << (v + 1))) ++v;
    sparseD.push_back(v);
  }
}

template<typename T, typename Cmp = less<T>>
struct Sparse {
  vector<vector<T>> s;
  Cmp cmp;

  T min(T const& a, T const& b) {
    if (cmp(a, b)) return a;
    return b;
  }

  Sparse() : s(1) {}

  Sparse(vector<T> a) {
    int n = sz(a);
    int d = 1;
    while ((1 << d) <= n) ++d;
    s.resize(d);
    s[0] = move(a);
    for (int i = 1; i < d; ++i) {
      s[i].resize(n - (1 << i) + 1);
      for (int j = 0; j < sz(s[i]); ++j)
        s[i][j] = min(s[i-1][j], s[i-1][j + (1 << (i - 1))]);
    }
    updateSparseD(n);
  }

  void push_back(T x) {
    s[0].push_back(move(x));
    int n = sz(s[0]);
    for (int i = 1; (1 << i) <= n; ++i) {
      if (sz(s) == i) s.emplace_back();
      s[i].push_back(min(s[i-1].back(), s[i-1][n - (1 << i)]));
    }
    updateSparseD(n);
  }

  void pop_back() {
    for (auto &v : s) {
      if (v.empty()) break;
      v.pop_back();
    }
  }

  T get(int l, int r) {
    if (l >= r) return numeric_limits<T>::max();
    int d = sparseD[r - l];
    return min(s[d][l], s[d][r - (1 << d)]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<ll> s = {0};
  {
    vector<ll> a(n), b(n);
    cin >> a >> b;
    for (int i = 0; i < n; ++i)
      s.push_back(s.back() + b[i] - a[i]);
  }
  Sparse<ll, less<ll>> smin(s);
  Sparse<ll, greater<ll>> smax(s);

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l;
    if (s[l] != s[r] || smin.get(l, r) < s[l]) {
      cout << "-1\n";
      continue;
    }
    cout << smax.get(l, r) - s[l] << "\n";
  }

  return 0;
}