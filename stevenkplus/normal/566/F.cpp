#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1000100;
int ar[MAXN];
int dp[MAXN];

#define sz(x) int((x).size())
int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", ar + i);
  }

  sort(ar, ar + n);

  int ans = 0;
  for(int i = 0; i < n; ++i) {
    int x = ar[i];
    dp[x] += 1;
    if (dp[x] > ans) ans = dp[x];

    for(int j = x; j < MAXN; j += x) {
      if (dp[x] > dp[j]) {
        dp[j] = dp[x];
      }
    }

  }

  printf("%d\n", ans);
  return 0;
}