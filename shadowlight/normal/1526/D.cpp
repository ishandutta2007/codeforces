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

string tet = "NOTA";
vector <int> pos[4];

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

ll get_pos(int pos, int vt, int lt, int rt) {
  if (rt - lt == 1) {
    return t[vt];
  }
  push(vt);
  int mt = (lt + rt) / 2;
  ll res;
  if (pos < mt) {
    res = get_pos(pos, 2 * vt, lt, mt);
  } else {
    res = get_pos(pos, 2 * vt + 1, mt, rt);
  }
  relax(vt);
  return res;
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

int n;
void clear() {
  for (int i = 0; i < 4 * n; ++i) {
    t[i] = 0;
    val[i] = 0;
  }
}


ll count(string tt) {
  clear();
  vector<int> now(4, 0);
  ll res = 0;
  int bb = 0;
  for (char c : tt) {
    for (int i = 0; i < 4; ++i) {
      if (tet[i] != c) continue;
      //cout << bb << " " << pos[i][now[i]] << " " << get_pos(pos[i][now[i]]) << endl;
      res += abs(bb - (pos[i][now[i]] + get_pos(pos[i][now[i]], 1, 0, n)));
      add_seg(0, pos[i][now[i]], 1, 1, 0, n);
      now[i]++;
    }
    bb++;
  }
  return res;
}
void solve() {
  for (int i = 0; i < 4; ++i) {
    pos[i].clear();
  }

  string s;
  cin >> s;
  n = s.size();
  int now = 0;
  for (char c : s) {
    for (int i = 0; i < 4; ++i) {
      if (tet[i] == c) {
        pos[i].pb(now++);      
      }
    }
  }
  vector<int> p(4);
  iota(all(p), 0);
  string rest = s;
  ll res = 0;

  do {
    string tt = "";
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < (int) pos[p[i]].size(); ++j) {
        tt += tet[p[i]];
      }
    }
    //pper(tt);
    ll cnt = count(tt);
    if (cnt > res) {
      res = cnt;
      rest = tt;
    }
  } while(next_permutation(all(p)));
  cout << rest << "\n";
  pper(res);
  //cout << count("TNNTAOOA") << endl;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}