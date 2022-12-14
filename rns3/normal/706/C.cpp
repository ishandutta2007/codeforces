#include <bits/stdc++.h>
using namespace std;

const int M = 200001;

int a[M];
string s[M], ss[M];

long long f[M][3];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i ++) scanf("%d", a + i);
  for(int i = 0; i < n; i ++) cin >> s[i];
  for(int i = 0; i < n; i ++) {
    ss[i] = s[i];
    reverse(ss[i].begin(), ss[i].end());
  }
  f[0][0] = 0;
  f[0][1] = a[0];
  for(int i = 1; i < n; i ++) {
    f[i][0] = f[i][1] = 1e18;
    if(s[i] >= s[i-1]) f[i][0] = min(f[i][0], f[i-1][0]);
    if(s[i] >= ss[i-1]) f[i][0] = min(f[i][0], f[i-1][1]);
    if(ss[i] >= s[i-1]) f[i][1] = min(f[i][1], f[i-1][0] + a[i]);
    if(ss[i] >= ss[i-1]) f[i][1] = min(f[i][1], f[i-1][1] + a[i]);
  }
  long long ans = min(f[n-1][0], f[n-1][1]);
  if(ans == 1e18) puts("-1");
  else printf("%I64d\n", ans);
}