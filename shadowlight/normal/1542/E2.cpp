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

int mod = 1000000007;

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

const int N = 507;

int with_delta[2][N * N];
int cnt[2][N * N];
int prefix[N * N];
int suffix[N *N];
int suffix_sums[N *N];
int C[N][N];
int f[N];

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n >> mod;

  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      C[i][j] = C[i - 1][j];
      add(C[i][j], C[i - 1][j - 1]);
    }
  }

  f[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
  }

  int res = 0;
  cnt[0][0] = 1;
  int uk = 0;

  for (int len = 1; len <= n; ++len) {
    int sum = 0;
    for (int inv = 0; inv < N * N; ++inv) {
      add(sum, cnt[uk][inv]);
      if (inv >= len) {
        dec(sum, cnt[uk][inv - len]);
      }
      cnt[uk ^ 1][inv] = sum;
    }

    suffix[N * N - 1] = 0;
    for (int inv = N * N - 2; inv >= 0; --inv) {
      suffix[inv] = suffix[inv + 1];
      add(suffix[inv], cnt[uk][inv]);
    }

    suffix_sums[N * N - 1] = 0;
    for (int inv = N * N - 2; inv >= 0; --inv) {
      suffix_sums[inv] = suffix_sums[inv + 1];
      add(suffix_sums[inv], suffix[inv]);
    }

    sum = 0;
    for (int delta = 1; delta < len; ++delta) {
      add(sum, mult(len - delta, suffix[delta + 1]));
    }

    int now = 0;
    for (int inv = 0; inv < N * N; ++inv) {
      add(now, mult(cnt[uk][inv], sum));
      if (inv + 2 < N * N) dec(sum, mult(len - 1, suffix[inv + 2]));
      if (inv + 3 < N * N) add(sum, suffix_sums[inv + 3]);
      if (inv + len + 2 < N * N) dec(sum, suffix_sums[inv + len + 2]);
    }

    //cout << f[n - len] << " " << len << " " << now << endl;
    add(res, mult(f[n - len], mult(C[n][len], now)));
    uk ^= 1;
  }
  cout << res << "\n";
}