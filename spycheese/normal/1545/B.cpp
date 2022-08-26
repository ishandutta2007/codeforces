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
const int MOD = 998244353;
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

int pw(int a, ll b) {
  int r = 1;
  for (; b; b >>= 1) {
    if (b & 1) r = 1LL * r * a % MOD;
    a = 1LL * a * a % MOD;
  }
  return r;
}

int solve(string s) {
  {
    int cnt = 0;
    while (cnt < sz(s) && s[cnt] == '1') ++cnt;
    if (cnt % 2) {
      s.erase(s.begin());
    }
  }
  {
    int cnt = 0;
    while (cnt < sz(s) && s[sz(s) - 1 - cnt] == '1') ++cnt;
    if (cnt % 2) {
      s.pop_back();
    }
  }
  int n = sz(s);

  int cnt1 = 0, cnt2 = 0;
  int i = 0;
  while (i < n) {
    if (s[i] == '0') {
      ++i;
      continue;
    }
    int len = 1;
    while (i + len < n && s[i + len] == '1')
      ++len;
    if (len % 2) ++cnt1;
    cnt2 += len / 2;
    i += len;
  }

  int x = sz(s) - cnt1 - cnt2;
  int y = cnt2;

  int ans = 1;
  for (int i = y + 1; i <= x; ++i)
    ans = 1LL * ans * i % MOD;
  for (int i = 1; i <= x - y; ++i)
    ans = 1LL * ans * pw(i, MOD - 2) % MOD;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    cout << solve(s) << "\n";
  }
  return 0;
}