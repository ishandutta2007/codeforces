#include<iostream>
using namespace std;
long long n,a[1002][1002],x,y,s,t,r,m,ans;
main()
{cin>>n;
for (int i=0; i<n; i++)
{cin>>x>>y;
a[x][y]=1;
}
for (int i=1; i<=1000; i++)
{s=0; t=0; m=0; r=0;
int p=1,q=i;
for (int j=i; j<=1000; j++)
{if (a[p][q]==1) s++;
if (a[q][p]==1 && i!=1) m++;
p++; q++;}
p=1; q=i;
for (int j=i; j>=1; j--)
{if (a[p][q]==1) t++;
if (a[1001-q][1001-p]==1 && i!=1000) r++;
p++; q--;}
ans+=t*(t-1)/2+s*(s-1)/2+m*(m-1)/2+r*(r-1)/2;
}
cout<<ans<<endl;
}/*
5
1 1
1 5
3 3
5 1
5 5*/