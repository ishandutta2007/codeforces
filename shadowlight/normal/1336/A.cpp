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
vector<int> gr[N];
int cnt[N];
int par[N];
ll sum[N];
int sz[N];
int he[N];

int n, k;

void dfs(int v, int p, int h = 0) {
  par[v] = p;
  sz[v] = 1;
  he[v] = h;
  for (int u : gr[v]) {
    if (u == p) continue;
    dfs(u, v, h + 1);
    ++cnt[v];
    sum[v] += sz[u];
    sz[v] += sz[u];
  }
}

ll res = 0;
bool ass[N];

void res_dfs(int v, int p, int cnt = 0) {
  if (ass[v]) res += cnt;
  for (int u : gr[v]) {
    if (u == p) continue;
    res_dfs(u, v, cnt + !ass[v]);
  }
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> k;

  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
  }

  dfs(0, -1);
  set <pair<ll, int>> q;
  for (int i = 0; i < n; ++i) {
    sum[i] -= he[i];
    if (!cnt[i]) {
      q.insert({sum[i], i});
    }
  }

  for (int i = 0; i < k; ++i) {
    int v = q.begin()->y;
    q.erase({sum[v], v});
    ass[v] = true;
    if (par[v] == -1) continue;
    --cnt[par[v]];
    if (!cnt[par[v]]) {
      q.insert({sum[par[v]], par[v]});
    }
  }
/*
  for (int i = 0; i < n; ++i) {
    cout << ass[i] << " ";
  }
  cout << endl;*/

  res_dfs(0, -1);
  cout << res << "\n";
}