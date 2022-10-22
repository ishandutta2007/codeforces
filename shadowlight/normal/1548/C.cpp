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

int inv(int a) {
  return bp(a, mod - 2);
}

const int N = 3e6 + 7;
int f[N], rf[N];

void init() {
  f[0] = rf[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
    rf[i] = inv(f[i]);
  }
}

int dp[N][3];

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mult(f[n], mult(rf[k], rf[n - k]));
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int n, q;
  cin >> n >> q;
  dp[0][0] = dp[0][1] = dp[0][2] = n;

  for (int x = 1; x < 3 * n; ++x) {
    int val = C(3 * n, x + 1);
    dec(val, mult(dp[x - 1][0], 2));
    dec(val, mult(dp[x - 1][1], 1));
    val = mult(val, inv(3));

    dp[x][0] = val;
    dp[x][1] = dp[x][0] + dp[x - 1][0];
    dp[x][2] = dp[x][1] + dp[x - 1][1];
  }

  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;

    int res = dp[x][0];
    add(res, C(3 * n, x));
    cout << res << "\n";
  }
}