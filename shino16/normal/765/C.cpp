#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int k, a, b;
int main() {
  scanf("%d%d%d", &k, &a, &b);
  if ((a < k && b % k != 0) || (b < k && a % k != 0)) printf("-1\n");
  else printf("%d\n", a / k + b / k);
}