#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}

template <typename T> inline bool CheckMax(T &a, const T &b) {
  return a < b ? a = b, true : false;
}

template <typename T> inline bool CheckMin(T &a, const T &b) {
  return a > b ? a = b, true : false;
}

const int N = 200005;

vector <int> a[N];
queue <int> p, q;
char s[N];
int n, m;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  scanf("%s", s + 1), n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0') {
      ++m;
    } else {
      --m;
    }
  }
  if (m <= 0) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    p.push(i);
  }
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '0') {
      if (p.empty()) {
        puts("-1");
        return 0;
      }
      a[p.front()].pb(i), q.push(p.front()), p.pop();
    } else {
      if (q.empty()) {
        puts("-1");
        return 0;
      }
      a[q.front()].pb(i), p.push(q.front()), q.pop();
    }
  }
  printf("%d\n", m);
  for (int i = 1; i <= m; ++i) {
    printf("%d", a[i].size());
    for (auto x : a[i]) {
      printf(" %d", x);
    }
    putchar(10);
  }
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}