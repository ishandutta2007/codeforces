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

const int LOGN = 20;

void upd(pair<int, int> &a, int x) {
  if (a.x < x) {
    a.y = a.x;
    a.x = x;
  } else if (a.x != x && a.y < x) {
    a.y = x;
  }
}

const ll INF = 1e18;

void solve() {
  int n, k;
  cin >> n >> k;
  int t = 1;
  int cnt = 0;
  while (t <= n) {
    t *= 2;  
    ++cnt;
  }
  vector <pair<int, int>> masks(1 << cnt, {-1, -1});
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    upd(masks[x], i + 1);
  }

  ll res = -INF;
  vector <pair<int, int>> dp(1 << cnt, {-1, -1});
  for (int mask = 0; mask < (1 << cnt); ++mask) {
    upd(dp[mask], masks[mask].x);
    upd(dp[mask], masks[mask].y);

    for (int i = 0; i < cnt; ++i) {
      if (mask & (1 << i)) {
        upd(dp[mask], dp[mask ^ (1 << i)].x);      
        upd(dp[mask], dp[mask ^ (1 << i)].y);      
      }
    }
    if (dp[mask].y != -1) {
      res = max(res, dp[mask].x * (ll) dp[mask].y - k * (ll) mask);
    }
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}