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

string s;
int cur;

vector<int> go(int start, int end) {
  if (end - start == 1) return {start};
  int mid = (start + end) / 2;
  vector<int> a1 = go(start, mid);
  if (a1.empty()) return a1;
  vector<int> a2 = go(mid, end);
  if (a2.empty()) return a2;
  vector<int> a;

  int i1 = 0, i2 = 0;
  while (i1 < sz(a1) && i2 < sz(a2)) {
    if (cur == sz(s)) return {};
    if (s[cur++] == '0')
      a.push_back(a1[i1++]);
    else
      a.push_back(a2[i2++]);
  }
  while (i1 < sz(a1)) a.push_back(a1[i1++]);
  while (i2 < sz(a2)) a.push_back(a2[i2++]);

  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> s;

  for (int len = 1; len <= 1000; ++len) {
    cur = 0;
    vector<int> a = go(0, len);
    if (sz(a) == 0 || cur != sz(s)) continue;
    vector<int> b(len);
    for (int i = 0; i < len; ++i)
      b[a[i]] = i + 1;
    cout << len << "\n" << b << "\n";
    return 0;
  }

  return 0;
}