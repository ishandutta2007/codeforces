#include <bits/stdc++.h>
using namespace std;
#define sz(c) (int)(c).size()
#define pb push_back
void mx(int& a, int x) {
  if (a < x) {
    a = x;
  }
}
const int M = (int)1e6;
const int maxn = (int)5e4;
const int maxm = (int)5e3;
int f[M + 2];
int a[maxn];
int F1[maxn];
int F2[maxn];
int l[maxm];
int r[maxm];
int ans[maxm];
vector<int> ls[maxn];
int dp[maxn];
int n, m;
int main(){
  f[0] = 0;
  for (int i = 1; i <= M; i++) {
    f[i] = f[i - 1] ^ i;
  }
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    F1[i] = f[a[i]];
    F2[i] = f[a[i] - 1];
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &l[i], &r[i]);
    l[i]--;
    r[i]--;
    ls[l[i]].pb(i);
  }
  for (int i = n - 1; i >= 0; i--) {   
    dp[i] = a[i];
    for (int j = i + 1; j < n; j++) {
      mx(dp[j], max(dp[j - 1], a[j] < a[i] ? F2[j] ^ F1[i] : F1[j] ^ F2[i]));
    }
    for (int j = 0; j < sz(ls[i]); j++) {
      ans[ls[i][j]] = dp[r[ls[i][j]]];
    }
  }
  for (int i = 0; i < m; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}