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

vector<pair<int, int>> a;
vector <vector<int>> matrix;
int m, k;
  
bool can(int n, bool construct = false){
  if (((n + 1) / 2) * n >= m && !construct) {
    return true;
  }
  matrix.clear();
  matrix.resize(n, vector<int>(n, 0));

  vector <pair<int, int>> order;
  for (int i = 1; i < n; i += 2) {
    for (int j = 0; j < n; j += 2) {
      order.pb({i, j});
    }
  }
  for (int i = 0; i < n; i += 2) {
    for (int j = 1; j < n; j += 2) {
      order.pb({i, j});
    }
  }
  vector <pair<int, int>> norder;
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < n; j += 2) {
      norder.pb({i, j});
    }
  }

  auto b = a;
  int now1 = 0, now2 = 0;
  int now = 0;

  while (true) {
    while (now < k && !a[now].x) ++now;
    if (now == k) break;

    int val = a[now].y + 1;
    bool good = true;
    --a[now].x;

    if (now1 < order.size()) {
      int x = order[now1].x, y = order[now1].y;

      if (x > 0 && y > 0 && matrix[x - 1][y - 1] == val) {
        good = false;
      }
      if (x > 0 && y + 1 < n && matrix[x - 1][y + 1] == val) {
        good = false;
      }
      if (x + 1 < n && y > 0 && matrix[x + 1][y - 1] == val) {
        good = false;
      }
      if (x + 1 < n && y + 1 < n && matrix[x + 1][y + 1] == val) {
        good = false;
      }

      if (good) {
        matrix[x][y] = val;
        ++now1;
        continue;
      }
    }

    if (now2 < norder.size()) {
      int x = norder[now2].x, y = norder[now2].y;
      ++now2;
      matrix[x][y] = val;
      continue;
    }
    a = b;
    return false;
  }
  a = b;


  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j + 1 < n; ++j) {
      if (!matrix[i][j] || !matrix[i + 1][j] || !matrix[i][j + 1] || !matrix[i + 1][j + 1]) {
        if (!matrix[i][j] || matrix[i][j] != matrix[i + 1][j + 1]) {
          if (!matrix[i + 1][j] || matrix[i + 1][j] != matrix[i][j + 1]) continue;
        }
      }
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> m >> k;
  a.clear();
  a.resize(k);

  for (int i = 0; i < k; ++i) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(all(a));
  reverse(all(a));

  int l = 0, r = N;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  int n = r;
  assert(can(n, true));
  //per(n);

  cout << n << "\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j + 1 < n; ++j) {
      assert(!matrix[i][j] || !matrix[i + 1][j] || !matrix[i][j + 1] || !matrix[i + 1][j + 1]);
      assert(!matrix[i][j] || matrix[i][j] != matrix[i + 1][j + 1]);
      assert(!matrix[i + 1][j] || matrix[i + 1][j] != matrix[i][j + 1]);
    }
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

 //cout << "1\n";
}