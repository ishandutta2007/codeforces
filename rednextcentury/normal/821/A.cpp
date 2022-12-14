#include <bits/stdc++.h>
using namespace std;
int a[101][101];
bool col[101][100001];
bool row[101][100001];
int main()
{
   int n;
   cin>>n;
   for (int i=0;i<n;i++)
   {
       for (int j=0;j<n;j++)
       {
           cin>>a[i][j];
           row[i][a[i][j]]=1;
       }
   }
   for (int i=0;i<n;i++)
   {
       for (int j=0;j<n;j++)
       {
           if (a[i][j]==1)continue;
           int can=0;
           for (int x=0;x<n;x++)
           {
               if (a[x][j]<a[i][j] && row[i][a[i][j]-a[x][j]])
                can=1;
           }
           if (!can)
           {

                cout<<"NO"<<endl;
                return 0;
           }
       }
   }
   cout<<"YES"<<endl;
}