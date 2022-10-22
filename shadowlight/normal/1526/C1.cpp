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

const int N = 2e5 + 7;
ll t[4 * N];
ll val[4 * N];

void add_val(int v, ll valt) {
  val[v] += valt;
  t[v] += valt;
}

void relax(int v) {
  t[v] = min(t[2 * v], t[2 * v + 1]);
}

void push(int v) {
  add_val(2 * v, val[v]);
  add_val(2 * v + 1, val[v]);
  val[v] = 0;
}

const ll INF = 1e18;

ll get_pos(int l, int r = N, int vt = 1, int lt = 0, int rt = N) {
  if (l >= rt || lt >= r) {
    return INF;
  }
  if (l <= lt && rt <= r) {
    return t[vt];
  }
  push(vt);
  int mt = (lt + rt) / 2;
  ll a = get_pos(l, r, 2 * vt, lt, mt);
  a = min(a, get_pos(l, r, 2 * vt + 1, mt, rt));
  relax(vt);
  return a;
}

void add_seg(int l, int r, ll x, int vt = 1, int lt = 0, int rt = N) {
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

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;
  vector <int> a(n);
  vector <pair <int, int>> pos;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] >= 0) {
      ++res;
      add_seg(i, N, a[i]);
    } else {
      pos.pb({abs(a[i]), i});
    }
  }
  sort(all(pos), [&](pair<int, int> t, pair<int, int> tt) {
    if (t.x == tt.x) {
      return t.y > tt.y;
    }
    return t.x < tt.x;
  });
  for (int i = 0; i < pos.size(); ++i) {
    int val = pos[i].x, ind = pos[i].y;
    //cout << val << " " << ind << " " << get_pos(ind) << endl;
    if (get_pos(ind) >= val) {
      add_seg(ind, N, -val);
      ++res;
    }
  }
  cout << res << "\n";
}