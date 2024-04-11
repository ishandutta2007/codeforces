#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5, bsz = 1e5+5;

int a[sz], ans[sz];
bool vis[sz], done[sz];
bitset <bsz> fk;

int main()
{
   int n;
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=1; i<=n; i++) {
      if(a[i] > a[i-1]) {
         ans[i] = a[i-1];
         done[i] = 1;
      }
      vis[a[i]] = 1;
   }

   for(int i=1, k=1; i<=n; i++) {
      if(done[i]) continue;
      while(vis[k]) k++;
      ans[i] = k;
      vis[k] = 1;
   }

   fk.set();
   for(int i=1; i<=n; i++) {
      if(ans[i] < bsz) fk[ans[i]] = 0;
      int x = fk._Find_first();
      if(a[i] ^ x) {
         puts("-1");
         exit(0);
      }
   }

   for(int i=1; i<=n; i++) printf("%d ", ans[i]);
}