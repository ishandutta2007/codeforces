#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL m;

LL calc(LL v) {
  LL sum = 0;
  for (int k = 2; k; k++) {
    LL t = 1LL * k * k * k;
    if (t > v) break;
    sum += (v / t);
  }
  return sum;
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%I64d", &m);
  LL l = 1, r = 10 * m;
  while (l < r) {
    LL mid = (l + r) >> 1;
    if (calc(mid) >= m) r = mid;
    else l = mid + 1;
  }
  if (calc(l) == m) cout << l << endl;
  else puts("-1");
}