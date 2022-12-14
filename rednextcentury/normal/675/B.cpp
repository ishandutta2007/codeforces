
#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
    long long a,b,c,d,x,y,z,w,u;
    long long n;
    cin>>n>>a>>b>>c>>d;
    long long ret=0;
    for (x=1;x<=n;x++)
    {
        y = a+x+b-c-a;
        u = a+y+c-c-d;
        w = a+b+x-b-d;
        /*int p = min(y,min(u,w));
        if (p<0)
            z = -p+1;
        else
            z=1;
        y+=z;
        u+=z;
        w+=z;*/
        if (y>=1 && w>=1 && u>=1)
        if (y<=n && w<=n && u<=n)
            ret+=n;
    }
    cout<<ret<<endl;
}