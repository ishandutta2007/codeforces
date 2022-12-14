#include <cstring>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
long long x,y,c;
int n;
bool check(unsigned long long m)
{
    unsigned long long num=(m+1)*(m+1)+m*m;
    long long L,U,D,R,UR,DR,UL,DL;
    R=m+y-n;
    if (R>0)
        num-=R*R;
    L=-(y-m-1);
    if (L>0)
        num-=L*L;
    U=-(x-m-1);
    if (U>0)
        num-=U*U;
    D=m+x-n;
    if (D>0)
        num-=D*D;
    DR=m-(2*(n+1)-x-y)+1;
    if (DR>0)
        num+=(DR*(DR+1))/2;
    UR=m-(x+n+1-y)+1;
    if (UR>0)
        num+=(UR*(UR+1))/2;
    UL=m-(y+x)+1;
    if (UL>0)
        num+=(UL*(UL+1))/2;
    DL=m-(y+n+1-x)+1;
    if (DL>0)
        num+=(DL*(DL+1))/2;
    return num>=c;
}
unsigned long long bs(unsigned long long l,unsigned long long r)
{
    long long ans=-1;
    while(l<=r)
    {
        unsigned long long mid=(l+r)/2;
        if (check(mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;

    }
    return ans;
}
int main()
{
    cin>>n>>x>>y>>c;
    check(1);
    if (c==1)cout<<0<<endl;
    else cout<<bs(1,2000000000LL)<<endl;
}