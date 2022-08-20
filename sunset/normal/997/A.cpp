#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 300005;

int n, x, y;
char s[N];

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  scanf("%d %d %d %s", &n, &x, &y, s);
  int result = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      while (i < n && s[i] == '0') {
        ++i;
      }
      ++result;
    }
  }
  if (!result) {
    puts("0");
  } else {
    printf("%lld\n", (ll)min(x, y) * (result - 1) + y);
  }
  return 0;
}