#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n1, n2, m;
    vector<int> a, b;
    read(n1); a.resize(n1);
    read(m);
    for (int &x : a)
      read(x);
    read(n2); b.resize(n2);
    for (int &x : b)
      read(x);

    using pii = pair<int, ll>;

    auto expand = [&](const vector<int> &a) {
      vector<pii> ans;
      for (int x : a) {
        int c = 1;
        while (x % m == 0) x /= m, c *= m;
        if (!ans.empty() && ans.back().first == x) ans.back().second += c;
        else ans.emplace_back(x, c);
      }
      return ans;
    };
    puts(expand(a) == expand(b) ? "Yes" : "No");
  }
  return 0;
}