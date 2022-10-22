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

void solve() {
  int n;
  cin >> n;

  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  vector<ll> pref(n, 0), suf(n, 0);

  for (int i = 1; i < n - 1; i++) {
    int a = max(h[i - 1], h[i + 1]);
    int b = h[i];

    if (i > 1) pref[i] = pref[i - 2];
    if (b <= a) {
      pref[i] += a - b + 1;
    }
  }

  for (int i = n - 2; i >= 1; --i) {
    int a = max(h[i - 1], h[i + 1]);
    int b = h[i];

    if (i < n - 2) suf[i] = suf[i + 2];
    if (b <= a) {
      suf[i] += a - b + 1;
    }
  }

  //per(pref, suf);

  ll res = 1e18;

  if (n % 2) {
    res = pref[n - 2];
  } else {
    for (int i = 0; i + 2 < n; ++i) {
      if (i % 2 && i + 3 < n) uin(res, pref[i] + suf[i + 3]);
      uin(res, pref[i] + suf[i + 2]);
    }
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}