#ifdef LOCAL
#include <stdint.h>
#include <inttypes.h>
#include <sys/resource.h>
struct ___ { ___(){ rlimit R{}; getrlimit(RLIMIT_STACK, &R); R.rlim_cur = R.rlim_max; setrlimit(RLIMIT_STACK, &R); }} ___;
#endif

#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)

using namespace std;

#ifndef LOCAL
#define cerr while(0) cerr
#endif

#ifdef AUTO_MALLOC
namespace MALLOC { const size_t MAX_HEAP = 256 * 1000 * 1000; char buf[MAX_HEAP]; size_t ptr; }
void* operator new(size_t size) { void *result = MALLOC::buf + MALLOC::ptr; MALLOC::ptr += size; return result; }
void operator delete(void *ptr) noexcept { /* DO NOTHING */ }
#endif //AUTO_MALLOC


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
//typedef pair<long long, long long> pii;
typedef vector<long long> vll;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
typedef unsigned int uint;

const ld PI = 3.1415926535897932384626433832795L;

template<class T>
bool uin(T &, const T &);

template<class T>
bool uax(T &, const T &);

template<class T>
T gcd(T, T);

template<class T>
T lcm(T, T);

template<class _T>
inline string tostr(const _T &);

template<typename T>
void input(T &);

template<typename T = long long>
T nxt();

bool checkp(long long);

template<typename T>
T pw(T a, T n, T m);

template<typename T>
T inv(T a, T p);

template<class _T>
_T sqr(const _T &x);



int TTT;

const ll mod = 998244353;


void pre() {
}

// A(n, k) = (k - 1) * A(n - 1, k - 2) + (n - k) * A(n - 1, k - 1)

void solve(int) {
  int n = nxt();
  vector <vi> a(n, vi(n));

  forn(i, n) {
    forn(j, n) a[i][j] = nxt() - 1;
  }

  vector <vll> dp(n + 1, vll(n + 1));

  dp[0][0] = 1;

  for (int i = 1; i <= n; ++i) {
    dp[i][0] = dp[i - 1][0] * i % mod;
    dp[i][1] = (i - 1) * dp[i - 1][0] % mod;

    for (int j = 2; j <= i; ++j) {
      dp[i][j] = ((j - 1) * dp[i - 1][j - 2] + (i - j) * dp[i - 1][j - 1]) % mod;
    }
  }

  vll s(n);
  s[0] = 1;
  forn(i, n - 1) {
    s[i + 1] = s[i] * dp[n][n] % mod;
  }

  vi prev(n, n);

  ll answer = 0;

  vector <bitset <2001>> pref(n);

  forn(i, n - 1) {
    pref[i + 1] = pref[i];
    pref[i + 1][i] = true;
  }

  forn(i, n) {
    bitset <2001> was;
    bitset <2001> used;

    if (i) for (int x : prev) was[x] = true;

    long long Z = 0;

    forn(j, n) {
      was[prev[j]] = false;

      size_t rem = (~used & was).count();
      auto CUR = (~used & pref[a[i][j]]);
      CUR[prev[j]] = false;

      size_t A = CUR.count();
      size_t B = (CUR & was).count();
      A -= B;

//      if (i == 0) assert(rem == 0);
      assert(rem > 0 || B == 0);

      Z += (rem > 0 ? (dp[n - j - 1][rem - 1] * B) : 0) + dp[n - j - 1][rem] * A;
      Z %= mod;

      assert(prev[j] != a[i][j]);

      used[a[i][j]] = true;
    }
//    cerr << i << " " << Z << "\n";
    answer += Z * s[n - 1 - i];
    answer %= mod;

    prev = a[i];
  }

  cout << answer << "\n";
}

int main(int argc, char **argv) {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
  #define fname "sequence"
  //freopen(fname".in", "r", stdin);
  //freopen(fname".out", "w", stdout);
#endif
  ::TTT = 1;

  pre();
  for (int test = 1; test <= ::TTT; ++test) {
    solve(test);
  }

#ifdef LOCAL
  cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
  return 0;
}

template<typename T>
T gcd(T x, T y) {
  while (y > 0) {
    x %= y;
    swap(x, y);
  }
  return x;
}

template<class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

template<class _T>
inline _T sqr(const _T &x) {
  return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
  ostringstream os("");
  os << a;
  return os.str();
}

template<typename T>
inline void input(T &a) {
  static int ed;
  a = 0;
  while (!isdigit(ed = getchar()) && ed != '-') {}
  char neg = 0;
  if (ed == '-') {
    neg = 1;
    ed = getchar();
  }
  while (isdigit(ed)) {
    a = 10 * a + ed - '0';
    ed = getchar();
  }
  if (neg) a = -a;
}

template<typename T>
inline T nxt() {
  T res;
  input(res);
  return res;
}

void myassert(bool v) {
  assert(v);
//cout << "FAIL\n";
//exit(0);
}

mt19937 generator;

bool checkp(long long v) {
  if (v < 2) return false;
  for (long long i = 2; i * i <= v; ++i) {
    if (v % i == 0) {
      return false;
    }
  }
  return true;
}

template<typename T>
T pw(T a, T n, T m) {
  T res = 1;
  while (n) {
    if (n & 1) {
      res = res * a % m;
    }
    a = a * a % m;
    n >>= 1;
  }
  return res;
}

template<typename T>
T inv(T a, T p) {
  T res = 1;
  while (a > 1) {
    res = res * (p - p / a) % p;
    a = p % a;
  }
  return res;
}

template<class T>
bool uin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
bool uax(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}