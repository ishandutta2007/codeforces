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

const int R2 = (mod + 1) / 2;

int main(){
#ifdef LOCAL
  freopen("E_input.txt", "r", stdin);
  //freopen("E_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  map <pair<int, int>, int> table;

  vector <int> rows_odd(n), rows_even(n);
  vector <int> cols_odd(m), cols_even(m);

  int res_row = bp(2, n);
  int res_col = bp(2, m);

  int rows_bad = 0, cols_bad = 0;

  ll chess0 = n * (ll)m, chess1 = n * (ll)m;

  for (int i = 0; i < k; ++i) {
    int x, y, tp;
    cin >> x >> y >> tp;
    --x, --y;

    if (table.count({x, y})) {
      if (rows_odd[x] && rows_even[x]) {
        --rows_bad;
      } else if (!rows_odd[x] && !rows_even[x]) {
        res_row = mult(res_row, R2);
      }

      if (table[{x, y}] == (x + y) % 2) {
        chess0++;
      } else {
        chess1++;
      }

      if (cols_odd[y] && cols_even[y]) {
        --cols_bad;
      } else if (!cols_odd[y] && !cols_even[y]) {
        res_col = mult(res_col, R2);
      }

      int now = table[{x, y}] ^ (y % 2);
      if (now) {
        rows_odd[x]--;
      } else {
        rows_even[x]--;
      }

      now = table[{x, y}] ^ (x % 2);
      if (now) {
        cols_odd[y]--;
      } else {
        cols_even[y]--;
      }

      if (rows_odd[x] && rows_even[x]) {
        ++rows_bad;
      } else if (!rows_odd[x] && !rows_even[x]) {
        res_row = mult(res_row, 2);
      }

      if (cols_odd[y] && cols_even[y]) {
        ++cols_bad;
      } else if (!cols_odd[y] && !cols_even[y]) {
        res_col = mult(res_col, 2);
      }

      table.erase({x, y});
    }

    if (tp != -1) {
      table[{x, y}] = tp;

      if (rows_odd[x] && rows_even[x]) {
        --rows_bad;
      } else if (!rows_odd[x] && !rows_even[x]) {
        res_row = mult(res_row, R2);
      }

      if (table[{x, y}] == (x + y) % 2) {
        chess0--;
      } else {
        chess1--;
      }

      if (cols_odd[y] && cols_even[y]) {
        --cols_bad;
      } else if (!cols_odd[y] && !cols_even[y]) {
        res_col = mult(res_col, R2);
      }

      int now = table[{x, y}] ^ (y % 2);
      if (now) {
        rows_odd[x]++;
      } else {
        rows_even[x]++;
      }

      now = table[{x, y}] ^ (x % 2);
      if (now) {
        cols_odd[y]++;
      } else {
        cols_even[y]++;
      }

      if (rows_odd[x] && rows_even[x]) {
        ++rows_bad;
      } else if (!rows_odd[x] && !rows_even[x]) {
        res_row = mult(res_row, 2);
      }

      if (cols_odd[y] && cols_even[y]) {
        ++cols_bad;
      } else if (!cols_odd[y] && !cols_even[y]) {
        res_col = mult(res_col, 2);
      }
    }

    int res = 0;

    if (!rows_bad) {
      add(res, res_row);
    }
    if (!cols_bad) {
      add(res, res_col);
    }

    if (chess0 == n * (ll)m) {
      dec(res, 1);
    }
    if (chess1 == n * (ll)m) {
      dec(res, 1);
    }

    cout << res << "\n";
  }

}