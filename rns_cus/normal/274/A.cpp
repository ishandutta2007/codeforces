#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;

#define N 100100
#define inf 1000000007

int n, a[N], vis[N], k;

int main() {
  scanf("%d%d", &n, &k);
  if(k == 1) {
    printf("%d\n", n); return 0;
  }
  for(int i = 1; i <= n; i ++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  for(int i = 1; i <= n; i ++) mp[a[i]] = i;
  int ans = 0;
  for(int i = 1; i <= n; i ++) if(!vis[i]) {
    int x = a[i], c = 1;
    while(1) {
      if(1LL * x * k > inf) break;
      x *= k;
      if(mp.count(x)) {
        vis[mp[x]] = 1;
        c ++;
      } else break;
    }
    ans += (c + 1) >> 1;
  }
  cout << ans << endl;
  return 0;
}