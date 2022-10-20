#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
#include <random>
#include <chrono>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

using ll = long long;
using ull = unsigned long long;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  read(n);
  vector<int> a(n);
  for (int &x : a)
    read(x);
  int mx = a[n - 1];
  a.erase(unique(all(a)), end(a));
  vector<int> b = a;
  shuffle(all(b), rng);

  auto chk = [&](ll dlt) {
    for (ll v : b) {
      v += dlt;
      ll x = sqrt((double)v);
      if (v > x * (x + 1)) return;
    }
    printf("%lld\n", dlt);
    exit(0);
  };

  static ll can[4000005];
  int cc = 1; *can = 0;
  for (int i = 1; i <= mx; ++i) {
    ll v = (ll)i * i - a[0];
    if (v > 0) can[cc++] = v;
  }
  int DIFF = 0;
  for (int i = 1, li = a.size(); i < li; ++i) {
    DIFF += max(0, a[i] - a[i - 1]);
    for (int j = 1; j <= a[i] - a[i - 1]; ++j) {
      ll v = (ll)j * j - a[i];
      if (v > 0) can[cc++] = v;
    }
  }
  sort(can, can + cc);
  cc = unique(can, can + cc) - can;

  for (int i = 0; i < cc; ++i)
    chk(can[i]);
  return 0;
}