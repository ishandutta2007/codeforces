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
  vector<int> t;
  vector<int> val;

  Tree(int n) : n(n), t(4 * n, 0), val(4 * n, 0) {}

  void add_val(int v, int x) {
    val[v] += x;
    t[v] += x;
  }

  void push(int v) {
    add_val(2 * v, val[v]);
    add_val(2 * v + 1, val[v]);
    val[v] = 0;
  }

  void add_seg(int l, int r, int vt, int lt, int rt) {
    if (l >= rt || lt >= r) {
      return;
    }
    if (l <= lt && rt <= r) {
      add_val(vt, 1);
      return;
    }

    push(vt);
    int mt = (lt + rt) / 2;
    add_seg(l, r, 2 * vt, lt, mt);
    add_seg(l, r, 2 * vt + 1, mt, rt);
  }

  int get(int pos, int vt, int lt, int rt) {
    if (rt - lt == 1) {
      return t[vt];
    }
    push(vt);
    int mt = (lt + rt) / 2;
    if (pos < mt) {
      return get(pos, 2 * vt, lt, mt);
    } else {
      return get(pos, 2 * vt + 1, mt, rt);
    }
  }
};

const ll INF = 1e18 + 7;

void solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  Tree tree(n);

  vector <vector<int>> pos(26);
  for (int i = n - 1; i >= 0; --i) {
    pos[s[i] - 'a'].pb(i);
  }

  ll res = INF;
  ll now = 0;

  for (int i = 0; i < n; ++i) {
    int k = t[i] - 'a';
    for (int j = 0; j < k; ++j) {
      if (!pos[j].size()) continue;
      int pp = pos[j].back() + tree.get(pos[j].back(), 1, 0, n);
      uin(res, now + (pp - i));
    }
    if (!pos[k].size()) break;

    int pp = pos[k].back() + tree.get(pos[k].back(), 1, 0, n);
    tree.add_seg(0, pos[k].back(), 1, 0, n);
    now += (pp - i);
    pos[k].pop_back();
  }
  cout << (res == INF ? -1 : res) << "\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    solve();
  }

}