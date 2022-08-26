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

struct DSU {
  vector<int> p;
  DSU() = default;
  DSU(int n) : p(n, -1) {}
  
  int get(int v) { return p[v] == -1 ? v : p[v] = get(p[v]); }
  bool merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    p[y] = x;
    return true;
  }
};

const int M = 1000011;

vector<int> calcPrimes(int max) {
  vector<char> p(max, false);
  vector<int> res;
  int i;
  for (i = 2; i * i < max; ++i)
    if (!p[i]) {
      for (int j = i * i; j < max; j += i)
        p[j] = 1;
      res.push_back(i);
    }
  for (; i < max; ++i)
    if (!p[i])
      res.push_back(i);
  return res;
}

namespace std {
  template<typename A, typename B>
  struct hash<pair<A, B>> {
    size_t operator()(pair<A, B> const& p) const {
      size_t h1 = hash<A>()(p.first);
      size_t h2 = hash<B>()(p.second);
      return hash<size_t>()((h1 * 257ull) ^ h2);
    }
  };

  template<>
  struct hash<pair<int, int>> {
    size_t operator()(pair<int, int> const& p) const {
      return hash<size_t>()((((size_t)p.first) << 32) ^ (size_t)p.second);
    }
  };

  template<typename T>
  struct hash<vector<T>> {
    size_t operator()(vector<T> const& v) const {
      size_t h = 0xabacabadabacabaull;
      for (auto const& x : v) {
        h = hash<size_t>()((h * 257ull) ^ hash<T>()(x));
      }
      return h;
    }
  };
}

void solve() {
  vector<int> primes = calcPrimes(M);
  static int p2i[M];
  memset(p2i, -1, sizeof(p2i));
  for (int i = 0; i < sz(primes); ++i)
    p2i[primes[i]] = i;
  DSU dsu(sz(primes));
  unordered_set<ipair> mp2;

  int n, q;
  cin >> n >> q;
  vector<int> a(n), ap0;
  cin >> a;

  for (int x : a) {
    int p0 = -1;
    for (int p : primes) {
      if (p * p > x) break;
      if (x % p == 0) {
        if (p0 == -1)
          p0 = p2i[p];
        else
          dsu.merge(p0, p2i[p]);
        do { x /= p; } while (x % p == 0);
      }
    }
    if (x != 1) {
      if (p0 == -1)
        p0 = p2i[x];
      else
        dsu.merge(p0, p2i[x]);
    }
    ap0.push_back(p0);
  }

  for (int i = 0; i < n; ++i) {
    int x1 = a[i] + 1;
    vector<int> e = {dsu.get(ap0[i])};
    for (int p : primes) {
      if (p * p > x1) break;
      if (x1 % p == 0) {
        e.push_back(dsu.get(p2i[p]));
        do { x1 /= p; } while (x1 % p == 0);
      }
    }
    if (x1 != 1) {
      e.push_back(dsu.get(p2i[x1]));
    }

    sort(all(e));
    e.erase(unique(all(e)), e.end());
    for (int j = 0; j < sz(e); ++j)
      for (int k = j + 1; k < sz(e); ++k) {
        int x = e[j], y = e[k];
        mp2.insert({x, y});
      }
  }

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    x = dsu.get(ap0[x]), y = dsu.get(ap0[y]);
    if (x > y) swap(x, y);
    int ans = 2;
    if (x == y)
      ans = 0;
    else {
      if (mp2.count({x, y})) ans = 1;
    }
    cout << ans << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  //cin >> t;
  while (t--) solve();
  return 0;
}