#include <bits/stdc++.h>
using namespace std;
#define N 200200

vector <int> v;
int n, sum, a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum += a[i];
  for (int i = 1; i <= n; i ++) {
    if (sum == a[i] * n) v.push_back(i);
  }
  printf("%d\n", v.size());
  if (!v.size()) return 0;
  for (int i = 0; i < v.size(); i ++) printf("%d ", v[i]); puts("");
  return 0;
}