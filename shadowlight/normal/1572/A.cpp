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

void solve() {
  int n;
  cin >> n;
  vector <vector<int>> a(n);
  vector <vector<int>> b(n);
  vector<int> sizes(n, 0);

  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    a[i].resize(k);
    sizes[i] = k;
    for (int j = 0; j < k; ++j) {
      int x;
      cin >> x;
      --x;
      b[x].pb(i);
      a[i][j] = x;
    }
  }

  vector<int> cnt(n, -1);
  deque<int> q;
  for (int v = 0; v < n; ++v) {
    if (!sizes[v]) {
      q.push_back(v);
      cnt[v] = 1;
    }
  }
  int res = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (int u : b[v]) {
      --sizes[u];
      if (u > v) {
        uax(cnt[u], cnt[v]);
      } else {
        uax(cnt[u], cnt[v] + 1);
      }
      if (!sizes[u]) {
        if (cnt[u] == cnt[v]) {
          q.push_front(u);
        } else {
          assert(cnt[u] == cnt[v] + 1);
          q.push_back(u);
        }
      }
    }
  }
  for (int v = 0; v < n; ++v) {
    if (sizes[v]) {
      cout << "-1\n";
      return;
    }
    res = max(res, cnt[v]);
  }
  cout << res << "\n";
}

int main(){
#ifdef LOCAL
  freopen("A_input.txt", "r", stdin);
  //freopen("A_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }

}