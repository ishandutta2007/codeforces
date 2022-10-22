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
  vector<int> t;
  vector<int> tsum;
  vector<int> valt;
  vector<int> vals;

  int n;

  void relax(int v) {
    tsum[v] = min(tsum[2 * v], tsum[2 * v + 1]);
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }

  void add_valt(int v, int x) {
    t[v] += x;
    valt[v] += x;
  }

  void add_vals(int v, int x) {
    tsum[v] += x;
    vals[v] += x;
  }

  void push(int v) {
    add_valt(2 * v, valt[v]);
    add_valt(2 * v + 1, valt[v]);
  
    add_vals(2 * v, vals[v]);
    add_vals(2 * v + 1, vals[v]);
    
    valt[v] = vals[v] = 0;
  }

  void build_tree(vector<int>& a, vector<int>& pa, vector<int>& b, int v, int l, int r) {
    if (r - l == 1) {
      t[v] = a[l];
      tsum[v] = pa[l] + b[l];
      return;
    }
    int mt = (l + r) / 2;
    build_tree(a, pa, b, 2 * v, l, mt);
    build_tree(a, pa, b, 2 * v + 1, mt, r);
    relax(v);
  }

  Tree(int n, vector<int>&a, vector<int>& pa, vector<int>& b) : n(n), t(4 * n), tsum(4 * n), valt(4 * n, 0), vals(4 * n, 0) {
    build_tree(a, pa, b, 1, 0, n);
  }

  int get_next(int pos, int x, int vt, int lt, int rt) {
    if (pos >= rt) {
      return INF;
    }
    if (rt - lt == 1) {
      return (t[vt] <= x ? lt : INF);
    }
    push(vt);
    int mt = (lt + rt) / 2;
    
    if (pos > lt) {
      int res = min(get_next(pos, x, 2 * vt, lt, mt), get_next(pos, x, 2 * vt + 1, mt, rt));
      relax(vt);
      return res;
    }

    int res;
    if (t[2 * vt] <= x) {
      res = get_next(pos, x, 2 * vt, lt, mt);
    } else {
      res = get_next(pos, x, 2 * vt + 1, mt, rt);
    }
    relax(vt);

    return res;
  }

  int get_next(int pos, int x) {
    //print1();
    int res = get_next(pos, x, 1, 0, n);
    //per("FIND", pos, x, res);
    return res;
  }

  void add_seg(int l, int r, int x, int y, int vt, int lt, int rt) {
    if (lt >= r || l >= rt) {
      return;
    }
    if (l <= lt && rt <= r) {
      add_valt(vt, x);
      add_vals(vt, y);
      return;
    }
    int mt = (lt + rt) / 2;
    push(vt);

    add_seg(l, r, x, y, 2 * vt, lt, mt);
    add_seg(l, r, x, y, 2 * vt + 1, mt, rt);
    relax(vt);
  }

  int get_min(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return INF;
    }
    if (l <= lt && rt <= r) {
      return t[vt];
    }
    int mt = (lt + rt) / 2;
    push(vt);

    int res = min(get_min(l, r, 2 * vt, lt, mt), get_min(l, r, 2 * vt + 1, mt, rt));
    relax(vt);
    return res;
  }

  int get_min(int l, int r) {
    return get_min(l, r, 1, 0, n);
  }

  void print(int vt, int lt, int rt) {
    if (rt - lt == 1) {
      cout << tsum[vt] << " ";
      return;
    }
    push(vt);
    int mt = (lt + rt) / 2;
    print(2 * vt, lt, mt);
    print(2 * vt + 1, mt, rt);
    relax(vt);
  }

  void print() {
    print(1, 0, n);
    cout << "\n";
  }

  void print1(int vt, int lt, int rt) {
    if (rt - lt == 1) {
      cout << t[vt] << " ";
      return;
    }
    push(vt);
    int mt = (lt + rt) / 2;
    print1(2 * vt, lt, mt);
    print1(2 * vt + 1, mt, rt);
    relax(vt);
  }

  void print1() {
    print1(1, 0, n);
    cout << "\n";
  }

  void add_seg(int l, int r, int x, int y) {
    add_seg(l, r, x, y, 1, 0, n);
  }
};

void print_correct(string& s) {
  int n = s.size();

  vector<int> a(n + 1, 0), pa(n + 1, 0), b(n + 1, 0);

  int totalb = 0;

  for (int i = 0; i < n; ++i) {
    int k = s[i] - 'a';
    
    a[i + 1] = a[i];
    if (k == 1) {
      --a[i + 1];
      ++totalb;
    } else if (!k) {
      ++a[i + 1];
    }
    pa[i + 1] = min(pa[i], a[i + 1]);
  }


  for (int i = n - 1; i >= 0; --i) {
    b[i] = b[i + 1];

    int k = s[i] - 'a';
    if (k == 1) {
      --b[i];
    } else if (k == 2) {
      ++b[i];
    }
  }

  cout << "CORRECT\n";

  for (int i = 0; i <= n; ++i) {
    cout << pa[i] + b[i] << " ";
  }
  cout << "\n";

  for (int i = 0; i <= n; ++i) {
    cout << a[i] << " ";
  }
  cout << "\n";
  cout << "============\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;

  vector<int> a(n + 1, 0), pa(n + 1, 0), b(n + 1, 0);

  int totalb = 0;

  for (int i = 0; i < n; ++i) {
    int k = s[i] - 'a';
    
    a[i + 1] = a[i];
    if (k == 1) {
      --a[i + 1];
      ++totalb;
    } else if (!k) {
      ++a[i + 1];
    }
    pa[i + 1] = min(pa[i], a[i + 1]);
  }


  for (int i = n - 1; i >= 0; --i) {
    b[i] = b[i + 1];

    int k = s[i] - 'a';
    if (k == 1) {
      --b[i];
    } else if (k == 2) {
      ++b[i];
    }
  }

  Tree tree(n + 1, a, pa, b);

  //tree.print();
  for (int i = 0; i < q; ++i) {
    int pos;
    char c;
    cin >> pos >> c;
    --pos;

    if (s[pos] == 'b') {
      --totalb;
    }
    //tree.print1();

    if (s[pos] != 'c') {
      int delta = (s[pos] == 'a' ? -1 : 1);
      int x = tree.get_min(0, pos + 1);
      
      int nxt;
      if (delta == 1) {
        nxt = tree.get_next(pos + 1, x - 1);
      } else {
        nxt = tree.get_next(pos + 1, x);
      }
      //per("FIND", pos + 1, x - (delta == 1), nxt);

      tree.add_seg(nxt, n + 1, 0, delta);
      tree.add_seg(pos + 1, n + 1, delta, 0);
    }

    if (s[pos] != 'a') {
      int delta = (s[pos] == 'c' ? -1 : 1);
      tree.add_seg(0, pos + 1, 0, delta);
    }

    //tree.print1();

    s[pos] = c;

    if (s[pos] == 'b') {
      ++totalb;
    }

     if (s[pos] != 'c') {
      int delta = (s[pos] == 'a' ? -1 : 1) * -1;
      int x = tree.get_min(0, pos + 1);

      int nxt;
      if (delta == 1) {
        nxt = tree.get_next(pos + 1, x - 1);
      } else {
        nxt = tree.get_next(pos + 1, x);
      }
      tree.add_seg(nxt, n + 1, 0, delta);
      tree.add_seg(pos + 1, n + 1, delta, 0);
    }

    if (s[pos] != 'a') {
      int delta = (s[pos] == 'c' ? -1 : 1) * -1;
      tree.add_seg(0, pos + 1, 0, delta);
    }

    /*per(s);
    per("QUERY", pos, c);
    print_correct(s);
    tree.print();
    tree.print1();*/
    cout << tree.tsum[1] + totalb << "\n";
  }

}