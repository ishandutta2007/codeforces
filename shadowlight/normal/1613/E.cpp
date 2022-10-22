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

const int D = 4;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> field(n);
  for (int i = 0; i < n; ++i) {
    cin >> field[i];
  }

  vector<vector<bool>> good(n, vector<bool>(m, false));
  int x, y;

  queue<pair<int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == 'L') {
        x = i, y = j;
      }
    }
  }
  good[x][y] = true;
  q.push({x, y});

  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
  
    int cnt = 0;
    for (int d = 0; d < D; ++d) {
      int xx = dx[d] + x, yy = dy[d] + y;
      if (xx < 0 || xx >= n || yy < 0 || yy >= m || field[xx][yy] == '#') continue;
      if (good[xx][yy]) continue;
      int cnt = 0;

      for (int d = 0; d < D; ++d) {
        int xt = dx[d] + xx, yt = dy[d] + yy;
        if (xt < 0 || xt >= n || yt < 0 || yt >= m || field[xt][yt] == '#') continue;
        if (good[xt][yt]) continue;
        ++cnt;
      }
      if (cnt < 2) {
        good[xx][yy] = true;
        q.push({xx, yy});
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (field[i][j] != '.') {
        cout << field[i][j];
      } else if (good[i][j]) {
        cout << "+";
      } else {
        cout << ".";
      }
    }
    cout << "\n";
  }
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}