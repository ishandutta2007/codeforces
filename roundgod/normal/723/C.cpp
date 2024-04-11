#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#define MAXN 2005
#define INF 100000000
using namespace std;
int a[MAXN],b[MAXN],n,m,cnt;
int main()
{
   scanf("%d%d",&n,&m);
   memset(b,0,sizeof(b));
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
       if (a[i]<=m) b[a[i]]++;
   }
   printf("%d ",n/m);
   cnt=0;
   int p=n/m;
   for(int i=1;i<=m;i++)
   {
       while(b[i]<p)
       {
           for(int j=0;j<n;j++)
           {
               if(a[j]>m||b[a[j]]>p)
               {
                   cnt++;
                   b[i]++;
                   if(a[j]<=m) b[a[j]]--;
                   a[j]=i;
                   break;
               }
           }
       }
   }
   printf("%d\n",cnt);
   for(int i=0;i<n;i++)
      printf("%d ",a[i]);
   return 0;
}