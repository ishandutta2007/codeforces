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

const int INF = 1e9 + 7;
const int LOGN = 20;
vector<int> friends;
int n;
vector<vector<int>> gr;
vector<int> he;
vector<vector<int>> binup;
vector<int> cnt;

void dfs(int v, int p, int d) {
  he[v] = d;
  binup[v][0] = p;
  for (int i = 1; i < LOGN; ++i) {
    if (binup[v][i - 1] == -1) break;
    binup[v][i] = binup[binup[v][i - 1]][i - 1];
  }
  for (int u : gr[v]) {
    if (u == p) continue;
    dfs(u, v, d + 1);
  }
}

int up(int v, int d) {
  for (int i = 0; i < LOGN; ++i) {
    if ((1 << i) & d) {
      v = binup[v][i];
    }
  }
  return v;
}

int calc_dfs(int v, int p) {
  if (cnt[v]) {
    return 1;
  }
  if (p != -1 && gr[v].size() == 1) {
    return -1;
  }

  int sum = 0;
  for (int u : gr[v]) {
    if (u == p) continue;
    int now = calc_dfs(u, v);
    if (now == -1) {
      return -1;
    }
    sum += now;
  }
  return sum;
}

void solve() {
  int k;
  cin >> n >> k;
  gr.assign(n, {});
  he.assign(n, 0);
  friends.assign(k, 0);
  cnt.assign(n, 0);
  binup.assign(n, vector<int>(LOGN, -1));

  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    --x;
    friends[i] = x;
  }

  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
  }
  dfs(0, -1, 0);

  for (int v : friends) {
    int h = he[v];
    //per(v, h);
    v = up(v, h / 2);
    ++cnt[v];
  }

  cout << calc_dfs(0, -1) << "\n";
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}