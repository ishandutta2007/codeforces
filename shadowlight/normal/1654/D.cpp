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

int rev(int a) {
  return bp(a, mod - 2);
}

const int N = 2e5 + 7;

struct Edge {
  int v;
  int x, y;
};
vector<vector<Edge>> gr;
vector<int> factorize[N];
int revs[N];

void dfs(int v, int p, int &g, vector<int>& vals) {
  //per(v, p, g);
  for (auto e : gr[v]) {
    if (e.v == p) continue;

    for (int x : factorize[e.x]) {
      if (vals[x]) {
        --vals[x];
        g = mult(g, revs[x]);
      }
    }
    for (int x : factorize[e.y]) {
      ++vals[x];
      g = mult(g, x);
    }

    dfs(e.v, v, g, vals);

    for (int x : factorize[e.y]) {
      --vals[x];
      g = mult(g, revs[x]);
    }
    for (int x : factorize[e.x]) {
      ++vals[x];
      g = mult(g, x);
    }
  }
}

int res = 0;

void calc_res(int v, int p, int g) {
  add(res, g);
  for (auto e : gr[v]) {
    if (e.v == p) continue;
    calc_res(e.v, v, mult(mult(g, e.y), rev(e.x)));
  }
}

void solve() {
  int n;
  cin >> n;

  res = 0;

  gr.assign(n, {});

  for (int i = 1; i < n; ++i) {
    int v, u, x, y;
    cin >> v >> u >> x >> y;
    --v, --u;
    int g = __gcd(x, y);
    x /= g, y /= g;

    gr[v].pb({u, x, y});
    gr[u].pb({v, y, x});
  }

  vector<int> vals(N, 0);
  int start = 1;
  dfs(0, -1, start, vals);
  calc_res(0, -1, start);

  cout << res << "\n";
}

void do_factorize() {
  for (int i = 2; i < N; ++i) {
    if (factorize[i].size()) continue;
    revs[i] = rev(i);

    for (int j = i; j < N; j += i) {
      int x = j;
      while (x % i == 0) {
        factorize[j].pb(i);
        x /= i;
      }
    }
  }
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  do_factorize();

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}