#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)
#define DBG(f...) printf("%3d: ", __LINE__), printf(f)
// #define DBG(f...) void()
#define all(cont) begin(cont), end(cont)
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif

using ll = long long;

template <class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template <class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 200005;

int a[N];
struct frac {
  ll a, b;
  int id;
  bool operator>(const frac &r) const { return a * r.b > r.a * b; }
} b[N];
vector<int> item[N];
vector<int> ans[N];
int ok[N], oka[N], okd[N];

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int T;
  read(T);
  while (T--) {
    int n, m;
    read(n, m);
    for (int i = 1; i <= n; ++i)
      read(a[i]);
    sort(a + 1, a + 1 + n, greater<>());
    for (int i = 1; i <= m; ++i) {
      int cnt;
      read(cnt);
      item[i].resize(cnt);
      ans[i].resize(cnt);
      b[i].a = 0;
      for (int j = 0; j < cnt; ++j) {
        read(item[i][j]);
        b[i].a += item[i][j];
      }
      b[i].b = cnt;
      b[i].id = i;
    }
    sort(b + 1, b + 1 + m, greater<frac>());
    for (int i = 1; i <= m; ++i)
      ok[i] = b[i].a <= a[i] * b[i].b;
    oka[1] = ok[1];
    for (int i = 2; i <= m; ++i)
      oka[i] = b[i].a <= a[i - 1] * b[i].b;
    partial_sum(ok + 1, ok + 1 + m, ok + 1);
    // printf("ok[m] = %d\n", ok[m]);
    partial_sum(oka + 1, oka + 1 + m, oka + 1);
    okd[m] = 1;
    for (int i = 1; i < m; ++i)
      okd[i] = b[i].a <= a[i + 1] * b[i].b;
    partial_sum(okd + 1, okd + 1 + m, okd + 1);
    for (int i = 1; i <= m; ++i) {
      int id = b[i].id;
      // LOG("i = %d id = %d\n", i, id);
      for (int j = 0, li = item[id].size(); j < li; ++j) {
        frac f;
        f.a = b[i].a - item[id][j];
        f.b = b[i].b - 1;
        // LOG("%lld / %lld\n", f.a, f.b);
        if (f > b[i]) {
          if (ok[m] != m) ans[id][j] = 0;
          else {
            auto it = upper_bound(b + 1, b + 1 + m, f, greater<>()) - b;
            // printf("it = %ld\n", it);
            int sum = ok[it - 1];
            sum += (f.a <= a[it] * f.b);
            sum += okd[i - 1] - okd[it - 1];
            sum += ok[m] - ok[i];
            // printf("Add %d m = %d\n", ok[m] - ok[i], m);
            // printf("SUM = %d\n", sum);
            ans[id][j] = (sum == m);
          }
        }
        else {
          int sum = ok[i - 1];
          auto it = upper_bound(b + 1, b + 1 + m, f, greater<>()) - b;
          sum += oka[it - 1] - oka[i];
          sum += ok[m] - ok[it - 1];
          sum += f.a <= a[it - 1] * f.b;
          ans[id][j] = (sum == m);
          // printf("sum = %d\n", sum);
        }
      }
    }
    for (int i = 1; i <= m; ++i)
      for (int v : ans[i])
        printf("%d", v);
    puts("");
  }
  return 0;
}