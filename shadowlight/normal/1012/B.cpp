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

int sz = 0;

struct DSU {
  int n;
  vector<int> p, r;

  DSU(int n) : p(n, -1), r(n, 0) {};

  int get(int v) {
    if (p[v] == -1) return -1;
    if (p[v] == v) return v;
    return p[v] = get(p[v]);
  }

  void uni(int v, int u) {
    if (get(v) == -1) {
      p[v] = v;
      ++sz;
    }
    if (get(u) == -1) {
      p[u] = u;
      ++sz;
    }
    v = get(v);
    u = get(u);
    if (v == u) return;
    if (r[v] == r[u]) ++r[u];
    if (r[v] > r[u]) swap(v, u);
    p[v] = u;

    --sz;
  }
};

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m, q;
  cin >> n >> m >> q;

  DSU dsu(m);

  vector<vector<int>> a(n);

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    a[x].pb(y);
  }

  sz = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < (int) a[i].size(); ++j) {
      dsu.uni(a[i][j - 1], a[i][j]);
    }
    if (a[i].size() == 1) {
      int v = a[i][0];
      if (dsu.get(v) == -1) {
        dsu.p[v] = v;
        ++sz;
      }
    } else if (!a[i].size()) {
      ++sz;
    }
  }

  for (int i = 0; i < m; ++i) {
    if (dsu.get(i) == -1) {
      ++sz;
    }
  }
  cout << sz << "\n";
}