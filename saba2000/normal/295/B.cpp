#include<bits/stdc++.h>
using namespace std;
int n;
int a[600][600];
long long An[1009];
int x[1009];
int d[600][600];
vector<int> X;
main()
{int n;
cin>>n;
for (int i=1; i<=n; i++)
for (int j=1; j<=n; j++)
 cin>>a[i][j];   
for (int i=0; i<n; i++)
cin>>x[i];
for (int i=0; i<=n; i++)
for (int j=0; j<=n; j++)
    d[i][j]=a[i][j];

for (int i=n-1; i>=0; i--)
{
   for (int j=1; j<=n; j++)
   for (int k=1; k<=n; k++)
   d[j][k]=min(d[j][k],d[j][x[i]]+d[x[i]][k]);
   long long  ans=0;
   for (int j=i; j<n; j++)
   for (int k=i; k<n; k++)
   ans+=d[x[j]][x[k]];
   An[i]=ans;
}
for (int i=0; i<n; i++)
cout<<An[i]<<endl;

}