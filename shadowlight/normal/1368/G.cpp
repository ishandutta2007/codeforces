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

const int N = 2e5 + 7;

vector<int> gr[N];
int rdeg[N];
int lt[N], rt[N];
int val[N];
int rval[N];

const int D = 4;
vector <int> dx = {-1, 0, 1, 0};
vector <int> dy = {0, -1, 0, 1};

string s = "DRUL";
vector <int> order;
int par[N];

void dfs(int v) {
  lt[v] = rt[v] = order.size();
  order.pb(v);
  for (int u : gr[v]) {
    dfs(u);
    rt[v] = rt[u];
  }
}

const int INF = 1e9 + 7;

struct Tree {
  int n;
  vector <pair<int, int>> t;
  vector <int> val;

  void upd(pair<int, int>& a, pair<int, int> b) {
    if (a.x == b.x) {
      a.y += b.y;
    } else if (a.x > b.x) {
      a = b;
    }
  }

  void relax(int v) {
    t[v] = t[2 * v];
    upd(t[v], t[2 * v + 1]);
  }

  void add_val(int v, int valt) {
    t[v].x += valt;
    val[v] += valt;
  }

  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
    val[v] = 0;
  }

  void build_tree(int v, int l, int r) {
    if (r - l == 1) {
      t[v] = {0, 1};
      return;
    }
    int m = (l + r) / 2;
    build_tree(2 * v, l, m);
    build_tree(2 * v + 1, m, r);
    relax(v);
  }

  Tree(int n) : n(n), t(4 * n), val(4 * n, 0) {
    build_tree(1, 0, n);
  }

  void add_seg(int l, int r, int x, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return;
    }
    if (l <= lt && rt <= r) {
      add_val(vt, x);
      return;
    }
    int mt = (lt + rt) / 2;
    push(vt);
    add_seg(l, r, x, 2 * vt, lt, mt);
    add_seg(l, r, x, 2 * vt + 1, mt, rt);
    relax(vt);
  }

  void add_seg(int l, int r, int x) {
    add_seg(l, r, x, 1, 0, n);
  }

  pair<int, int> get(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return {INF, 0};
    }
    if (l <= lt && rt <= r) {
      return t[vt];
    }
    int mt = (lt + rt) / 2;
    push(vt);

    auto res = get(l, r, 2 * vt, lt, mt);
    upd(res, get(l, r, 2 * vt + 1, mt, rt));
    relax(vt);
    return res;
  }

  pair<int, int> get(int l, int r) {
    return get(l, r, 1, 0, n);
  }
} tree(1);

ll res = 0;
int n, m;

ll need[N];

void ddfs(int v) {
  int dom = val[v];
  int u = rval[dom];

  tree.add_seg(lt[u], rt[u] + 1, 1);
  auto t = tree.t[1];

  if (!t.x) {
    res += t.y;
  } else {
    t.y = 0;
  }

 /* if (t.y != need[v]) {
    cout << v << " " << need[v] << " " << t.y << endl;
  }*/

  for (int u : gr[v]) {
    ddfs(u);
  }
  tree.add_seg(lt[u], rt[u] + 1, -1);
}


ll rres = 0;
void simple_count(int v) {
  set <int> q;
  int w = v;
  while (w != -1) {
    q.insert(val[w]);
    w = par[w];
  }
  int xx = v / m, yy = v % m;

  for (int u = 0; u < n * m; ++u) {
    int x = u / m, y = u % m;
    if ((xx + yy) % 2 == (x + y) % 2) continue;

    int w = u;
    bool good = false;
    while (w != -1) {
      if (q.find(val[w]) != q.end()) {
        good = true;
        break;
      }
      w = par[w];
    }
    rres += good;
    need[v] += good;
  }

  for (int u : gr[v]) {
    simple_count(u);
  }
}

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  vector <vector<char>> field(n, vector<char>(m));
  fill_n(par, N, -1);

  int cnt = 0;
  int even = 0, odd = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> field[i][j];
      if ((i + j) % 2) {
        ++odd;
      } else {
        ++even;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == 'U') {
        val[i * m + j] = val[(i + 1) * m + j] = cnt;
        rval[cnt++] = ((i + j) % 2 ? i * m + j : (i + 1) * m + j);
      } else if (field[i][j] == 'L') {
        val[i * m + j] = val[i * m + j + 1] = cnt;
        rval[cnt++] = ((i + j) % 2 ? i * m + j : i * m + j + 1);
      }
    }
  }



  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int t = (i + j) % 2;
      for (int d = 0; d < D; ++d) {
        if (s[d] != field[i][j]) continue;
        int x = i + dx[d] * 2, y = j + dy[d] * 2;
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        gr[x * m + y].pb(i * m + j);
        par[i * m + j] = x * m + y;
        ++rdeg[i * m + j];
        //cout << i << " " << j << " TO " << x << " " << y << endl;
      }
    }
  }

  for (int i = 0; i < n * m; ++i) {
    int x = i / m, y = i % m;
    if ((x + y) % 2 == 0 || rdeg[i]) continue;
    dfs(i);
  }

  tree = Tree(order.size());

  for (int i = 0; i < n * m; ++i) {
    int x = i / m, y = i % m;
    if ((x + y) % 2 || rdeg[i]) continue;
    //simple_count(i);
    ddfs(i);
  }

  cout << odd * (ll) even - res << "\n";
}