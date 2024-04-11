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

int c[N];
int val[N];
int pos[N];

vector <pair<int, int>> res;
void swap_vals(int px, int py) {
  assert(px != py);
  res.pb({px, py});
  
  swap(c[px], c[py]);
  swap(pos[c[px]], pos[c[py]]);
  val[c[px]] ^= 1;
  val[c[py]] ^= 1;
}

int n;

int main(){
#ifdef LOCAL
 freopen("G_input.txt", "r", stdin);
 //freopen("G_output.txt", "w", stdout);
#endif
 ios_base::sync_with_stdio(0);
 cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
    --c[i];
    pos[c[i]] = i;
    val[c[i]] = 0;
  }

  vector <bool> used(n, false);

  int now = 0;

  for (int w = 0; w < n; ++w) {
    if (used[w]) continue;

    int v = w;
    vector <int> cycle;
    while (!used[v]) {
      used[v] = true;
      cycle.pb(v);
      v = c[v];
    }
    if (cycle.size() == 1) continue;

    bool found = false;
    vector <int> cycle2;
    while (true) {
      cycle2.clear();
      while (now < n && used[now]) ++now;
      if (now == n) break;

      int u = now;
      while (!used[u]) {
        used[u] = true;
        cycle2.pb(u);
        u = c[u];
      }  
      if (cycle2.size() == 1) continue;

      swap_vals(cycle[0], cycle2.back());
      int tet = cycle2.back();
      for (int x = 1; x < (int) cycle.size(); ++x) {
        swap_vals(cycle2.back(), cycle[x]);
      }
      for (int x = 0; x + 1 < (int) cycle2.size(); ++x) {
        swap_vals(cycle[0], cycle2[x]);
      }
      swap_vals(cycle[0], cycle2.back());
      found = true;
      break;
    }
    if (found) continue;

    cycle2.clear();
    for (int v = 0; v < n; ++v) {
      if (c[v] == v) {
        cycle2.pb(v);
        break;
      }
    }
    if (cycle2.size()) {
      swap_vals(cycle[0], cycle2.back());
      int tet = cycle2.back();
      for (int x = 1; x < (int) cycle.size(); ++x) {
        swap_vals(cycle2.back(), cycle[x]);
      }
      for (int x = 0; x + 1 < (int) cycle2.size(); ++x) {
        swap_vals(cycle[0], cycle2[x]);
      }
      swap_vals(cycle[0], cycle2.back());
      break;
    }

    assert(cycle.size() > 2);
    swap_vals(cycle[0], cycle[1]);
    swap_vals(cycle[1], cycle[2]);
    swap_vals(cycle[0], cycle[2]);
    for (int x = 3; x < (int) cycle.size(); ++x) {
      swap_vals(cycle[1], cycle[x]);
    }
    swap_vals(cycle[1], cycle[0]);
    break;
  }

  for (int i = 0; i < n; ++i) {
    assert(c[i] == i);
    assert(!val[i]);
  }

  assert(res.size() <= n + 1);
  cout << res.size() << "\n";
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i].x + 1 << " " << res[i].y + 1 << "\n";
  }
}