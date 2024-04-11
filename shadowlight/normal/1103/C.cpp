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

int n, m, k;
int need = 0;
vector<vector<int>> gr;
vector <int> d;
vector <int> pred;
vector <bool> used;

void dfs(int v, int p, int h = 0) {
  if (used[v]) return;
  used[v] = true;
  pred[v] = p;
  d[v] = h;
  for (int u : gr[v]) {
    dfs(u, v, h + 1);
  }
}

int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  need = n / k;
  if (n % k) ++need;

  pred.resize(n);
  d.resize(n);
  gr.resize(n);

  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
  }
  used.resize(n, false);
  dfs(0, -1);

  for (int v = 0; v < n; ++v) {
    if (d[v] >= need) {
      vector <int> res;
      while (v != -1) {
        res.pb(v);
        v = pred[v];
      }
      cout << "PATH\n";
      cout << res.size() << "\n";
      for (int x : res) {
        cout << x + 1 << " ";
      }
      cout << "\n";
      exit(0);
    }
  }
  cout << "CYCLES\n";

  int cnt = 0;

  for (int v = 0; v < n; ++v) {
    bool is_leaf = true;
    for (int u : gr[v]) {
      if (d[u] > d[v]) {
        is_leaf = false;
        break;
      }
    }
    if (is_leaf) {
      vector <pair<int, int>> vals;
      vals.pb({d[v], v});
      for (int u : gr[v]) {
        if (d[u] == d[v] - 1) continue;
        vals.pb({d[u], u});
        if (vals.size() == 3) break;
      }
      sort(all(vals));

      assert(vals.size() == 3);

      int v = vals[2].y, u = vals[1].y, w = vals[0].y;
      vector <int> res;
      if ((d[v] - d[u] + 1) % 3) {
        while (v != u) {
          res.pb(v);
          v = pred[v];
        }
        res.pb(u);
      } else if ((d[v] - d[w] + 1) % 3) {
        while (v != w) {
          res.pb(v);
          v = pred[v];
        }
        res.pb(w);
      } else {
        while (u != w) {
          res.pb(u);
          u = pred[u];
        }
        res.pb(w);
        res.pb(v);
      }

      cout << res.size() << "\n";
      for (int x : res) {
        cout << x + 1 << " ";
      }
      cout << "\n";

      if (++cnt == k) {
        exit(0);
      }
    }
  }
}