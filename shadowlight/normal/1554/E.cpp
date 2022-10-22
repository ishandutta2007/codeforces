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

const int mod = 998244353;

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

int inv(int a) {
  return bp(a, mod - 2);
}

vector <vector<int>> gr;
vector <int> dp;
vector <int> res;
vector <int> sz;

const int N = 1e5 + 7;
int f[N];
int rf[N];

void init() {
  f[0] = 1;
  rf[0] = 1;
  for (int i = 1; i < N; ++i) {
    f[i] = mult(f[i - 1], i);
    rf[i] = inv(f[i]);
  }
}

int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  return mult(f[n], mult(rf[k], rf[n - k]));
}

bool dfs(int v, int p, int k) {
  sz[v] = 1;
  dp[v] = 1;
  int sz_earlier = 0, sz_later = 0;
  int cnt_later = 0;
  for (int u : gr[v]) {
    if (u == p) continue;
    bool earlier = dfs(u, v, k);
    dp[v] = mult(dp[v], dp[u]); 
    if (earlier) {
      sz_earlier += sz[u];
    } else {
      sz_later += sz[u];
      ++cnt_later;
    }
  }
  if (cnt_later % k == 0) {
    return false;
  }
  if ((cnt_later + (p != -1)) % k == 0) {
    return true;
  }
  dp[v] = 0;
  return false;
}

void solve() {
  int n;
  cin >> n;
  gr.assign(n, {});
  sz.assign(n, 0);
  res.assign(n + 1, 0);
  res[1] = 1;
  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
    res[1] = mult(res[1], 2);
  }
  for (int k = 2; k < n; ++k) {
    if ((n - 1) % k) continue;
    dp.assign(n, 0);
    dfs(0, -1, k);
    res[k] = dp[0];
  }
  for (int i = n; i >= 1; --i) {
    for (int j = 2 * i; j <= n; j += i) {
      dec(res[i], res[j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << res[i] << " ";
  }
  cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  init();

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}