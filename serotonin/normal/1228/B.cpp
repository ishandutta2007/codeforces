#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e3+5, p=1e9+7;

int r[sz], c[sz];

int main()
{
   int h,w;
   cin >> h >> w;
   for(int i=1; i<=h; i++) scanf("%d", &r[i]);
   for(int i=1; i<=w; i++) scanf("%d", &c[i]);

   int cnt=0;
   for(int i=1; i<=h; i++) {
      for(int j=1; j<=w; j++) {
         if(r[i]>=j && c[j]+1==i) {
            puts("0");
            return 0;
         }
         if(c[j]>=i && r[i]+1==j) {
            puts("0");
            return 0;
         }
         if(r[i]+1<j && c[j]+1<i) cnt++;
      }
   }

   ll ans=1;
   for(int i=0; i<cnt; i++) {
      ans=(ans<<1)%p;
   }
   cout << ans << endl;
}