#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
const int maxn = 204;
const int maxc = 504;
const int maxk = 1004;
const int md = (int)1e9 + 7;
int n, k;
int a[maxn];
int mul(int x, int y) {
  return int(((ll)x * y) % md);
}
void add(int& x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}
int dp[2][maxn / 2][maxk];
int main(){
  #ifdef home
  assert(freopen("a.out","wt",stdout));
  assert(freopen("a.in","rt",stdin));
  #endif              
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    a[i] -= a[i + 1];
  }
  dp[0][0][0] = 1;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int ncur = cur ^ 1;
    for (int bal = 0; bal <= min(i + 1, n - i - 1); bal++) {
      memset(dp[ncur][bal], 0, sizeof(dp[ncur][bal]));
    }
    for (int bal = 0; bal <= min(i, n - i); bal++) {
      for (int sum = 0; sum <= k; sum++) {
        int val = dp[cur][bal][sum];
        if (val == 0) continue;
        int gg = sum + a[i] * bal;
        int ff = k - gg;
        if (a[i] <= ff)
          add(dp[ncur][bal + 1][gg + a[i]], val);
        if (0 <= ff)  
          add(dp[ncur][bal][gg], mul(val, bal + 1));
        if (bal > 0 && -a[i] <= ff) {
          add(dp[ncur][bal - 1][gg - a[i]], mul(val, bal));
        }      
      }
    }
    cur = ncur;
  }
  int res = 0;
  for (int i = 0; i <= k; i++) {
    add(res, dp[cur][0][i]);
  }
  cout << res << endl;
  return 0;
}