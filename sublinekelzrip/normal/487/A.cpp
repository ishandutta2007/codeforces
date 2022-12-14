#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int main()
{
    int hy,ay,dy,hm,am,dm,h,a,d,ans=inf;
    cin>>hy>>ay>>dy>>hm>>am>>dm>>h>>a>>d;
    int p=max(0,(dm+hm)-ay),q=max(0,am-dy);
    for(int i=0;i<=p;i++)
    {
        int aa=ay+i;
        if(aa<=dm)
            continue;
        int ti=hm/(aa-dm);
        if(hm%(aa-dm)!=0)
            ti++;
        for(int j=0;j<=q;j++)
        {
            int z=dy+j;
            int pi;
            if(z>=am)
                pi=0;
            else
                pi=am-z;
            int f=pi*ti;
            if(hy<=f)
                ans=min(ans,i*a+j*d+(f-hy+1)*h);
            else
                ans=min(ans,i*a+j*d);
        }
    }
    cout<<ans<<endl;
}