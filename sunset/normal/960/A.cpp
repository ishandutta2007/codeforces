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

const int N = 5005;

char s[N];
int n;

int main() {
#ifdef wxh010910
  freopen("d.in", "r", stdin);
#endif
  scanf("%s", s), n = strlen(s);
  int cur = 0, cnt[3] = {0, 0, 0};
  for (int i = 0; i < n; ++i) {
    if (!i || s[i] != s[i - 1]) {
      if (s[i] != cur + 'a') {
        puts("NO");
        return 0;
      }
      ++cur;
    }
    ++cnt[s[i] - 'a'];
  }
  if (cur != 3 || (cnt[0] != cnt[2] && cnt[1] != cnt[2])) {
    puts("NO");
    return 0;
  }
  puts("YES");
#ifdef wxh010910
  Debug("My Time: %.3lfms\n", (double)clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}