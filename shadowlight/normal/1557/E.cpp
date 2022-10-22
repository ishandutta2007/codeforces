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

bool beaten(int x, int y, int rx, int ry) {
  if (rx == x || ry == y) {
    return true;
  }
  if (abs(rx - x) == abs(ry - y)) {
    return true;
  }
  return false;
}

const int N = 8;
int qx = 3, qy = 3;

const int D = 8;
vector<int> dx = {0, -1, 0, 1, -1, -1, 1, 1};
vector<int> dy = {1, 0, -1, 0, -1, 1, -1, 1};

vector<string> shifts = {"Right", "Up", "Left", "Down",
          "Up-Left", "Up-Right", "Down-Left", "Down-Right"};
  
void print() {
  cout << qx + 1 << " " << qy + 1 << endl;
}

vector <vector<bool>> possible;

int get_count(int nx, int ny) {
  int res = 0;
  for (int d = 0; d < D; ++d) {
    vector<vector<bool>> npossible(N, vector<bool>(N, false));
    int now = 0;  
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (!possible[i][j]) continue;
        int x = i + dx[d], y = j + dy[d];
        if (x < 0 || x >= N || y < 0 || y >= N || beaten(nx, ny, x, y)) {
          continue;
        }
        now += !npossible[x][y];
        npossible[x][y] = true;
      }
    }
    res = max(res, now);
  }
  return res;
}

void shift(int d) {
  vector<vector<bool>> npossible(N, vector<bool>(N, false));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (!possible[i][j]) continue;
      int x = i + dx[d], y = j + dy[d];
      if (x < 0 || x >= N || y < 0 || y >= N || beaten(qx, qy, x, y)) {
        continue;
      }
      npossible[x][y] = true;
    }
  }
  possible = npossible;
}

void print_desk() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cerr << (int) possible[i][j];
    }
    cerr << endl;
  }
}

int kx = 4, ky = 4;
bool endq = false;

int get_positions() {
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cnt += possible[i][j];
    }
  }
  return cnt;
}

int qs = 0;

bool interact() {
  string s = "Done";
  /*if ((++qs) > 60) {
    print_desk();
    exit(0);
  }*/
  /*for (int d = 0; d < D; ++d) {
    int x = kx + dx[d], y = ky + dy[d];
    if (x < 0 || x >= N || y < 0 || y >= N) continue;
    if (beaten(qx, qy, x, y)) continue;
    kx = x, ky = y;
    s = shifts[d];
    break;
  }*/
  //per("KING", kx, ky);
  cin >> s;
  if (s == "Done") {
    endq = true;
    return false;
  }
  bool shifted = false;
  for (int d = 0; d < D; ++d) {
    if (shifts[d] == s) {
      shift(d);
      shifted = true;
      break;
    }
  }
  assert(shifted);
  assert(get_positions());
  //print_desk();
  return true;
}

void get_pos(int &x, int &y) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (possible[i][j]) {
        x = i, y = j;
        return;
      }
    }
  }
  assert(false);
}

const int INF = 1e9 + 7;

void solve() {
  qs = 0;
  kx = rand() % N, ky = rand() % N;
  qx = 5, qy = 5;
  endq = false;
  print();

  possible.assign(N, vector<bool>(N, true));
  possible[qx][qy] = false;
  while (interact()) {
    if (get_positions() < 3) {
      break;
    }
    int res = INF;
    int nx = -1, ny = -1;
    for (int x = 0; x < N; ++x) {
      for (int y = 0; y < N; ++y) {
        if (!beaten(qx, qy, x, y) || (x == qx && y == qy)) continue;
        int cnt = get_count(x, y);
        if (cnt < res) {
          res = cnt;
          nx = x, ny = y;
        }
      }
    }
    //pper(res);
    qx = nx, qy = ny;
    print();
  }
  if (endq) return;

  int positions = get_positions();

  while (positions > 0) {
    if (endq) {
      return;
    }
    int x, y;
    get_pos(x, y);

    int wx = x, wy = y;
    assert(qx != x);
    qx = x;
    print();
    if (!interact()) return;
    if (get_positions() < positions) {
      positions = get_positions();
      continue;
    }
    get_pos(x, y);

    assert(qy != wy);
    qy = wy;
    print();
    int deltax = qx - x, deltay = qy - y;

    while (interact()) {
       if (get_positions() < positions) {
        positions = get_positions();
        break;
      }
      get_pos(x, y);
      qx = x + deltax, qy = y + deltay;
      print();
    }
  }
}

int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}