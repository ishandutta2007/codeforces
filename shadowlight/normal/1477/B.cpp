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

struct Tree {
  int n;
  vector <int> t;
  vector <int> val;
  vector <int> cnt;

  void relax(int v) {
    t[v] = t[2 * v] + t[2 * v + 1];
  }

  void add_val(int v, int valt) {
    if (valt == -1) return;
    val[v] = valt;
    if (valt == 0) {
      t[v] = 0;
    } else if (valt == 1) {
      t[v] = cnt[v];
    }
  }

  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
    val[v] = -1;
  }

  void build_tree(int v, int l, int r, vector<int>& a) {
    if (r - l == 1) {
      t[v] = a[l];
      cnt[v] = 1;
      return;
    }
    int m = (l + r) / 2;
    build_tree(2 * v, l, m, a);
    build_tree(2 * v + 1, m, r, a);
    relax(v);
    cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
  }

  Tree(int n, vector<int>& a) : n(n), t(4 * n, 0), val(4 * n, -1), cnt(4 * n) {
    build_tree(1, 0, n, a);
  }

  int get(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return 0;
    }
    if (l <= lt && rt <= r) {
      return t[vt];
    }
    //cout << l << " " << r << " " << lt << " " << rt << " " << vt << " " << t[vt] << endl;
    push(vt);
    int mt = (lt + rt) / 2;
    int a = get(l, r, 2 * vt, lt, mt);
    int b = get(l, r, 2 * vt + 1, mt, rt);
    relax(vt);
    return a + b;
  }

  int get(int l, int r) {
    return get(l, r, 1, 0, n);
  }

  void add_seg(int l, int r, int x, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return;
    }
    if (l <= lt && rt <= r) {
      add_val(vt, x);
      return;
    }
    push(vt);
    int mt = (lt + rt) / 2;
    add_seg(l, r, x, 2 * vt, lt, mt);
    add_seg(l, r, x, 2 * vt + 1, mt, rt);
    relax(vt);
  }

  void add_seg(int l, int r, int x) {
    add_seg(l, r, x, 1, 0, n);
  }
};

void solve() {
  int n, q;
  cin >> n >> q;
  vector <int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    b[i] = c - '0';
  }

  vector<pair<int, int>> c;
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    c.pb({l, r});
  }
  reverse(all(c));

  Tree tree(n, b);
  for (auto [l, r] : c) {
    int cnt = tree.get(l, r + 1);
    int len = (r - l + 1);
    //cout << cnt << " " << len << endl;
    if (2 * cnt == len) {
      cout << "NO\n";
      return;
    }
    if (2 * cnt < len) {
      tree.add_seg(l, r + 1, 0);
    } else {
      tree.add_seg(l, r + 1, 1);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (tree.get(i, i + 1) != a[i]) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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