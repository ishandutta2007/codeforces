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

void solve() {
  string s;
  cin >> s;
  int n = sz(s);
  vector<int> cnt(26, 0);
  for (char c : s) ++cnt[c - 'a'];
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] == 1) {
      cout << char(i + 'a');
      for (int j = 0; j < 26; ++j)
        if (j != i)
          for (int x = 0; x < cnt[j]; ++x)
            cout << char(j + 'a');
      cout << "\n";
      return;
    }
  }

  int c0 = 0;
  while (!cnt[c0]) ++c0;
  if (cnt[c0] == sz(s)) {
    cout << s << "\n";
    return;
  }
  if (cnt[c0] >= 2 && cnt[c0] - 2 <= (n - 2) / 2) {
    cnt[c0] -= 2;
    int pa = true;
    cout << char(c0 + 'a');
    cout << char(c0 + 'a');
    for (int iter = 0; iter < n - 2; ++iter) {
      int c = 0;
      while (!cnt[c] || (pa && c == c0)) ++c;
      --cnt[c];
      pa = (c == c0);
      cout << char(c + 'a');
    }
    cout << "\n";
    return;
  }
  int c1 = c0 + 1;
  while (!cnt[c1]) ++c1;
  cout << char(c0 + 'a');
  cout << char(c1 + 'a');
  --cnt[c0];
  --cnt[c1];
  int pa = 0;
  for (int rem = n - 2; rem > 0; --rem) {
    int c = 0;
    while (!cnt[c] || (pa && c == c1) || (c == c0 && rem == cnt[c0] + cnt[c1] && cnt[c1])) ++c;
    --cnt[c];
    pa = (c == c0);
    cout << char(c + 'a');
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}