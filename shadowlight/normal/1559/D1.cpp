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

struct DSU {
  int n;
  vector <int> p, r;
  DSU(int n) : p(n), r(n) {
    iota(all(p), 0);
  }

  int get(int v) {
    return (p[v] == v ? v : p[v] = get(p[v]));
  }

  void uni(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u) return;

    if (r[v] == r[u]) ++r[u];
    if (r[v] > r[u]) swap(v, u);
    p[v] = u;
  }

  bool conn(int v, int u) {
    return get(v) == get(u);
  }
};

int main(){
#ifdef LOCAL
 freopen("D_input.txt", "r", stdin);
 //freopen("D_output.txt", "w", stdout);
#endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 int n, m1, m2;
 cin >> n >> m1 >> m2;

 DSU dsu1(n), dsu2(n);

 for (int i = 0; i < m1; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    dsu1.uni(v, u);
 }

 for (int i = 0; i < m2; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    dsu2.uni(v, u);
 }

 vector <pair<int, int>> res;

 for (int i = 0; i < n; ++i) {
  for (int j = i + 1; j < n; ++j) {
    if (!dsu1.conn(i, j) && !dsu2.conn(i, j)) {
      res.pb({i, j});
      dsu1.uni(i, j);
      dsu2.uni(i, j);
    }
  }
 }

 cout << res.size() << "\n";
 for (auto t : res) {
  cout << t.x + 1 << " " << t.y + 1 << "\n";
 }

}