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

ll get_res(ll x, ll y, ll z) {
  ll a = x - y;
  ll b = y - z;
  ll c = x - z;
  return a * a + b * b + c * c;
}

const ll INF = 1e18 + 7;

void solve() {
  vector <vector<int>> a(3);
  int x, y, z;
  cin >> x >> y >> z;
  a[0].resize(x);
  a[1].resize(y);
  a[2].resize(z);

  ll res = 3 * INF;

  for (int i = 0; i < 3; ++i) {
    for (int &x : a[i]) {
      cin >> x;
    }
    sort(all(a[i]));
  }

  vector <int> p(3);
  iota(all(p), 0);

  do {
    auto b = a;
    for (int i = 0; i < 3; ++i) {
      b[p[i]] = a[i];
    }

    int idx = 0, idy = 0;
    for (int pos = 0; pos < (int) b[0].size(); ++pos) {
      int val = b[0][pos];
      while (idx < (int) b[1].size() && b[1][idx] < val) {
        ++idx;
      }
      while (idy + 1 < (int) b[2].size() && b[2][idy + 1] <= val) {
        ++idy;
      }
      if (b[2][idy] > val || idx == b[1].size()) continue;
      res = min(res, get_res(val, b[1][idx], b[2][idy]));
    }
  } while (next_permutation(all(p)));
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