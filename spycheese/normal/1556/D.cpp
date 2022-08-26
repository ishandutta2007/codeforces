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

int ask(string const& s, int i, int j) {
  ++i;
  ++j;
  cout << s << " " << i << " " << j << "\n";
  cout.flush();
  int x;
  cin >> x;
  return x;
}

void answer(int x) {
  cout << "finish " << x << "\n";
  cout.flush();
}

int main() {
  ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  --k;
  vector<int> a(n);

  int ors[3] = {
    ask("or", 0, 1),
    ask("or", 1, 2),
    ask("or", 2, 0)
  };
  int ands[3] = {
    ask("and", 0, 1),
    ask("and", 1, 2),
    ask("and", 2, 0)
  };

  for (int i = 0; i < 30; ++i) {
    int cors[3] = {
      !!(ors[0] & (1 << i)),
      !!(ors[1] & (1 << i)),
      !!(ors[2] & (1 << i))
    };
    int cands[3] = {
      !!(ands[0] & (1 << i)),
      !!(ands[1] & (1 << i)),
      !!(ands[2] & (1 << i))
    };
    for (int b0 = 0; b0 < 2; ++b0)
      for (int b1 = 0; b1 < 2; ++b1)
        for (int b2 = 0; b2 < 2; ++b2) {
          if ((b0 | b1) == cors[0] &&
              (b1 | b2) == cors[1] &&
              (b2 | b0) == cors[2] &&
              (b0 & b1) == cands[0] &&
              (b1 & b2) == cands[1] &&
              (b2 & b0) == cands[2]) {
            a[0] |= (b0 << i);
            a[1] |= (b1 << i);
            a[2] |= (b2 << i);
          }
        }
  }

  for (int i = 3; i < n; ++i) {
    a[i] = a[0] ^ ask("or", 0, i) ^ ask("and", 0, i);
  }
  sort(all(a));
  answer(a[k]);

  return 0;
}