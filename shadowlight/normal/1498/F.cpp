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

int n, k;
vector <vector<int>> gr;
vector<int> a;
vector <int> res;
vector <vector<int>> xors;

void dfs(int v, int p) {
  xors[v][0] ^= a[v];
  for (int u : gr[v]) {
    if (u == p) continue;
    dfs(u, v);
    for (int i = 0; i < 2 * k; ++i) {
      xors[v][(i + 1) % (2 * k)] ^= xors[u][i];
    }
  }
}

vector<int> now;

void res_dfs(int v, int p) {
  for (int i = k; i < 2 * k; ++i) {
    res[v] ^= now[i] ^ xors[v][i];
  }

  vector<int> xxor(2 * k, 0);
  for (int u : gr[v]) {
    if (u == p) continue;
    for (int i = 0; i < 2 * k; ++i) {
      xxor[(i + 1) % (2 * k)] ^= xors[u][i];
    }
  }

  for (int u : gr[v]) {
    if (u == p) continue;
    for (int i = 0; i < 2 * k; ++i) {
      xxor[(i + 1) % (2 * k)] ^= xors[u][i];
    }

    vector <int> nxt(2 * k, 0);
    for (int i = 0; i < 2 * k; ++i) {
      nxt[(i + 1) % (2 * k)] ^= now[i] ^ xxor[i];
    }
    nxt[1] ^= a[v];

    auto was = now;
    now = nxt;
    res_dfs(u, v);
    now = was;
    
    for (int i = 0; i < 2 * k; ++i) {
      xxor[(i + 1) % (2 * k)] ^= xors[u][i];
    }
  }
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> k;
  gr.resize(n);
  a.resize(n);
  res.resize(n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    gr[x].pb(y);
    gr[y].pb(x);
  }

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  xors.resize(n, vector<int>(2 * k, 0));
  dfs(0, -1);

  now.resize(2 * k, 0);
  res_dfs(0, -1);

  for (int x : res) {
     cout << (bool) x << " ";
  }
  cout << "\n";
}