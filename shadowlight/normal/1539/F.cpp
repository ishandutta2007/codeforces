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
  vector <int> tmin, tmax;
  vector <int> val;

  void relax(int v) {
    tmin[v] = min(tmin[2 * v], tmin[2 * v + 1]);
    tmax[v] = max(tmax[2 * v], tmax[2 * v + 1]);
  }

  void add_val(int v, int valt) {
    val[v] += valt;
    tmin[v] += valt;
    tmax[v] += valt;
  }

  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
    val[v] = 0;
  }

  void build_tree(int v, int l, int r, vector<int>& a) {
    if (r - l == 1) {
      tmin[v] = a[l];
      tmax[v] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build_tree(2 * v, l, m, a);
    build_tree(2 * v + 1, m, r, a);
    relax(v);
  }

  Tree(int n, vector<int> &a) : n(n), tmin(4 * n), tmax(4 * n), val(4 * n) {
    build_tree(1, 0, n, a);
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

  int get_max(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return -INF;
    }
    if (l <= lt && rt <= r) {
      return tmax[vt];
    }
    int mt = (lt + rt) / 2;
    push(vt);
    int a = get_max(l, r, 2 * vt, lt, mt);
    int b = get_max(l, r, 2 * vt + 1, mt, rt);
    relax(vt);
    return max(a, b);
  }

  int get_min(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return INF;
    }
    if (l <= lt && rt <= r) {
      return tmin[vt];
    }
    int mt = (lt + rt) / 2;
    push(vt);
    int a = get_min(l, r, 2 * vt, lt, mt);
    int b = get_min(l, r, 2 * vt + 1, mt, rt);
    relax(vt);
    return min(a, b);
  }

  int get_max(int l, int r) {
    return get_max(l, r, 1, 0, n);
  }

  int get_min(int l, int r) {
    return get_min(l, r, 1, 0, n);
  }

  void add_seg(int l, int r, int x) {
    add_seg(l, r, x, 1, 0, n);
  }
};

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector <int> left_min(n), right_min(n), left_max(n), right_max(n);
  vector <int> deltas;
  vector <pair<int, int>> b;
  for (int i = 0; i < n; ++i) {
    b.pb({a[i], i});
    deltas.pb(n - i);
  }

  Tree tree(n, deltas);
  sort(all(b), [&](pair<int, int> aa, pair<int, int> bb) {
    if (aa.x != bb.x) {
      return aa.x < bb.x;
    }
    return aa.y < bb.y;
  });

  for (int i = 0; i < n; ++i) {
    int was = i;
    int now = i;
    while (now < n && b[now].x == b[was].x) {
      ++now;
    }
    for (int j = was; j < now; ++j) {
      int pos = b[j].y; 
      left_min[pos] = max(0, tree.get_max(0, pos) - tree.get_max(pos, pos + 1));
    }
    for (int j = was; j < now; ++j) {
      int pos = b[j].y; 
      tree.add_seg(0, pos + 1, -2);
    }
    i = now - 1;
  }

  b.clear();
  deltas.clear();

  for (int i = 0; i < n; ++i) {
    b.pb({a[i], i});
    deltas.pb(i);
  }

  tree = Tree(n, deltas);
  sort(all(b), [&](pair<int, int> aa, pair<int, int> bb) {
    if (aa.x != bb.x) {
      return aa.x < bb.x;
    }
    return aa.y < bb.y;
  });

  for (int i = 0; i < n; ++i) {
    int was = i;
    int now = i;
    while (now < n && b[now].x == b[was].x) {
      ++now;
    }
    for (int j = was; j < now; ++j) {
      int pos = b[j].y; 
      right_min[pos] = max(0, tree.get_max(pos + 1, n) - tree.get_max(pos, pos + 1));
    }
    for (int j = was; j < now; ++j) {
      int pos = b[j].y; 
      tree.add_seg(pos, n, -2);
    }
    i = now - 1;
  }

  b.clear();
  deltas.clear();

  for (int i = 0; i < n; ++i) {
    b.pb({a[i], i});
    deltas.pb(n - i);
  }

  tree = Tree(n, deltas);
  sort(all(b), [&](pair<int, int> aa, pair<int, int> bb) {
    if (aa.x != bb.x) {
      return aa.x > bb.x;
    }
    return aa.y < bb.y;
  });

  for (int i = 0; i < n; ++i) {
    int was = i;
    int now = i;
    while (now < n && b[now].x == b[was].x) {
      ++now;
    }
    for (int j = was; j < now; ++j) {
      int pos = b[j].y; 
      left_max[pos] = max(0, tree.get_max(0, pos) - tree.get_max(pos, pos + 1));
    }
    for (int j = was; j < now; ++j) {
      int pos = b[j].y; 
      tree.add_seg(0, pos + 1, -2);
    }
    i = now - 1;
  }

  b.clear();
  deltas.clear();

  for (int i = 0; i < n; ++i) {
    b.pb({a[i], i});
    deltas.pb(i);
  }

  tree = Tree(n, deltas);
  sort(all(b), [&](pair<int, int> aa, pair<int, int> bb) {
    if (aa.x != bb.x) {
      return aa.x > bb.x;
    }
    return aa.y < bb.y;
  });

  for (int i = 0; i < n; ++i) {
    int was = i;
    int now = i;
    while (now < n && b[now].x == b[was].x) {
      ++now;
    }
    for (int j = was; j < now; ++j) {
      int pos = b[j].y; 
      right_max[pos] = max(0, tree.get_max(pos + 1, n) - tree.get_max(pos, pos + 1));
    }
    for (int j = was; j < now; ++j) {
      int pos = b[j].y; 
      tree.add_seg(pos, n, -2);
    }
    i = now - 1;
  }

  vector <int> res(n);
  for (int i = 0; i < n; ++i) {
    int cnt1 = (left_min[i] + right_min[i] + 1);
    //pper(i);
    //cout << left_min[i] << " " << right_min[i] << " " << cnt1 << endl;

    int cnt2 = (left_max[i] + right_max[i]);
    //cout << left_max[i] << " " << right_max[i] << " " << cnt2 << endl;
    res[i] = max(cnt1 / 2, cnt2 / 2);
    cout << res[i] << " ";
  }
  cout << endl;
}