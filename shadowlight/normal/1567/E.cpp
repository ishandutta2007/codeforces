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

struct Data {
  int val_l, val_r;
  ll cnt_l, cnt_r;
  ll cnt;
  int len;
};

Data unite(Data a, Data b) {
  Data c;
  c.val_l = a.val_l;
  c.val_r = b.val_r;
  c.cnt_l = a.cnt_l;
  c.cnt_r = b.cnt_r;
  c.len = a.len + b.len;
  c.cnt = a.cnt + b.cnt;

  if (a.val_r <= b.val_l) {
    c.cnt += a.cnt_r * b.cnt_l;
    if (a.cnt_l == a.len) {
      c.cnt_l += b.cnt_l;
    }
    if (b.cnt_r == b.len) {
      c.cnt_r += a.cnt_r;
    }
  } 

  return c;
}

struct Tree {
  int n;
  vector<Data> t;

  void build_tree(int v, int l, int r, vector<int>& a) {
    if (r - l == 1) {
      t[v] = {a[l], a[l], 1, 1, 1, 1};
      return;
    }
    int m = (l + r) / 2;
    build_tree(2 * v, l, m, a);
    build_tree(2 * v + 1, m, r, a);
    t[v] = unite(t[2 * v], t[2 * v + 1]);
  }

  Tree(vector<int>& a) : n(a.size()), t(4 * n) {
    build_tree(1, 0, n, a);
  }

  Data get(int l, int r, int vt, int lt, int rt) {
    if (l <= lt && rt <= r) {
      return t[vt];
    }
    int mt = (lt + rt) / 2;
    if (r <= mt) {
      return get(l, r, 2 * vt, lt, mt);
    }
    if (l >= mt) {
      return get(l, r, 2 * vt + 1, mt, rt);
    }
    auto t1 = get(l, r, 2 * vt, lt, mt);
    auto t2 = get(l, r, 2 * vt + 1, mt, rt);
    return unite(t1, t2);
  }

  ll get(int l, int r) {
    return get(l, r, 1, 0, n).cnt;
  }

  void change(int pos, int x, int vt, int lt, int rt) {
    if (rt - lt == 1) {
      t[vt].val_l = t[vt].val_r = x;
      return;
    }
    int mt = (lt + rt) / 2;
    if (pos < mt) {
      change(pos, x, 2 * vt, lt, mt);
    } else {
      change(pos, x, 2 * vt + 1, mt, rt);
    }
    t[vt] = unite(t[2 * vt], t[2 * vt + 1]);
  }

  void change(int pos, int x) {
    change(pos, x, 1, 0, n);
  }
};

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  Tree tree(a);

  for (int i = 0; i < q; ++i) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int x, y;
      cin >> x >> y;
      --x;
      tree.change(x, y);
    } else {
      int l, r;
      cin >> l >> r;
      --l;
      cout << tree.get(l, r) << "\n";
    }
  }

}