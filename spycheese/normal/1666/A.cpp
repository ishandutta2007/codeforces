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

template<typename T, typename M> T& updMin(T& a, M const& b) { if (b < a) a = b; return a; }
template<typename T, typename M> T& updMax(T& a, M const& b) { if (a < b) a = b; return a; }

ll divFloor(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b : (a - b + 1) / b; }
ll divCeil(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b : a / b; }
ll divFloorS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? (a + b - 1) / b - 1 : a / b - 1; }
ll divCeilS(ll a, ll b) { if (b < 0) { a = -a; b = -b; } return a >= 0 ? a / b + 1 : (a - b + 1) / b + 1; }
template<typename T> T pw(T a, ll b) { T r = T(1); if (b <= 0) return r; for (;; b >>= 1) { if (b & 1) r *= a; if (b) a *= a; else return r; } }

template<typename T> void unique(vector<T> &a) { sort(all(a)); a.erase(unique(all(a)), a.end()); }
template<typename T> int lowerBound(vector<T> const& a, T const& x) { return lower_bound(all(a), x) - a.begin(); }
template<typename T> int upperBound(vector<T> const& a, T const& x) { return upper_bound(all(a), x) - a.begin(); }

template<typename K, typename V> V getOrDef(map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename K, typename V> V getOrDef(unordered_map<K, V> const& a, K const& k, V const& def = V()) { auto it = a.find(k); return it == a.end() ? def : it->second; }
template<typename T> T getOrDef(vector<T> const& a, int i, T const& def = T()) { return i < 0 || i >= sz(a) ? def : a[i]; }
template<typename T> T getOrDef(vector<vector<T>> const& a, int i, int j, T const& def = T()) { return i < 0 || i >= sz(a) ? def : getOrDef(a[i], j, def); }
template<typename T> T backOrDef(vector<T> const& a, T const& def = T()) { return a.empty() ? def : a.back(); }

template<typename A, typename B> istream& operator >> (istream& in, pair<A, B>& p) { return in >> p.X >> p.Y; }
template<typename A, typename B> ostream& operator << (ostream& out, pair<A, B> const& p) { return out << p.X << " " << p.Y; }
template<typename T> istream& operator >> (istream& in, vector<T>& a) { for (T& x : a) in >> x; return in; }
template<typename T> ostream& operator << (ostream& out, vector<T> const& a) {
  bool f = true;
  for (T const& x : a) {
    if (!f) out << " ";
    f = false; out << x;
  }
  return out;
}
template<typename T> ostream& operator << (ostream& out, vector<vector<T>> const& a) {
  for (vector<T> const& x : a) out << x << "\n";
  return out;
}

template<typename T> bool isZero(T const& x) { return x == T(0); }
bool isZero(float x) { return abs(x) < EPS; }
bool isZero(double x) { return abs(x) < EPS; }
bool isZero(long double x) { return abs(x) < EPS; }
template<typename T> int sgn(T const& x) { if (isZero(x)) return 0; return x > 0 ? 1 : -1; }

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  vector<int> s;
  {
    string s0;
    cin >> s0;
    for (char c : s0) {
      if (c == 'D') s.push_back(0);
      if (c == 'R') s.push_back(1);
      if (c == 'U') s.push_back(2);
      if (c == 'L') s.push_back(3);
    }
  }

  int ans = 0;
  int n = sz(s);

  vector<bitset<20032>> ansC(n);

  vector<char> cu(n), cm(n), cd(n);
  vector<char> ru(n), rm(n), rd(n);

  vector<int> where(n, -1);
  for (int l = 0; l < n; ++l) {
    for (int r = l + 2; r <= n; r += 2) {
      if (s[r - 2] == 1 && s[r - 1] == 3) {
        if (!ansC[l][r]) {
          ansC[l][r] = 1;
          ++ans;
          where[l] = max(where[l], r);
        }
      } else
        break;
    }
    for (int r = l + 2; r <= n; r += 2) {
      if (s[r - 2] == 0 && s[r - 1] == 2) {
        if (!ansC[l][r]) {
          ansC[l][r] = 1;
          ++ans;
          where[l] = max(where[l], r);
        }
      } else
        break;
    }
  }

  vector<int> cnt0(n);
  for (int i = 1; i < n - 1; ++i)
    cnt0[i] = (s[i - 1] == 1) + (s[i + 1] == 3);

  for (int w = n / 2; w >= 2; --w) {
    for (int i = 1; i < n - 1; ++i) {
      int v = s[i];
      int u = (i - w < 0 ? -1 : s[i - w]);
      int d = (i + w >= n ? -1 : s[i + w]);
      
      bool ccu = 1, ccm = 1, ccd = 1;
      if (v == 0) ccd = 0;
      if (v == 2) ccu = 0;
      int cnt = cnt0[i];
      if (cnt + (u == 0) + (d == 2) != 1) ccm = 0;
      if (cnt + (u == 0) != 1) ccd = 0;
      if (cnt + (d == 2) != 1) ccu = 0;

      cu[i] = ccu;
      cm[i] = ccm;
      cd[i] = ccd;
    }

    int nnu = n, nnm = n, nnd = n;

    for (int i = n - 1; i >= 0; --i) {
      if (i + w <= n) {
        bool rru = 1, rrm = 1, rrd = 1;
        int v1 = s[i], v2 = s[i + w - 1];
        if (v1 == 3 || v2 == 1)
          rru = rrm = rrd = 0;
        else {
          int i2 = i + w - 1;

          if (i + w + w > n || v1 == 2 || v2 == 2)
            rru = 0;
          else if (nnu < i + w - 1)
            rru = 0;
          else if ((s[i + 1] == 3) + (s[i + w] == 2) != 1) rru = 0;
          else if ((s[i2 - 1] == 1) + (s[i2 + w] == 2) != 1) rru = 0;

          if (i - w < 0 || v1 == 0 || v2 == 0)
            rrd = 0;
          else if (nnd < i + w - 1)
            rrd = 0;
          else if ((s[i + 1] == 3) + (s[i - w] == 0) != 1) rrd = 0;
          else if ((s[i2 - 1] == 1) + (s[i2 - w] == 0) != 1) rrd = 0;

          if (i + w + w > n || i - w < 0 || nnm < i + w - 1) rrm = 0;
          else if ((s[i + 1] == 3) + (s[i + w] == 2) + (s[i - w] == 0) != 1) rrm = 0;
          else if ((s[i2 - 1] == 1) + (s[i2 + w] == 2) + (s[i2 - w] == 0) != 1) rrm = 0;
        }
        ru[i] = rru;
        rm[i] = rrm;
        rd[i] = rrd;
      }
      if (!cu[i]) nnu = i;
      if (!cm[i]) nnm = i;
      if (!cd[i]) nnd = i;
    }
    for (int i0 = 0; i0 < w; ++i0) {
      int prvNM = n;
      static vector<int> dws;
      int j0 = 0;
      dws.clear();
      for (int i = n - 1 - i0; i >= 0; i -= w) {
        if (ru[i]) {
          while (j0 < sz(dws) && dws[j0] > prvNM) ++j0;
          for (int j = j0; j < sz(dws); ++j) {
            int x = dws[j];
            if ((w & 1) == 0 && where[i] >= x) break;
            int l = i, r = x + w;
            if (!ansC[l][r]) {
              ansC[l][r] = 1;
              ++ans;
            }
          }
        }
        if (rd[i]) dws.push_back(i);
        if (!rm[i]) prvNM = i;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}