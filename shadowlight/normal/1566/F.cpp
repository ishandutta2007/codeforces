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
const ll LINF = 1e18;

void solve() {
  int n, m;
  cin >> n >> m;

  vector <int> a(n);
  vector<pair<int, int>> segs(m);
  vector<pair<int, int>> nsegs;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> segs[i].x >> segs[i].y;
  }
  sort(all(a));
  sort(all(segs));


  for (int i = 0; i < m; ++i) {
    while (nsegs.size() && nsegs.back().y >= segs[i].y) {
      nsegs.pop_back();
    }
    nsegs.pb(segs[i]);
  }
  segs = nsegs;
  nsegs.clear();

  m = segs.size();

  vector <int> pos;
  pos.pb(-1);

  int now = 0;
  for (int i = 0; i < n; ++i) {
    while (now < m && segs[now].y < a[i]) {
      nsegs.pb(segs[now++]);
    }
    nsegs.pb({a[i], a[i]});
    pos.pb(nsegs.size() - 1);
    while (now < m && segs[now].x <= a[i]) {
      ++now;
    }
  }
  while (now < m) {
    nsegs.pb(segs[now++]);
  }
  pos.pb(nsegs.size());

  segs = nsegs;
  nsegs.clear();
  m = segs.size();

  vector<vector<ll>> dp(n + 1);
  vector<vector<ll>> pmin(n + 1);
  vector<vector<ll>> smin(n + 1);
  for (int i = 0; i <= n; ++i) {
    dp[i].resize(pos[i + 1] - pos[i], LINF);
    pmin[i].resize(pos[i + 1] - pos[i], LINF);
    smin[i].resize(pos[i + 1] - pos[i], LINF);
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int) dp[i].size(); ++j) {
      pmin[i][j] = dp[i][j] - segs[pos[i] + j + 1].y;
      if (j) {
        uin(pmin[i][j], pmin[i][j - 1]);
      }
    }

    for (int j = dp[i].size() - 1; j >= 0; --j) {
      smin[i][j] = dp[i][j] - 2 * segs[pos[i] + j + 1].y;
      if (j + 1 != dp[i].size()) {
        uin(smin[i][j], smin[i][j + 1]);
      }
    }
    for (int j = 0; j < dp[i + 1].size(); ++j) {
      int distb = segs[pos[i + 1] + j].x - a[i];

      int lt = -1, rt = dp[i].size();
      while (rt - lt > 1) {
        int mt = (lt + rt) / 2;
        int dista = a[i] - segs[pos[i] + mt + 1].y;
        if (dista > distb) {
          lt = mt;
        } else {
          rt = mt;
        }
      }

      if (lt != -1) {
        uin(dp[i + 1][j], pmin[i][lt] + a[i] + 2 * distb);        
      }

      if (rt != dp[i].size()) {
        uin(dp[i + 1][j], smin[i][rt] + 2 * a[i] + distb);
      }

      /*for (int k = 0; k < dp[i].size(); ++k) {
        int dista = a[i] - segs[pos[i] + k + 1].y;
        uin(dp[i + 1][j], dp[i][k] + 2 * min(dista, distb) + max(dista, distb));
      }*/
      //per(i, j, dp[i + 1][j]);
    }
  }
  cout << dp[n].back() << "\n";
}

int main(){
#ifdef LOCAL
  freopen("F_input.txt", "r", stdin);
  //freopen("F_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}