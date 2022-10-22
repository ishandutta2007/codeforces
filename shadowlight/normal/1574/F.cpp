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

vector<vector<pair<int, int>>> where;
vector<vector<int>> a;
vector<bool> bad;
vector<bool> badw;
vector<int> repl;

vector<int> current;

void dfs(int v, bool letter) {
  if (letter) {
    if (badw[v]) return;
    badw[v] = true;
    for (auto t : where[v]) {
      dfs(t.x, false);
    }  
  } else {
    if (bad[v]) return;
    current.pb(v);
    bad[v] = true;
    for (int x : a[v]) {
      dfs(x, true);
    }
  }
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  bad.resize(n, false);
  badw.resize(k, false);
  repl.resize(n, false);
  a.resize(n);
  where.resize(k);

  for (int i = 0; i < n; ++i) {
    int cnt;
    cin >> cnt;
    a[i].resize(cnt);
    bool good = true;
    for (int j = 0; j < cnt; ++j) {
      int x;
      cin >> x;
      --x;
      a[i][j] = x;
      where[x].pb({i, j});
    }
  }

  for (int i = 0; i < k; ++i) {
    if (badw[i]) continue;
    bool good = true;
    for (int j = 0; j + 1 < (int) where[i].size(); ++j) {
      if (where[i][j].x == where[i][j + 1].x) {
        good = false;
        break;
      }
    }
    if (!good) {
      dfs(i, true);
      continue;
    }
  }

  vector<int> cnt(m + 1, 0);
  vector<int> was(k, 0);
  vector<int> wh(k, -1);

  for (int i = 0; i < k; ++i) {
    if (badw[i]) continue;
    if (!where[i].size()) {
      ++cnt[1];
      continue;
    }

    int now = i;
    bool found = false;
    while (!was[now]) {
      was[now] = 1;
      found = true;
      for (auto t : where[now]) {
        if (a[t.x][0] != now) {
          now = a[t.x][0];
          found = false;
          break;
        }
      }
    }
    if (!found) {
      dfs(i, true);
      continue;
    }

    bool good = true;
    vector<int> s = {now};
    was[now] = 2;
    wh[now] = 0;


    for (int i = 0; i < (int) s.size(); ++i) {
      if (!good) break;
      for (auto t : where[s[i]]) {
        while (s.size() < (a[t.x].size() - t.y) + i) {
          int nxt = (int)s.size() - i + t.y;
          if (nxt < 0) {
            good = false;
            break;
          }
          s.pb(a[t.x][nxt]);
          if (was[s.back()] == 2) {
            good = false;
            break;
          }
          was[s.back()] = 2;
          wh[s.back()] = s.size() - 1;
        }
      }
    }

     for (int i = 0; i < (int) s.size(); ++i) {
      for (auto t : where[s[i]]) {
        if (t.y != a[t.x].size() - 1) continue;

        for (int j = 0; j < (int) a[t.x].size(); ++j) {
          if (i - j < 0 || s[i - j] != a[t.x][a[t.x].size() - 1 - j]) {
            good = false;
            break;
          }
        }
      }
      for (auto t : where[s[i]]) {
        if (t.y) continue;

        for (int j = 0; j < (int) a[t.x].size(); ++j) {
          if (i + j >= (int) s.size() || s[i + j] != a[t.x][j]) {
            good = false;
            break;
          }
        }
      }
    }
    dfs(i, true);
    if (!good) {
      continue;
    }
    if (s.size() <= m) cnt[s.size()]++;
  }

  vector <int> dp(m + 1, 0);
  dp[0] = 1;
  vector <int> lens;
  for (int i = 0; i <= m; ++i) {
    if (cnt[i]) lens.pb(i);
  }

  for (int i = 0; i < m; ++i) {
    for (int len : lens) {
      if (i + len > m) continue;
      add(dp[i + len], mult(dp[i], cnt[len]));
    }
  }
  cout << dp[m] << "\n";
}