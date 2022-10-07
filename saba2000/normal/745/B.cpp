#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
char a[1009][1009];
int p=100000,q=100000,r,t;
int ans;
main()
{int n,m;
cin>>n>>m;
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
{cin>>a[i][j];
}
for (int i=0; i<n; i++)
for (int j=0; j<m; j++)
if (a[i][j]=='X') {p=min(p,i); q=min(q,j); r=max(r,i); t=max(t,j);}
//cout<<p<<" "<<q<<" "<<r<<" "<<t<<endl;
for (int i=p; i<=r; i++)
for (int j=q; j<=t; j++)
if (a[i][j]=='.') {cout<<"NO"<<endl; return 0;}
cout<<"YES"<<endl;
}