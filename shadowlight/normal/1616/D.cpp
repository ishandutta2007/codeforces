#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

const int INF = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector <int> a(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int x;
  cin >> x;

  vector <vector<int>> dp(n + 1, vector<int>(4, -INF));

  vector <bool> can(n, false);
  for (int i = 0; i < n; ++i) {
    can[i] = true;
    if (a[i] >= x) {
      continue;
    }
    if (i > 0 && a[i - 1] >= x && a[i] + a[i - 1] < 2 * x) {
      can[i] = false;
    }
    if (i + 1 < n && a[i + 1] >= x && a[i] + a[i + 1] < 2 * x) {
      can[i] = false;
    }
  }

  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < 4; ++mask) {
      if (dp[i][mask] == -INF) continue;
      int nmask = (mask & 1) * 2;
      uax(dp[i + 1][nmask], dp[i][mask]);
      if (!nmask) {
        uax(dp[i + 1][nmask + 1], dp[i][mask] + 1);
      }
      if (a[i - 1] + a[i] < 2 * x) continue;
      if (!(mask & 2) || (a[i] + a[i - 1] + a[i - 2]) >= 3 * x) {
        uax(dp[i + 1][nmask + 1], dp[i][mask] + 1);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < 4; ++i) {
    uax(res, dp[n][i]);
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}