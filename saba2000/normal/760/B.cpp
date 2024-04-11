#include<bits/stdc++.h>
using namespace std;		
long long n,m,k;
main()
{cin>>n>>m>>k;
long long x=0,y=m;
while(x<y)
{long long z=(x+y+1)/2;
long long p,q,z1,k1;
if (z<k) p=(k-z)+z*(z+1)/2;
else p=k*(2*z-k+1)/2;
k1=n-k;
z1=z-1;
if (z1<k1) q=(k1-z1)+z1*(z1+1)/2;
else q=k1*(2*z1-k1+1)/2;
if (p+q<=m) x=z;
else y=z-1;
}
cout<<x<<endl;
	
}