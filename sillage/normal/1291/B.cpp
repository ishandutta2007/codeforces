#include<bits/stdc++.h>
using namespace std;
int T,n;
int f[300010],a[300010],g[300010];
int main(){
   scanf("%d",&T);
   while(T--){
       scanf("%d",&n); 
       for (int i=1; i<=n; i++) scanf("%d",&a[i]),f[i]=g[i]=0;
       for (int i=1; i<=n; i++) if (a[i]>=(i-1)) f[i]=1; else break;
       for (int i=n; i>=1; i--) if (a[i]>=(n-i)) g[i]=1; else break;
       int flag=0;
        for (int i=1; i<=n; i++) if (f[i]&&g[i]) flag=1;
    puts(flag?"Yes":"No");
   }
   return 0;
}