#include <bits/stdc++.h>
using namespace std;

long long a[1001][1001];

int main() {
  ///freopen("2.in", "r", stdin);
  int n;
  scanf("%d", &n);
  for(int i = 0; i <n  ;i ++) for(int j = 0; j < n; j ++) scanf("%I64d", &a[i][j]);
  if(n == 1) return puts("1");
  int X, Y;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) if(a[i][j] == 0) X = i, Y = j;
  }
  long long sum = 0;
  for(int i = 0; i < n; i ++) if(i != X) {
    for(int j = 0; j < n; j ++) sum += a[i][j];
    break;
  }
  long long res = 0;
  for(int i = 0; i < n; i ++) if(i != Y) res += a[X][i];
  if(res >= sum) return puts("-1");
  a[X][Y] = sum - res;
  for(int i = 0; i < n; i ++) {
    long long pre = 0;
    for(int j = 0; j < n; j ++) pre += a[i][j];
    if(pre != sum) return puts("-1");
    pre = 0;
    for(int j = 0; j < n; j ++) pre += a[j][i];
    if(pre != sum) return puts("-1");
  }
  res = 0;
  for(int i = 0; i < n; i ++) res += a[i][i];
  if(res != sum) return puts("-1");
  res = 0;
  for(int i = 0; i < n; i ++) res += a[i][n-1-i];
  if(res != sum) return puts("-1");
  printf("%I64d\n", a[X][Y]);
}