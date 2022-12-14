# include <iostream>
# include <stdio.h>
# include <map>
# include <algorithm>
# include <vector>
#define eps 1e-9
using namespace std;
int a[1000000];
int main()
{
   int n;
   cin>>n;
   int mx=0;int cur=0;
   for (int i=1;i<=n;i++)
   {
       cin>>a[i];
       if (a[i]>=a[i-1])
        cur++;
       else
       {
           mx=max(mx,cur);
           cur=1;
       }
   }
   mx=max(mx,cur);
   cout<<mx<<endl;
}