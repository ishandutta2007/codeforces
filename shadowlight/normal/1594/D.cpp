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

vector <vector<pair<int, int>>> gr;
vector <vector<pair<int, int>>> rgr;
vector <int> imp;
vector <int> used;

int now = 0;
bool dfs(int v, int tp, int is_imp) {
  if (used[v] == tp) {
    if (imp[v] != is_imp) {
      return true;
    }
    return false;
  }
  used[v] = tp;
  imp[v] = is_imp;
  now += is_imp;

  for (auto [u, w] : gr[v]) {
    if (dfs(u, tp, w ^ is_imp)) {
      return true;
    }
  }
  for (auto [u, w] : rgr[v]) {
    if (dfs(u, tp, w ^ is_imp)) {
      return true;
    }
  }
  return false;
}

void solve() {
  int n, m;
  cin >> n >> m;
  gr.assign(n, {});
  rgr.assign(n, {});
  imp.assign(n, 0);
  used.assign(n, 0);

  for (int i = 0; i < m; ++i) {
    int v, u;
    string s;
    cin >> v >> u >> s;
    --v, --u;
    bool is_imp = (s == "imposter");
    gr[v].pb({u, is_imp});
    rgr[u].pb({v, is_imp});
  }

  int res = 0;
  for (int v = 0; v < n; ++v) {
    if (used[v]) continue;
    int mx = -1;
    for (int it = 1; it <= 2; ++it) {
      now = 0;
      if (!dfs(v, it, it - 1)) uax(mx, now);
      //per(n, v, it, now);
    }
    if (mx == -1) {
      cout << "-1\n";
      return;
    }
    res += mx;
  }
  cout << res << "\n";
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