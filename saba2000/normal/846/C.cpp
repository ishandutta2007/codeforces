#include<bits/stdc++.h>
using namespace std;
int n;
long long p[10009];
main()
{cin>>n;
p[0]=0;
for (int i=0;i<n; i++)
{
    int a;cin>>a; p[i+1]=p[i]+a;
}
long long ans=0,X=0,Y=0,Z=0;
for (int x=0; x<=n; x++)
{
    long long z=p[x],r=x;
    for (int y=x; y<=n; y++)
    {
        if(p[y]<z){z=p[y]; r=y;}
        if(p[x]-p[r]+p[y]>ans) {ans=p[x]-p[r]+p[y]; X=x; Y=r; Z=y;}
    }
}
cout<<X<<" "<<Y<<" "<<Z<<endl;
//s(0,x-1)-s(x+1,y)+s(y+1,z)-s(z+1,n)
//p[x]-(p[y]-p[x])+(p[z]-p[y])-(p[n]-p[z])
//p[x-1]-p[y-1]+p[z-1]
}