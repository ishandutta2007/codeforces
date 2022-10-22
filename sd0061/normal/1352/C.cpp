#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int m = n - 1;
    --k;
    int i = k / m;
    // cout << i << endl;
    k %= m;
    long long res = 1LL * i * n;
    printf("%lld\n", res + k + 1);
  }
}