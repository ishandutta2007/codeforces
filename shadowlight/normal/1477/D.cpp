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

const int N = 5e5 + 7;

vector <int> tree[N];
bool used[N];
int now = 0;

struct DSU {
  int n;
  vector <int> p, r, lst;
  DSU(int n) : n(n), p(n), r(n), lst(n) {
    iota(all(p), 0);
    iota(all(lst), 0);
  }

  int get(int v) {
    return (v == p[v] ? v : p[v] = get(p[v]));
  }

  bool uni(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u) {
      return false;
    }
    if (r[v] > r[u]) swap(v, u);
    if (r[v] == r[u]) ++r[u];

    p[v] = u;
    lst[u] = max(lst[v], lst[u]);
    return true;
  }
};

vector <int> stars[N];

bool dfs(int v, int p) {
  used[v] = true;

  bool matched = false;
  for (int u : tree[v]) {
    if (u == p) continue;
    if (!dfs(u, v)) {
      matched = true;
      stars[v].pb(u);
    } 
  }
  if (p == -1 && !matched) {
    stars[tree[v][0]].pb(v);
  }
  return matched;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector <vector<int>> gr(n);

  for (int i = 0; i < n; ++i) {
    used[i] = false;
    stars[i].clear();
    tree[i].clear();
  }

  now = 0;
  for (int i = 0; i < m; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb(u);
    gr[u].pb(v);
  }
  
  vector<int> p(n), q(n);

  for (int i = 0; i < n; ++i) {
    if (gr[i].size() == n - 1) {
      p[i] = q[i] = now++;
      used[i] = true; 
    }
  }

  DSU dsu_segs(n), dsu(n);

  for (int v = 0; v < n; ++v) {
    if (used[v]) continue;
    sort(all(gr[v]));
    int pr = 0;
    for (int u : gr[v]) {
      int l = pr, r = u - 1;
      pr = u + 1;
      if (l > r) {
        continue;
      }

      int now = l;
      while (now <= r) {
        if (dsu.uni(v, now)) {
          tree[v].pb(now);
          tree[now].pb(v);
          //cout << "EDGE: " << v << " " << now << endl;
        }
        int nxt = dsu_segs.lst[dsu_segs.get(now)] + 1;
        if (nxt <= r) {
          dsu_segs.uni(now, nxt);
        }
        now = nxt;
      }
    }
    int l = pr, r = n - 1;
    if (l > r) {
      continue;
    }

    int now = l;
    while (now <= r) {
      if (dsu.uni(v, now)) {
        tree[v].pb(now);
        tree[now].pb(v);
        //cout << "EDGE: " << v << " " << now << endl;
      }
      int nxt = dsu_segs.lst[dsu_segs.get(now)] + 1;
      if (nxt <= r) {
        dsu_segs.uni(now, nxt);
      }
      now = nxt;
    }
  }

  for (int v = 0; v < n; ++v) {
    if (used[v]) continue;
    dfs(v, -1);
  }

  for (int v = 0; v < n; ++v) {
    if (!stars[v].size()) continue;
    auto star = stars[v];

    int size = star.size() + 1;
    p[v] = now;
    q[v] = now + size - 1;
    for (int i = 0; i < (int) star.size(); ++i) {
      p[star[i]] = now + i + 1;
      q[star[i]] = now + i; 
    }

    now += size;
  }

  for (int x : p) {
    cout << x + 1 << " ";
  }
  cout << "\n";

  for (int x : q) {
    cout << x + 1 << " ";
  }
  cout << "\n";
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