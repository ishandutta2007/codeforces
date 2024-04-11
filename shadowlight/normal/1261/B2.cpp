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
  vector<int> t;
  int n;

  void build_tree(int v, int l, int r) {
    if (r - l == 1) {
      t[v] = 1;
      return;
    }
    int m = (l + r) / 2;
    build_tree(2 * v, l, m);
    build_tree(2 * v + 1, m, r);
    t[v] = t[2 * v] + t[2 * v + 1];
  }

  Tree(int n) : n(n), t(4 * n) {
    build_tree(1, 0, n);
  }

  void change(int pos, int v, int l, int r) {
    if (r - l == 1) {
      t[v] = 0;
      return;
    }
    int m = (l + r) / 2;
    if (pos < m) {
      change(pos, 2 * v, l, m); 
    } else {
      change(pos, 2 * v + 1, m, r);
    }
    t[v] = t[2 * v] + t[2 * v + 1];
  }

  int get(int sum, int v, int l, int r) {
    assert(sum);
    if (r - l == 1) {
      assert(t[v]);
      return l;
    }
    int m = (l + r) / 2;
    if (t[2 * v] >= sum) {
      return get(sum, 2 * v, l, m);
    } else {
      return get(sum - t[2 * v], 2 * v + 1, m, r);
    }
  }
};

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  Tree tree(n);

  map<int, vector<int>> vals;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    vals[a[i]].pb(i);
  }

  int q;
  cin >> q;

  vector<vector<pair<int, int>>> qs(n + 1);

  for (int i = 0; i < q; ++i) {
    int k, pos;
    cin >> k >> pos;
    qs[k].pb({pos, i});
  }

  vector<int> res(q, 0);

  int sz = n;

  for (auto [x, arr] : vals) {
    while (arr.size()) {
      for (auto t : qs[sz]) {
        int pos = tree.get(t.x, 1, 0, n);
        //per(t.y, pos);
        res[t.y] = a[pos];
      }
      tree.change(arr.back(), 1, 0, n);
      //per("pos", arr.back());
      arr.pop_back();
      --sz;
    }
  }
  for (int x : res) {
    cout << x << "\n";
  }

}