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

const int N = 1007;

int n, m;
bool used[N][N];
vector <string> field;

const int D = 4;
vector <int> dx = {0, 1, 0, -1};
vector <int> dy = {1, 0, -1, 0};

void dfs(int x, int y) {
  if (used[x][y]) return;
  used[x][y] = true;

  for (int d = 0; d < D; ++d) {
    int xx = x + dx[d], yy = y + dy[d];
    if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
      continue;
    }
    if (field[xx][yy] == '.') continue;
    dfs(xx, yy);
  }
}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m;
  field.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> field[i];
  }
  int have_row = 0, have_col = 0;
  for (int i = 0; i < n; ++i) {
    int cntr = 0;
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == '#' && (!j || field[i][j - 1] == '.')) {
        ++cntr;
      }
    }
    if (cntr > 1) {
      cout << "-1\n";
      return 0;
    }
    if (!cntr) {
      have_row = 1;
    }
  }

  for (int j = 0; j < m; ++j) {
    int cntc = 0;
    for (int i = 0; i < n; ++i) {
      if (field[i][j] == '#' && (!i || field[i - 1][j] == '.')) {
        ++cntc;
      }
    }
    if (cntc > 1) {
      cout << "-1\n";
      return 0;
    }
    if (!cntc) {
      have_col = 1;
    }
  }

  if (have_row + have_col == 1) {
    cout << "-1\n";
    return 0;
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (used[i][j] || field[i][j] == '.') continue;
      ++res;
      dfs(i, j);
    }
  }
  cout << res << "\n";
}