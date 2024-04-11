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

const int N = 1e6 + 7;

pair<int, int> t[4 * N];
pair<int, int> val[4 * N];
int n, m;

void add_val(int v, pair<int, int> x) {
  val[v] = max(val[v], x);
  t[v] = max(t[v], x);
}

void push(int v) {
  add_val(2 * v, val[v]);
  add_val(2 * v + 1, val[v]);
}

void relax(int v) {
  t[v] = max(t[2 * v], t[2 * v + 1]);
}

void change(int l, int r, pair<int, int> x, int vt = 1, int lt = 0, int rt = N) {
  if (l >= rt || lt >= r) {
    return;
  }
  if (l <= lt && rt <= r) {
    add_val(vt, x);
    return;
  }
  push(vt);
  int mt = (lt + rt) / 2;
  change(l, r, x, 2 * vt, lt, mt);
  change(l, r, x, 2 * vt + 1, mt, rt);
  //t[vt] = max(t[2 * vt], t[2 * vt + 1]);
  relax(vt);
}

pair<int, int> get(int l, int r, int vt = 1, int lt = 0, int rt = N) {
  if (l >= rt || lt >= r) {
    return {0, -1};
  }
  if (l <= lt && rt <= r) {
    return t[vt];
  }
  push(vt);
  int mt = (lt + rt) / 2;
  auto res = get(l, r, 2 * vt, lt, mt);
  res = max(res, get(l, r, 2 * vt + 1, mt, rt));
  relax(vt);
  return res;
}

struct Seg {
  int ind, l, r;
};

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;

  vector <Seg> segs;
  set <int> q;
  for (int i = 0; i < m; ++i) {
    int j, l, r;
    cin >> j >> l >> r;
    segs.pb({j, l, r});
    q.insert(l);
    q.insert(r);
  }
  map <int, int> val;
  int now = 0;
  for (int x : q) {
    val[x] = now++;
  }
  vector<vector<pair<int, int>>> kekw(n);
  for (auto &t : segs) {
    t.l = val[t.l];
    t.r = val[t.r];
    t.ind--;
    kekw[t.ind].pb({t.l, t.r});
  }
  pair<int, int> rres = {0, -1};
  vector <int> pr(n, -1);
  for (int i = 0; i < n; ++i) {
    int res = 1;
    for (auto t : kekw[i]) {
      auto tt = get(t.x, t.y + 1);
      if (tt.x + 1 > res) {
        res = tt.x + 1;
        pr[i] = tt.y;
      }
    }
    //per(pr[i], i, res);
    rres = max(rres, {res, i});
    for (auto t : kekw[i]) {
      change(t.x, t.y + 1, {res, i});
    }
  }
  cout << n - rres.x << "\n";
  vector <bool> have(n, false);
  now = rres.y;
  while (now != -1) {
    have[now] = true;
    now = pr[now];
  }
  for (int i = 0; i < n; ++i) {
    if (have[i]) continue;
    cout << i + 1 << " ";
  }
  cout << "\n";
}