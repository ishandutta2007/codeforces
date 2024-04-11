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

const int S = 333;
const string COLORS[] = {
  "red", "orange", "yellow", "green", "blue", "indigo", "violet"
};

struct Block {
  int lock = -1;
  int ncol[2] = {-1, -1};

  void update(vector<int> const& a, int l, int r) {
    lock = -1;
    ncol[0] = -1;
    ncol[1] = -1;
    for (int i = l; i < r; ++i) {
      if (a[i] == -1) lock = 1;
      else if (a[i] == -2) lock = 0;
      else {
        if (lock != 1) ncol[0] = a[i];
        if (lock == 0) ncol[1] = a[i];
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "lock") {
      a[i] = -1;
    } else if (s == "unlock") {
      a[i] = -2;
    } else {
      int c = 0;
      while (COLORS[c] != s) ++c;
      a[i] = c;
    }
  }

  vector<Block> blocks((n + S - 1) / S);
  for (int i = 0; i < sz(blocks); ++i) {
    blocks[i].update(a, i * S, min(i * S + S, n));
  }
  
  int t;
  cin >> t;
  for (int ii = 0; ii <= t; ++ii) {
    if (ii != 0) {
      int i;
      string s;
      cin >> i >> s;
      --i;
      if (s == "lock") {
        a[i] = -1;
      } else if (s == "unlock") {
        a[i] = -2;
      } else {
        int c = 0;
        while (COLORS[c] != s) ++c;
        a[i] = c;
      }
      blocks[i / S].update(a, i / S * S, min(i / S * S + S, n));
    }
    int lock = 0;
    int c = 4;
    for (Block const& b : blocks) {
      c = b.ncol[lock] == -1 ? c : b.ncol[lock];
      lock = b.lock == -1 ? lock : b.lock;
    }
    cout << COLORS[c] << "\n";
  }

  return 0;
}