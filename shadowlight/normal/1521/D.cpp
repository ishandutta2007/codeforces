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

const int N = 1e5 + 7;

int n;
vector <int> gr[N];
vector <int> ngr[N];
int dp[N][2];
pair<int, int> sons[N];
bool used[N];

void dfs(int v, int p) {
  dp[v][0] = 0;
  dp[v][1] = 0;
  sons[v] = {-1, -1};

  int sum = 0;
  vector <pair<int, int>> vals;
  for (int u : gr[v]) {
    if (u == p) continue;
    dfs(u, v);
    sum += dp[u][1];
    vals.pb({dp[u][0] - dp[u][1], u});
  }
  sort(all(vals), greater<pair<int, int>>());
  if (vals.size() >= 1) {
    dp[v][0] = sum + vals[0].x + 1;
    sons[v].x = vals[0].y;
  }
  if (vals.size() >= 2) {
    dp[v][1] = sum + vals[0].x + vals[1].x + 2;
    sons[v].y = vals[1].y;
  }
  if (dp[v][1] < dp[v][0]) {
    sons[v].y = -1;
    dp[v][1] = dp[v][0];
  }
}

vector<int> cnt;

vector<pair<int, int>> delt;
vector<pair<int, int>> addt;

void ans_dfs(int v, int p, int val) {
  int x = sons[v].x, y = sons[v].y;
  if (!val) {
    y = -1;
  }
  for (int u : gr[v]) {
    if (u == p) continue;   
    if (u == x || u == y) {
      ++cnt[v];
      ++cnt[u];
      ngr[v].pb(u);
      ngr[u].pb(v);
      //per("EDGE", v, u);

      ans_dfs(u, v, 0);
    } else {
      delt.pb({v, u});
      ans_dfs(u, v, 1);
    }
  }
}

int rdfs(int v, int p) {
  used[v] = true;
  //per(v, cnt[v], p);
  if (p != -1 && cnt[v] == 1) {
    return v;
  }
  if (!cnt[v]) {
    return v;
  }
  for (int u : ngr[v]) {
    if (u == p) continue;
    return rdfs(u, v);
  }
  assert(false);
}

void solve() {
  cin >> n;
  cnt.assign(n, 0);
  addt.clear();
  delt.clear();

  for (int i = 0; i < n; ++i) {
    gr[i].clear();
    ngr[i].clear();
    used[i] = false;
  }

  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
  }

  dfs(0, -1);
  ans_dfs(0, -1, 1);
  cout << (n - 1) - dp[0][1] << "\n";
  //per(cnt);

  int pr = -1;
  for (int i = 0; i < n; ++i) {
    assert(cnt[i] <= 2);
    if (cnt[i] == 2 || used[i]) continue;

    if (pr != -1) {
      addt.pb({pr, i});
    }
    pr = rdfs(i, -1);
    assert(cnt[i] == cnt[pr] && cnt[i] < 2);
    //cout << pr << " " << i << endl;
  }

  //cout << delt.size() << " " << addt.size() << endl;

  assert(addt.size() == delt.size());
  assert(addt.size() == (n - 1) - dp[0][1]);
  for (int i = 0; i < (int) delt.size(); ++i) {
    cout << delt[i].x + 1 << " " << delt[i].y + 1 << " " << addt[i].x + 1 << " " << addt[i].y + 1 << "\n";
  }
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