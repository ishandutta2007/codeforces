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

const int mod = 998244353;

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

const int N = 3e5 + 7;
int cnt[N], cnt2[N];
int f[N], rf[N];

int rev(int a) {
  return bp(a, mod - 2);
}

void init() {
  cnt[0] = cnt[1] = 1;
  cnt2[0] = 1;
  for (int i = 2; i < N; ++i) {
    add(cnt[i], cnt[i - 1]);
    add(cnt[i], mult(i - 1, cnt[i - 2]));
    if (i % 2 == 0) add(cnt2[i], mult(i - 1, cnt2[i - 2]));
    cnt2[i] = mult(cnt2[i], 2);
  }

  f[0] = rf[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
    rf[i] = rev(f[i]);
  }
}

int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return mult(f[n], mult(rf[k], rf[n - k]));
}

void solve() {
  int n;
  cin >> n;

  int res = 0;
  for (int k = 0; 2 * k <= n; k += 2) {
    //per(cnt2[k], mult(f[k], rf[k / 2]));
    assert(cnt2[k] == mult(f[k], rf[k / 2]));
    add(res, mult(C(n - k, k), mult(cnt2[k], cnt[n - 2 * k])));
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}