#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int answer[] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  if (n < 12) {
    printf("%d\n", answer[n]);
  } else {
    printf("%lld\n", 49ll * (n - 11) + answer[11]);
  }
  return 0;
}