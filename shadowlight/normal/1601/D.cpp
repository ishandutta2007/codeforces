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
  vector<int> val;

  void relax(int v) {
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }

  void add_val(int v, int valt) {
    t[v] += valt;
    val[v] += valt;
  }

  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
    val[v] = 0;
  }

  void build_tree(vector<int>& a, int v, int l, int r) {
    if (r - l == 1) {
      t[v] = 0;
      return;
    }
    int m = (l + r) / 2;
    build_tree(a, 2 * v, l, m);
    build_tree(a, 2 * v + 1, m, r);
    relax(v);
  }

  Tree(int n) : n(n), t(4 * n), val(4 * n) {}

  void add_seg(int l, int r, int x, int vt, int lt, int rt) {
    if (lt >= r || l >= rt) {
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

  int get_max(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return -INF;
    }
    if (l <= lt && rt <= r) {
      return t[vt];
    }

    int mt = (lt + rt) / 2;
    push(vt);
    auto a = get_max(l, r, 2 * vt, lt, mt);
    auto b = get_max(l, r, 2 * vt + 1, mt, rt);
    relax(vt);
    return max(a, b);
  }

  int get_max(int l, int r) {
    return get_max(l, r, 1, 0, n);
  }
};

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, d;
  cin >> n >> d;

  vector<pair<int, int>> a;
  vector<pair<int, int>> b;

  int was = 0;
  b.pb({-1, -1});

  for (int i = 0; i < n; ++i) {
    int ss, pp;
    cin >> ss >> pp;

    if (pp <= d) {
      if (ss >= d) ++was;
      continue;
    }
    if (ss < d) continue;

    if (ss >= pp) a.pb({ss, pp});
    b.pb({pp, ss});
  }
  sort(all(a));
  sort(all(b));

  int m = b.size();

  if (!m) {
    cout << was << "\n";
    return 0;
  }

  Tree tree(m);

  int res = 0;
  vector<int> dp(m, 0);
  dp[0] = 0;
  
  multiset<pair<int, int>> qq;


  for (int i = 1; i < m; ++i) {
    int p = b[i].x;
    int s = b[i].y;

    while (qq.size() && qq.begin()->x < p) {
      int sn = qq.begin()->x, pn = qq.begin()->y;
      if (sn >= pn) {
        int pos = lower_bound(all(b), mp(pn, -1)) - b.begin();
        tree.add_seg(0, pos, -1);
      }

      qq.erase(qq.begin());
    }


    int pos = lower_bound(all(b), mp(p + 1, -1)) - b.begin();
    if (s >= p) {
      tree.add_seg(0, min(pos, i), 1);
    }

    int ppos = lower_bound(all(b), mp(s + 1, -1)) - b.begin();
    dp[i] = tree.get_max(0, min(pos, ppos)) + (s < p);

    qq.insert({s, p});
    res = max(res, dp[i]);
    tree.add_seg(i, i + 1, dp[i]);
  }
  cout << res + was << "\n";
}