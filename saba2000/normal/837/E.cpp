#include<bits/stdc++.h>
using namespace std;
long long x,y,c,a,b,z,j;
main()
{
   cin>>x>>y;
   while(y)
   {
    b=__gcd(x,y),x/=b,y/=b,z=y;
    for (j=1;j*j<=x;j++)
    {
        a=j,b=x/j;
        if(a>1 && !(x%a)) z=min(z,y%a);
        if(b>1 && !(x%b)) z=min(z,y%b);
    }
    c+=z,y-=z;
    }
    cout<<c;
}