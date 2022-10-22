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
vector <pair<int, int>> gr[N];
int isFib[N];
int sz[N];
int p[N];

int banned[N];
bool used[N];

int cut = 0;
vector <int> arr;

void dfs(int v, int pid = -1) {
  //cout << v << " " << pid << endl;
  arr.pb(v);
  used[v] = true;
  sz[v] = 1;
  p[v] = pid;

  for (auto [u, id] : gr[v]) {
    if (banned[id] || id == pid) continue;
    dfs(u, id);
    sz[v] += sz[u];
  }
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  int f0 = 1, f1 = 1;
  while (f1 < N) {
    isFib[f1] = true;
    int f2 = f1 + f0;
    f0 = f1;
    f1 = f2;
  }

  if (!isFib[n]) {
    cout << "NO\n";
    return 0;
  }

  for (int i = 1; i < n; ++i) {
    int v, u;
    cin >> v >> u;
    --v, --u;
    gr[v].pb({u, i});
    gr[u].pb({v, i});
  }

  while (cut != n - 1) {
    for (int i = 0; i < n; ++i) {
      used[i] = false;
    }
    for (int i = 0; i < n; ++i) {
      if (used[i]) continue;
      arr.clear();
      dfs(i);


      if (arr.size() == 1) continue;

      bool can = false;
      for (int v : arr) {
        if (v != i && isFib[sz[v]] && isFib[sz[i] - sz[v]]) {
          ++cut;
          banned[p[v]] = true;
          can = true;
          break;
        }
      }
      if (!can) {
        cout << "NO\n";
        return 0;
      }
    }
  }

  cout << "YES\n";
}