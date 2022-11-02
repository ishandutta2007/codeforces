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

template <typename c_type, typename o_type>
o_type get_count(c_type A, c_type B, o_type C, o_type X);

template <typename o_type>
inline o_type s1(o_type X) {
  if (X % 2 == 0) {
    return X / 2 * (X + 1);
  } else {
    return (X + 1) / 2 * X;
  }
}

// A * x + B * y <= C
// 0 <= x <= X
template <typename c_type, typename o_type>
inline o_type get_count(c_type A, c_type B, o_type C) {
  assert(A > 0 && B > 0);
  if (C < 0) return 0;
  if (A < B) swap(A, B);

  const c_type U = A / B;
  const c_type V = A % B;

  return get_count(V, B, C, C / A) - U * s1(C / A);
}


// A * x + B * y <= C
// 0 <= x <= X
template <typename c_type, typename o_type>
inline o_type get_count(c_type A, c_type B, o_type C, o_type X) {
  assert(B > 0 && A >= 0);

  if (C < 0) return 0;
  if (A == 0) {
    return (C / B + 1) * (X + 1);
  }

  if (C / A <= X) {
    return get_count(A, B, C);
  }

  o_type Y = (C - A * X) / B;
  C -= Y * B;
  assert(A * X + B > C);

  return (X + 1) * Y + get_count(A, B, C) - max(o_type(0), C / A - X);
}

// A * x + B * y <= C
// 0 <= x <= X, 0 <= y <= Y
template <typename c_type, typename o_type>
o_type get_count(c_type A, c_type B, o_type C, o_type X, o_type Y) {
  assert(A >= 0 && B >= 0);
  if (C < 0) return 0;

  if (A == 0 || B == 0) {
    if (A) X = min(X, C / A);
    if (B) Y = min(Y, C / B);
    return (X + 1) * (Y + 1);
  }

  if (C / A > X && C / B > Y) {
    return get_count(A, B, C, X) + get_count(B, A, C, Y) - get_count(A, B, C) + get_count(A, B, C - A * (X + 1) - B * (Y + 1));
  }
  if (C / A > X) {
    return get_count(A, B, C, X);
  }
  if (C / B > Y) {
    return get_count(B, A, C, Y);
  }

  return get_count(A, B, C);
}



void solve(int) {
  int n = nxt();
  cerr << "OK" << endl;
  vi a(n);
  forn(i, n) a[i] = nxt();
  cerr << "OK" << endl;
  const int N = 100001;
  vll counts(N + 1);

  map <int, int> c;

  for (int i = 0; i < n; ++i) {
    c[0] += 1;
    map <int, int> nc;

    for (auto kv : c) {
      int nk = gcd(kv.x, a[i]);
      nc[nk] += kv.y;
      counts[nk] += kv.y;
    }
    assert(nc.size() < 100);
    nc.swap(c);
  }


  vector <ll> psum0(N + 1);
  vector <ll> psum1(N + 1);
  vector <int> values(N);
  forn(i, N) {
    values[i] = i;
  }

  for (int i = 1; i < N; ++i) {
    psum0[i] = psum0[i - 1] + counts[i];
    psum1[i] = psum1[i - 1] + counts[i] * values[i];
  }

  auto get = [&](ll v) {
    long long res = 0;

    for (int i = 1, r = 1; i < N; ++i, r = max(r, i)) {
      for (ll rem = counts[i]; rem > 0; ) {
        while (r < N && rem * values[i] + psum1[r] - psum1[i] <= v) {
          r++;
        }
        if (i == r) {
//          assert(false);
          ll q = v / values[i];
          assert(q <= rem);
          ll nrem = q;
          assert(nrem < rem);
          res += (rem - nrem) * q;
          rem = nrem;

          assert(rem * values[i] + psum1[r] - psum1[i] <= v);
          continue;
        }
        if (r == N) {
          res += rem * (psum0[r - 1] - psum0[i]) + rem * (rem + 1) / 2;
          rem = 0;
          continue;
        }

        assert(v - rem * values[i] - (psum1[r - 1] - psum1[i]) >= 0);

        auto C = v - (psum1[r - 1] - psum1[i]);
        auto A = values[i];
        auto B = values[r];

        assert(C >= 0);

        ll minx = max(1ll, (C - B * counts[r]) / A);
        ll maxx = rem;

        assert(minx <= maxx);
        assert(A * maxx <= C);

        ll maxy = counts[r];

        ll solutions = get_count(A, B, C, maxx, maxy) - get_count(A, B, C, minx - 1, maxy);

        res += solutions + (maxx - minx + 1) * (psum0[r - 1] - psum0[i]) + (maxx + minx - 2) * (maxx - minx + 1) / 2;
        rem = minx - 1;

        assert(rem == 0 || rem * values[i] + psum1[r] - psum1[i] <= v);
      }
    }
    return res;
  };

  ll l = 0, r = psum1[N - 1];

  ll expectedLen = n * (n + 1ll) / 2;
  expectedLen = expectedLen * (expectedLen + 1) / 2;

  assert(get(r) == expectedLen);

  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (get(m) < (expectedLen + 1) / 2) {
      l = m;
    } else {
      r = m;
    }
  }
  assert(get(l) < (expectedLen + 1) / 2);
  assert(get(r) >= (expectedLen + 1) / 2);
  cout << r << "\n";
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