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

const int N = 1e5 + 7;
ll tmin[2 * N], tmax[2 * N];
int n;

void change(int v, ll x) {
  v += n;
  tmin[v] = x;
  tmax[v] = x;
  while (v) {
    v /= 2;
    tmin[v] = min(tmin[2 * v], tmin[2 * v + 1]);
    tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
  }
}

const ll INF = 1e18 + 7;

pair<ll, ll> get(int l, int r) {
  ll nmin = INF;
  ll nmax = -INF;
  for (l += n, r += n; l <= r; l /= 2, r /= 2) {
    if (l % 2) {
      uin(nmin, tmin[l]);
      uax(nmax, tmax[l]);
      ++l;
    }
    if (r % 2 == 0) {
      uin(nmin, tmin[r]);
      uax(nmax, tmax[r]);
      --r;
    }
  }
  return {nmin, nmax};
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int q;
  cin >> n >> q;

  vector <ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    a[i] = x - a[i];
  }

  vector <ll> pref(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + a[i];
  }
  //per(pref);

  for (int i = 0; i <= n; ++i) {
    change(i, pref[i]);
  }

  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    if (pref[r] != pref[l - 1]) {
      cout << "-1\n";
      continue;
    }

    auto t = get(l, r);
    t.x -= pref[l - 1];
    t.y -= pref[l - 1];

    cout << max(-t.x, t.y) << "\n";
  }

}