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

vector<ipair> solve1(string &s, int m, int k) {
  int n = sz(s);
  vector<ipair> ans;
  for (int i = 0; i < m - k - 1; ++i) {
    int j = i;
    int cnt = 0;
    while (cnt < k) {
      if (s[j] == '1') ++cnt;
      ++j;
    }
    ans.push_back({i, j});
    assert(ans.back().X < ans.back().Y && 0 <= ans.back().X && ans.back().Y <= n);
    reverse(s.begin() + i, s.begin() + j);
  }
  int st = m - k - 1;
  for (int i = 0; i < k; ++i) {
    int j1 = st;
    while (s[j1] == '0') ++j1;
    int j2 = n - 1;
    while (s[j2] == '0') --j2;
    if (i % 2 == 0) {
      ans.push_back({j1 + 1, j2 + 1});
    } else {
      ans.push_back({j1, j2});
    }
    assert(ans.back().X < ans.back().Y && 0 <= ans.back().X && ans.back().Y <= n);
    reverse(s.begin() + ans.back().X, s.begin() + ans.back().Y);
  }
  if (k % 2 == 1) {
    int st2 = st;
    while (s[st2] == '0') ++st2;
    int end = st2 + k;
    if (st2 == st) return ans;
    for (int i = 0; i < k + 1; ++i) {
      if (i % 2 == 0) {
        ans.push_back({st, end});
      } else {
        ans.push_back({st + 1, end + 1});
      }
      assert(ans.back().X < ans.back().Y && 0 <= ans.back().X && ans.back().Y <= n);
      reverse(s.begin() + ans.back().X, s.begin() + ans.back().Y);
    }
  }
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  string s1, s2;
  cin >> s1 >> s2;
  int m = 0;
  for (char c : s1) m += (c == '1');
  {
    int m2 = 0;
    for (char c : s2) m2 += (c == '1');
    if (m != m2) {
      cout << "-1\n";
      return;
    }
  }

  if (k == 0 || k > m) {
    if (s1 == s2) {
      cout << "0\n";
    } else {
      cout << "-1\n";
    }
    return;
  }

  if (k == m) {
    if (s1 == s2) {
      cout << "0\n";
      return;
    }
    vector<ipair> ans1, ans2;
    int l1 = n - 1;
    while (s1[l1] == '0') --l1;
    int l2 = n - 1;
    while (s2[l2] == '0') --l2;
    ans1.push_back({0, l1 + 1});
    reverse(s1.begin(), s1.begin() + l1 + 1);
    ans2.push_back({0, l2 + 1});
    reverse(s2.begin(), s2.begin() + l2 + 1);
    if (s1 != s2) {
      l1 = n - 1;
      while (s1[l1] == '0') --l1;
      ans1.push_back({0, l1 + 1});
      reverse(s1.begin(), s1.begin() + l1 + 1);
      if (s1 != s2) {
        cout << "-1\n";
        return;
      }
    }
    ans1.push_back(ans2[0]);
    cout << sz(ans1) << "\n";
    for (ipair p : ans1) cout << p.X + 1 << " " << p.Y << "\n";
    return;
  }

  vector<ipair> ans1 = solve1(s1, m, k);
  vector<ipair> ans2 = solve1(s2, m, k);
  if (s1 != s2) {
    cout << "-1\n";
    return;
  }
  cout << sz(ans1) + sz(ans2) << "\n";
  reverse(all(ans2));
  for (ipair p : ans1) cout << p.X + 1 << " " << p.Y << "\n";
  for (ipair p : ans2) cout << p.X + 1 << " " << p.Y << "\n";
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