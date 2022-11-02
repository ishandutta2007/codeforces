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

const ll mod = 1000000007;


void pre() {
}

struct data {
  ll L;
  ll R;
  ll S;
  ll ans;

  data() {
    L = R = S = ans = static_cast<ll>(-1e18);
  }

  explicit data(ll x) {
    L = R = ans = max(0ll, x);
    S = x;
  }

  data operator+(const data &r) const {
    data res;
    res.L = max(L, S + r.L);
    res.R = max(r.R, r.S + R);
    res.S = max(ll(-1e18), S + r.S);
    res.ans = max(ans, max(r.ans, R + r.L));

    return res;
  }
};

void solve(int) {
  int n = nxt();
  ll a = nxt();
  vll d(n);
  vll c(d);
  forn(i, n) {
    d[i] = nxt();
    c[i] = nxt();
  }
  ll ans = 0;

  int N = 1;//2 * n + 1;
  while (N < 2 * n + 1) N <<= 1;

  vector <data> t(2 * N);

  forn(i, n) {
    t[N + 2 * i] = data(a - c[i]);
  }
  for (int i = N - 1; i > 0; --i) {
    t[i] = t[i + i] + t[i + i + 1];
  }

  vi o(n - 1);
  iota(all(o), 0);
  sort(all(o), [&](int a, int b) {return d[a + 1] - d[a] < d[b + 1] - d[b];});

  ans = max(ans, t[1].ans);
  cerr << ans << "\n";

  for (int pos : o) {
    int p = 2 * pos + 1 + N;
    t[p] = data(0ll);
    for (p >>= 1; p; p >>= 1) {
      t[p] = t[p + p] + t[p + p + 1];
//      cerr << "! " << p << " " << t[p].L << " " << t[p].R << " " << t[p].S << " " << t[p].ans << "\n";
    }
//    cerr << pos << " " << sqr(d[pos + 1] - d[pos]) << " " << t[1].ans << "\n";

    ans = max(ans, t[1].ans - sqr(d[pos + 1] - d[pos]));
  }

  cout << ans << "\n";
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
  cerr << "OK" << endl;
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