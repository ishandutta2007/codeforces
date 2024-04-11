#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

char s[sz];
int a[sz], d[sz];

int main()
{
   int t;
   cin >> t;
   while(t--) {
      int n;
      scanf("%d %s", &n, s);
      for(int i=0; i<n; i++) a[i]=s[i]-'0';
      bool yes=0;

      for(int i=0; i<10 && !yes; i++) {
         for(int j=0; j<n; j++) d[j]=0;

         int x=0;
         for(int j=0; j<n; j++) {
            if(a[j]<i) {
               if(a[j]<x) {
                  x=-1;
                  break;
               }
               d[j]=1, x=a[j];
            }
         }

         if(x<0) continue;

         int y=i;
         for(int j=0; j<n; j++) {
            if(a[j]>i) {
               if(a[j]<y) {
                  y=-1;
                  break;
               }
               d[j]=2, y=a[j];
            }
         }

         if(y<0) continue;

         for(int j=0; j<n; j++) {
            if(a[j]==i) d[j]=2;
            if(a[j]>i) break;
         }

         for(int j=n-1; j>=0; j--) {
            if(a[j]==i) d[j]=1;
            if(a[j]<i) break;
         }

         yes=1;
         for(int j=0; j<n; j++) {
            if(!d[j]) {
               yes=0;
               break;
            }
         }
      }

      if(!yes) puts("-");
      else {
         for(int j=0; j<n; j++) printf("%d", d[j]);
         puts("");
      }
   }
}