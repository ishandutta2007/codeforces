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
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

template<typename T> T& updMin(T& a, T const& b) { if (b < a) a = b; return a; }
template<typename T> T& updMax(T& a, T const& b) { if (a < b) a = b; return a; }

// ========================================================================= //

int solve1(int n) {
  static int d[2050][2050];
  int ans = 0;
  for (int sum = 1; sum <= n; ++sum) {
    for (int mx = 1; mx <= sum; ++mx) {
      d[sum][mx] = (d[sum - mx][min(mx, sum - mx)] + d[sum][mx - 1]) % MOD;
      if (mx == sum) { (++d[sum][mx]) %= MOD;
      (ans += d[sum][mx]) %= MOD;
      }
    }
  }
  return ans;
}

int n, k;
int arr[22];

bool check(int len) {
  int sum = 0;
  static int arr2[2050];
  int pos = 0;
  for (int i = len - 1; i >= 0; --i) {
    for (int j = 0; j < arr[i]; ++j) {
      arr2[pos++] = (len - i);
      if (pos > n) return false;
    }
  }
  for (int i = pos - 1; i >= 0; --i)
    sum += arr2[i] * (pos - i);
  return sum <= n;
}

set<vector<int>> ans;

vector<int> step(vector<int> const& x) {
  static vector<int> y;
  y.clear();
  for (int i = 0; i < sz(x);) {
    int j = i + 1;
    while (j < sz(x) && x[j] == x[i]) ++j;
    y.push_back(j - i);
    i = j;
  }
  sort(all(y));
  return y;
}

void go(int len = 0, int csum = 0, int cur = 1) {
  if (len > 0) {
    vector<int> x(arr, arr + len);
    for (int i = 0; i < k - 2; ++i)
      x = step(x);
    ans.insert(x);
  }
  arr[len] = cur;
  if (check(len + 1)) go(len + 1, csum + cur, cur);
  else return;
  go(len, csum, cur + 1);
}

int solve3(int _n, int _k) {
  n = _n;
  k = _k;
  ans.clear();
  go();
  return ans.size();
}

int solve2(int n) {
  int ans = 0;
  static int d[2050][2050];
  for (int i = 1; i <= n; ++i) d[0][i] = 1;
  for (int cnt = 1; cnt <= 63; ++cnt) {
    static int nd[2050][2050];
    memset(nd, 0, sizeof(nd));
    for (int sum = 1; sum <= n; ++sum) {
      bool was = 0;
      for (int mn = sum / cnt; mn >= 1; --mn) {
        nd[sum][mn] = ((was ? nd[sum][mn + 1] : 0) + d[sum - cnt * mn][mn]);
        if (nd[sum][mn] >= MOD) nd[sum][mn] -= MOD;
        was = 1;
      }
      (ans += nd[sum][1]) %= MOD;
    }
    memcpy(d, nd, sizeof(d));
  }
  return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    --k;
    k = min(k, 8);
    if (k == 0) {
      cout << solve1(n) << "\n";
    } else if (k == 1) {
      cout << solve2(n) << "\n";
    } else {
      cout << solve3(n, k) << "\n";
    }

    return 0;
}