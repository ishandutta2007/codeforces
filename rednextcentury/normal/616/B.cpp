#include <iostream>

using namespace std;
int a[1000][1000];
int main()
{
   int n,m;
   cin>>n>>m;
   int ans=0;
   for (int i=0;i<n;i++)
   {
       int mn=1000000000;
       for (int j=0;j<m;j++)
       {
           cin>>a[i][j];
           mn=min(mn,a[i][j]);
       }
       ans=max(ans,mn);
   }
   cout<<ans<<endl;
}