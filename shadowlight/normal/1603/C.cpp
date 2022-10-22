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

const int N = 2e5 + 7;
const int SQ = sqrt(N) + 10;
//const int SQ = 10;

int upper(int x, int y) {
  int res = x / y;
  if (x % y) ++res;
  return res;
}

int lower(int x, int y) {
  return x / y;
}

int small[2][SQ];
int large[2][SQ];

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int t = 1; t < SQ; ++t) {
    large[0][t] = t - 1;
  }
  for (int x = 1; x < SQ; ++x) {
    int moves = upper(a[0], x) - 1;

    small[0][x] = moves;
  }

  int res = 0;

  int uk = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < SQ; ++j) {
      small[uk ^ 1][j] = 0;
      large[uk ^ 1][j] = 0;
    }

    if (a[i] < SQ) {
      //per(i, a[i], small[uk][a[i]]);
      add(res, small[uk][a[i]]);
    } else {
      int moves = upper(a[i - 1], a[i]) - 1;
      assert(moves < SQ);
      add(res, large[uk][moves + 1]);
    }

    for (int t = 1; t < SQ; ++t) {
      int lval = lower(a[i], t);
      int rval = upper(a[i], t);

      add(large[uk ^ 1][t], mult(t - 1, i + 1));
      
      if (lval < SQ) {
        add(large[uk ^ 1][t], small[uk][lval]);
      } else {
        int moves = upper(a[i - 1], lval) - 1;
        assert(moves < SQ);
        add(large[uk ^ 1][t], large[uk][moves + 1]);
      }
    }

    for (int x = 1; x < SQ; ++x) {
      int moves = upper(a[i], x) - 1;
      add(small[uk ^ 1][x], mult(moves, i + 1));

      int lval = lower(a[i], moves + 1);
      int rval = upper(a[i], moves + 1);

      if (lval < SQ) {
        add(small[uk ^ 1][x], small[uk][lval]);
      } else {
        int moves = upper(a[i - 1], lval) - 1;
        //per("MOVES", moves);
        assert(moves < SQ);
        add(small[uk ^ 1][x], large[uk][moves + 1]);
      }
    }
    uk ^= 1;
  }

  cout << res << "\n";
}


int main(){
#ifdef LOCAL
  freopen("C_input.txt", "r", stdin);
  //freopen("C_output.txt", "w", stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    solve();
  }

}