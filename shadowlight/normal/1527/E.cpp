#include <bits/stdc++.h>
#define ll int
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
  vector <ll> t;
  vector <ll> val;

  Tree(int n) : n(n), t(4 * n), val(4 * n) {}
  Tree() {}

  void add_val(int v, ll valt) {
    val[v] += valt;
    t[v] += valt;
  }

  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
    val[v] = 0;
  }

  void relax(int v) {
    t[v] = min(t[2 * v], t[2 * v + 1]);
  }

  void add_seg(int l, int r, ll x, int vt, int lt, int rt) {
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

  ll get(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return INF;
    }
    if (l <= lt && rt <= r) {
      return t[vt];
    }
    push(vt);
    int mt = (lt + rt) / 2;
    ll res = get(l, r, 2 * vt, lt, mt);
    res = min(res, get(l, r, 2 * vt + 1, mt, rt));
    relax(vt);
    return res;
  }

  void add_seg(int l, int r, ll x) {
    add_seg(l, r, x, 1, 0, n);
  }

  ll get(int l, int r) {
    return get(l, r, 1, 0, n);
  }
};


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<Tree> tree(k + 1);
  for (int i = 0; i <= k; ++i) {
    tree[i] = Tree(n + 1);
  }

  vector<int> pr(n + 1, -1);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    int add = (pr[x] == -1 ? 0 : i - pr[x]);

    for (int j = 1; j <= k; ++j) {
      ll now = tree[j - 1].get(0, pr[x]) + add;
      now = min(now, tree[j - 1].get(pr[x], i));
      tree[j].add_seg(i, i + 1, now);
      //cout << i << " " << j << " " << now << endl;
    }
    tree[0].add_seg(i, i + 1, INF);
    for (int j = 0; j < k; ++j) {
      if (pr[x] != -1) {
        //cout << j << " " << 0 << " " << pr[x] << " " << add << endl;
        tree[j].add_seg(0, pr[x], add);
      }
    }
    pr[x] = i;
  }
  cout << tree[k].get(n, n + 1) << "\n";
}