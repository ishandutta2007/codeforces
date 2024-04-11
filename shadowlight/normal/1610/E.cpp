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

const int INF = 1e9 + 7;

struct Tree {
  int n;
  vector<int> t;

  Tree(int n) : n(n), t(4 * n, INF) {}

  void relax(int v) {
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }

  void change(int pos, int x, int v, int l, int r) {
    if (r - l == 1) {
      t[v] = x;
      return;
    }
    int m = (l + r) / 2;
    if (pos <= m) {
      change(pos, x, 2 * v, l, m);
    } else {
      change(pos, x, 2 * v + 1, m, r);
    }
    relax(v);
  } 

  int find_nearest(int x, int v, int l, int r) {
    if (r - l == 1) {
      return (t[v] < x ? l : -1);
    }
    int m = (l + r) / 2;
    if (t[2 * v + 1] < x) {
      return find_nearest(x, 2 * v + 1, m, r);
    }
    return find_nearest(x, 2 * v, l, m);
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a;
  map <int, int> cnt;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (a.size() && a.back() == x) {
      ++cnt[x];
    } else {
      a.pb(x);
      cnt[x] = 1;
    }
  }

  int res = n;
  uin(res, n - cnt[a.back()]);
  for (int i = 0; i + 1 < (int) a.size(); ++i) {
    int mn = a[i];

    int save = cnt[mn] + 1;
    int z = a.back();

    while (true) {
      int y = (z + mn) / 2;
      int pos = (int) (upper_bound(all(a), y) - a.begin()) - 1;
      //per(mx, z, y);
      if (pos <= i) break;
      z = a[pos];
      ++save;
    }
    //per(mx, save);
    uin(res, n - save);
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

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}