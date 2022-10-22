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
  int n, p;
  cin >> n >> p;
  map <int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++cnt[x];
  }
  if (p == 1) {
    cout << n % 2 << "\n";
    return;
  }
  vector <pair<int, int>> a;
  for (auto t : cnt) {
    a.pb(t);
  }
  reverse(all(a));
  ll have = 0;
  int pr = -1;
  int res = 0;
  bool bad = false;

  for (int i = 0; i < (int) a.size(); ++i) {
    //cout << i << " " << a[i].x << " " << a[i].y << " " << have << endl;
    if (have) {
      while (pr != a[i].x && have <= n) {
        have *= p;
        --pr;
      }
      if (have > n) {
        res = mult(have % mod, bp(p, pr));
        for (int j = i; j < (int) a.size(); ++j) {
          dec(res, mult(a[j].y, bp(p, a[j].x)));
        }
        bad = true;
        break;
      }
    }
    ll t = min(have, (ll) a[i].y);
    have -= t;
    a[i].y -= t;
    if (a[i].y) {
      have = a[i].y % 2;
    }
    pr = a[i].x;
  }
  if (!bad) res = mult(have % mod, bp(p, pr));
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