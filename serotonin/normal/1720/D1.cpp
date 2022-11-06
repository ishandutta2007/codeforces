#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], dp[sz], trie[sz*31][2], val[sz*31][2];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   
   int k = 1;
   memset(trie[1], 0, sizeof(trie[1]));
   for(int i=n-1; i>=0; i--) {
      dp[i] = 0;
      int x = a[i], y = i;
      for(int j=29, u=1; j>=0 and u; j--) {
         int d = x >> j & 1;
         d = d << 1 | (y >> j & 1);
         {
            d ^= 1;
            int v = trie[u][min(d, d ^ 3)];
            dp[i] = max(dp[i], val[v][d & 1]);
            d ^= 1;
         }
         u = trie[u][min(d, d ^ 3)];
      }
      dp[i]++;
      
      swap(x, y);
      for(int j=29, u=1; j>=0; j--) {
         int d = x >> j & 1;
         d = d << 1 | (y >> j & 1);
         int &v = trie[u][min(d, d ^ 3)];
         if(!v) {
            v = ++k;
            memset(trie[k], 0, sizeof(trie[k]));
            memset(val[k], 0, sizeof(val[k]));
         }
         u = v;
         val[u][d & 1] = max(val[u][d & 1], dp[i]);
      }
   }
   printf("%d\n", *max_element(dp, dp + n));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}