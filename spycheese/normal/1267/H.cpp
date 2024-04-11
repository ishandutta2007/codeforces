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

vector<int> solve(vector<int> const& p) {
  int n = sz(p);
  vector<int> ans(n);
  vector<int> m(n);
  if (n > 4) {
    vector<int> p2;
    for (int i = 0; i < n; i += 3) {
      int j = min_element(p.begin() + i, p.begin() + min(i + 3, n)) - p.begin();
      p2.push_back(p[j]);
      m[j] = 1;
    }
    vector<int> ans2 = solve(p2);
    int j = 0;
    for (int i = 0; i < n; ++i)
      if (m[i])
        ans[i] = ans2[j++] + 3;
  }
  vector<int> order(n);
  iota(all(order), 0);
  sort(all(order), [&](int x, int y) { return p[x] < p[y]; });
  set<int> was;
  for (int i : order) {
    auto it = was.insert(i).first;
    if (m[i]) continue;
    int cnt = 1;
    bool used[4] = {0, 0, 0, 0};
    int u1 = -1, u2 = -1;
    {
      auto it2 = it;
      it2++;
      while (it2 != was.end() && !m[*it2]) {
        used[ans[*it2]] = 1;
        if (u1 == -1) u1 = ans[*it2];
        ++cnt;
        ++it2;
      }
    }
    {
      auto it2 = it;
      while (it2 != was.begin()) {
        --it2;
        if (m[*it2]) break;
        used[ans[*it2]] = 1;
        if (u2 == -1) u2 = ans[*it2];
        ++cnt;
      }
    }
    if (cnt == 4) {
      ans[i] = 1;
      while (ans[i] == u1 || ans[i] == u2) ++ans[i];
    } else {
      ans[i] = 1;
      while (used[ans[i]]) ++ans[i];
    }
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    p[x] = i;
  }
  cout << solve(p) << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}