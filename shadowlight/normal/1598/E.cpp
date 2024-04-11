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

int n, m, q;
const int N = 1007;
int field[N][N];

int calc(int delta) {
  int res = 0;
  for (int it = 0; it <= 1; ++it) {
    int now = 0;
    for (int y = 0; y < m; ++y) {
      int x = delta + y;
      if (x < 0 || x >= n || field[x][y]) {
        for (int yy = now; yy < y; ++yy) {
          res += 2 * (y - yy) - 1;  
        }
        now = y + 1;
        continue;
      }

      int x1, y1;
      if (!it) {
        x1 = x, y1 = y + 1;
      } else {
        x1 = x + 1, y1 = y;
      }
      if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || field[x1][y1]) {
        for (int yy = now; yy < y; ++yy) {
          res += 2 * (y - yy);
        }
        now = y + 1;
        continue;
      }
    }
    for (int yy = now; yy < m; ++yy) {
      res += 2 * (m - yy) - 1;  
    }
  }
  return res;
}

int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n >> m >> q;

  int res = 0;
  int full = n * m;
  for (int i = -m; i < n; ++i) {
    res += calc(i);
  }

  for (int i = 0; i < q; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    int delta = x - y;
    
    res -= calc(delta - 1);
    res -= calc(delta);
    res -= calc(delta + 1);

    full -= !field[x][y];
    field[x][y] ^= 1;
    full += !field[x][y];

    res += calc(delta - 1);
    res += calc(delta);
    res += calc(delta + 1);

    cout << res + full << "\n";
  }

}