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
  int n, a, b;
  cin >> n >> a >> b;
  --a, --b;
  vector<int> p(n);
  p[0] = a;
  int now = 1;
  for (int i = n - 1; i > b; --i) {
    if (i == a) continue;
    p[now++] = i;
  }
  p.back() = b;
  now = p.size() - 2;
  for (int i = 0; i < a; ++i) {
    if (i == b) continue;
    p[now--] = i;
  }

  for (int i = a + 1; i < b; ++i) {
    p[now--] = i;
  }
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    if (cnt[p[i]]++) {
      cout << "-1\n";
      return;
    }
  }
  int mn = n;
  for (int i = 0; i < n / 2; ++i) {
    uin(mn, p[i]);
  }
  if (mn != a) {
    cout << "-1\n";
    return;
  }

  int mx = 0;
  for (int i = n / 2; i < n; ++i) {
    uax(mx, p[i]);
  }
  if (mx != b) {
    cout << "-1\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    cout << p[i] + 1 << " ";
  }
  cout << "\n";
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