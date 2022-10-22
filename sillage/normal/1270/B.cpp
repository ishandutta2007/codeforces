#include<bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main(){
   int T;
   scanf("%d",&T);
   while (T--){
      int n;
      scanf("%d",&n);
      for (int i=1; i<=n; i++) scanf("%d",&a[i]);
      for (int i=1; i<=n; i++) b[i]=a[i]-i;
      int mx=-10-n,p,flag=0;
      for (int i=n; i>=1; i--){
         if (mx>b[i]){
            printf("YES\n");
            printf("%d %d\n",i,p);
            flag=1;
            break;
         }
         if (b[i]>mx){
            mx=b[i];
            p=i;
         }
      }
      if (flag) continue;
      for (int i=1; i<=n; i++) b[i]=a[i]+i;
      mx=-1,p,flag=0;
      for (int i=1; i<=n; i++){
         if (mx>b[i]){
            printf("YES\n");
            printf("%d %d\n",p,i);
            flag=1;
            break;
         }
         if (b[i]>mx){
            mx=b[i];
            p=i;
         }
      }
      if (flag) continue;
      puts("NO");
   }
}