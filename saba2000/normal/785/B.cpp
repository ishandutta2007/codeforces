#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,x,y;
int main()
{cin>>n;
for (int i=0; i<n; i++)
{cin>>x>>y;
if (i==0) {a=x; b=y;}
a=max(a,x);
b=min(b,y);
}
cin>>m;
for (int i=0; i<m; i++)
{cin>>x>>y;
if (i==0) {c=x; d=y;}
c=max(c,x);
d=min(d,y);
}
cout<<max(0,max(c-b,a-d))<<endl;
}