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

struct Edge {
  int to, w, id;
};

const int N = 1007;
vector <Edge> gr[N];
int n, m, s, t;
int used[N];

vector<int> path;
bool dfs(int v) {
  if (v == t) {
    return true;
  }
  if (used[v]) {
    return false;
  }
  used[v] = true;

  for (auto e : gr[v]) {
    path.pb(e.id);
    if (dfs(e.to)) {
      return true;
    }
    path.pop_back();
  }
  return false;
} 

int ban = -1;

const int M = 3e4 + 7;

int tin[N];
int fup[N];
int cost[M];
bool can[N];

const int INF = 1e9 + 7;
int res = 2 * INF;
int a, b;

void upd(int ind1, int ind2 = -1) {
  int c = cost[ind1];
  if (ind2 != -1) {
    c += cost[ind2];
  }
  //cout << ind1 << " " << ind2 << " " << c << endl;
  if (res > c) {
    res = c;
    a = ind1, b = ind2;
  }
}

int timer = 0;
void dfs1(int v, int pid = -1) {
  can[v] = (v == t);
  fup[v] = tin[v] = timer++;
  used[v] = true;
  for (auto e : gr[v]) {
    if (e.id == ban || e.id == pid) continue;

    if (used[e.to]) {
      fup[v] = min(fup[v], tin[e.to]);
    } else {
      dfs1(e.to, e.id);
      fup[v] = min(fup[v], fup[e.to]);
      if (fup[e.to] > tin[v] && can[e.to]) {
        //cout << ban << " " << e.id << " " << fup[e.to] << " " << tin[v] << endl;
        upd(ban, e.id);
      }
      can[v] |= can[e.to];
    }
  }
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;

  cin >> s >> t;
  --s, --t;

  for (int i = 0; i < m; ++i) {
    int v, u, w;
    cin >> v >> u >> w;
    --v, --u;
    gr[v].pb({u, w, i});
    gr[u].pb({v, w, i});
    cost[i] = w;
  }

  if (!dfs(s)) {
    cout << "0\n";
    cout << "0\n";
    return 0;
  }

  for (int id : path) {
    ban = id;
    fill_n(used, n, false);
    fill_n(can, n, false);
    timer = 0;
    dfs1(s);
    if (!used[t]) {
      upd(ban);
    }
  }

  if (res == 2 * INF) {
    cout << "-1\n";
    return 0;
  }

  cout << res << "\n";
  if (b != -1) {
    cout << "2\n";
    cout << a + 1 << " " << b + 1 << "\n";
  } else {
    cout << "1\n";
    cout << a + 1 << "\n";
  }
}