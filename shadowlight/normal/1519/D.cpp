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

const ll INF = 1e18;

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;
  vector<ll> a(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i + 1];
  }
  vector<ll> b(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> b[i + 1];
  }

  vector<ll> pref(n + 2, 0), suf(n + 2, 0);
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i] * b[i];
  }
  for (int i = n; i >= 1; --i) {
    suf[i] = suf[i + 1] + a[i] * b[i];
  }

  ll res = pref[n];
  for (int c = 1; c <= n; ++c) {
    ll sum1 = 0, sum2 = a[c] * b[c]; 
    for (int len = 1; len <= n; ++len) {
      if (1 <= c - len + 1 && c + len <= n) {
        sum1 += a[c - len + 1] * b[c + len];
        sum1 += a[c + len] * b[c - len + 1];
        res = max(res, sum1 + pref[c - len] + suf[c + len + 1]);
      }

      if (1 <= c - len && c + len <= n) {
        sum2 += a[c - len] * b[c + len];
        sum2 += a[c + len] * b[c - len];
        res = max(res, sum2 + pref[c - len - 1] + suf[c + len + 1]);
      }
    }
  }

  cout << res << "\n";
}