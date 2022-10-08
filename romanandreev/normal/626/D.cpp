#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
const int maxc = 5010;
int n;
int a[maxn];
int k = 0;
double pl[maxc];
double pl2[maxc];
int main(){
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  int zn = n * (n - 1) / 2;
  int mx = a[n - 1] - a[0];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      pl[a[j] - a[i]]++;
    }
  }
  for (int i = 0; i <= mx; i++) {
    pl[i] /= zn;
  }  
  for (int i = 0; i <= mx; i++) if (pl[i] > 0) {
    if (i * 2 <= mx)
      pl2[i * 2] += pl[i] * pl[i];
    for (int j = i + 1; i + j <= mx; j++) {
      pl2[i + j] += 2 * pl[i] * pl[j];
    }
  }
  for (int i = 1; i <= mx; i++) {
    pl2[i] += pl2[i - 1];
  }
  double ans = 0;
  for (int i = 1; i <= mx; i++) {
    ans += pl2[i - 1] * pl[i];
  }
  printf("%.18lf\n", ans);
  return 0;
}