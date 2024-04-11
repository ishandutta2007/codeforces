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
  vector<int> tsum;
  vector<pair<int, int>> tmin;
  vector<int> val;

  void relax(int v) {
    tmin[v] = min(tmin[2 * v], tmin[2 * v + 1]);
    tsum[v] = tsum[2 * v] + tsum[2 * v + 1];
  }

  void add_val(int v, int valt) {
    tmin[v].x += valt;
    val[v] += valt;
  }

  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
    val[v] = 0;
  }

  void build_tree(vector<int>& a, int v, int l, int r) {
    if (r - l == 1) {
      tsum[v] = 1;
      tmin[v] = {a[l], l};
      return;
    }
    int m = (l + r) / 2;
    build_tree(a, 2 * v, l, m);
    build_tree(a, 2 * v + 1, m, r);
    relax(v);
  }

  Tree(vector<int>& a) : n(a.size()), tsum(4 * n), tmin(4 * n), val(4 * n) {
    build_tree(a, 1, 0, n);
  } 

  void add_seg(int l, int r, int x, int vt, int lt, int rt) {
    if (lt >= r || l >= rt) {
      return;
    }
    if (l <= lt && rt <= r) {
      add_val(vt, x);
      return;
    }
    int mt = (lt + rt) / 2;
    //per(l, r, vt, lt, rt);
    push(vt);
    add_seg(l, r, x, 2 * vt, lt, mt);
    add_seg(l, r, x, 2 * vt + 1, mt, rt);
    relax(vt);
  }

  void add_seg(int l, int r, int x) {
    add_seg(l, r, x, 1, 0, n);
  }

  void change(int pos, int vt, int lt, int rt) {
    if (rt - lt == 1) {
      tsum[vt] = 0;
      return;
    }
    int mt = (lt + rt) / 2;
    push(vt);
    if (pos < mt) {
      change(pos, 2 * vt, lt, mt);
    } else {
      change(pos, 2 * vt + 1, mt, rt);
    }
    relax(vt);
  }

  void change(int pos) {
    change(pos, 1, 0, n);
  }

  pair<int, int> get_min(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return {INF, -1};
    }
    if (l <= lt && rt <= r) {
      return tmin[vt];
    }

    int mt = (lt + rt) / 2;
    push(vt);
    auto a = get_min(l, r, 2 * vt, lt, mt);
    auto b = get_min(l, r, 2 * vt + 1, mt, rt);
    relax(vt);
    return min(a, b);
  }

  pair<int, int> get_min(int l, int r) {
    return get_min(l, r, 1, 0, n);
  }

  int get_sum(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return 0;
    }
    if (l <= lt && rt <= r) {
      return tsum[vt];
    }
    int mt = (lt + rt) / 2;
    push(vt);
    int x = get_sum(l, r, 2 * vt, lt, mt);
    int y = get_sum(l, r, 2 * vt + 1, mt, rt);
    relax(vt);
    return x + y;
  }

  int get_sum(int l, int r) {
    return get_sum(l, r, 1, 0, n);
  }
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector <int> a(n);
  vector <int> b(m);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> values(n + 1);
  for (int i = 0; i <= n; ++i) {
    values[i] = i;
  }

  Tree tree(values);

  vector <pair<int, int>> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = {a[i], i};
  }
  sort(all(c));
  ll was = 0;

  int now = 0;
  for (auto t : c) {
    while (now < n && c[now].x <= t.x) {
      tree.change(c[now].y);
      //per("CHANGE", t.x, c[now].y);
      now++;
    }
    //per("FIND", t.y, tree.get_sum(0, t.y));
    was += tree.get_sum(0, t.y);
  }

  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(all(b));

  int now1 = 0, now2 = 0;

  int fpos = 0;
  ll res = 0;

  for (int x : b) {
    while (now1 < n && c[now1].x <= x) {
      int pos = c[now1++].y;
      //per(x, "ADD", pos);
      //tree.add_seg(0, pos + 1, 1);
      tree.add_seg(pos + 1, n + 1, -1);
    }

    while (now2 < n && c[now2].x < x) {
      int pos = c[now2++].y;
      //per(x, "ADD", pos);
      tree.add_seg(0, pos + 1, 1);
      //tree.add_seg(pos + 1, n + 1, -1);
    }


    auto t = tree.get_min(fpos, n + 1);
    res += t.x;
    fpos = t.y;
  
    //per(t.x, fpos);
  }

  //pper(res);
 // pper(was);

  cout << res + was << "\n";
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