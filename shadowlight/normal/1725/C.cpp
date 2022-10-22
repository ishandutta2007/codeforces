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
int f[N], rf[N];

int rev(int a) {
  return bp(a, mod - 2);
}

void init() {
  f[0] = rf[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
    rf[i] = rev(f[i]);
  }
}

int C(int n, int x) {
  if (x < 0 || x > n) return 0;
  return mult(f[n], mult(rf[n - x], rf[x]));
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int n, m;
  cin >> n >> m;

  ll total = 0;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    total += a[i];
  }
  ll need = total / 2;
  int k = 0;

  if (total % 2 == 0) {
    int now = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      while (now + 1 < n && sum < need) sum += a[now++];
      if (sum == need) {
        ++k;
      }
      sum -= a[i];
    }
  }

  int res = 0;
  for (int x = 0; x <= min(m, k); ++x) {
    int mlt = 1;
    mlt = mult(mlt, C(m, x));
    mlt = mult(mlt, C(k, x));
    mlt = mult(mlt, bp(mult(m - x, m - x - 1), k - x));
    mlt = mult(mlt, bp(m - x, n - 2 * k));
    mlt = mult(mlt, f[x]);
    //per(x, mlt);
    add(res, mlt);
  }
  cout << res << "\n";
}