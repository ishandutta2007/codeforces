#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <LL, LL> pll;
map <pll, int> mp;

bool dfs(LL a, LL b) {
  if (a > b) swap(a, b);
  if (!a) return 0;
  if (a == 1) return 1;
  if (!dfs(b % a, a)) return 1;
  if (((b / a) % (a + 1)) & 1) return 0;
  return 1;
}

int main() {
  //freopen("in.txt", "r", stdin);
  int T;
  LL a, b;
  for (scanf("%d", &T); T--; ) {
    scanf("%I64d %I64d", &a, &b);
    if (dfs(a, b)) puts("First");
    else puts("Second");
  }
}