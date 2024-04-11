#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int bigp=1000000007;

int w,h,ans,p1,p2,t,ans1,cs;
int vi[5],vj[5],k[5],ji[10000];

int doit(int x,int y)
{
    int ansc=0,xc,yc,xd,yd;
    for (int i=1;i<=4;i++)
        for (int j=i;j<=4;j++)
        {
            xc=abs(x-vi[i]);
            yc=abs(y-vj[i]);
            xd=abs(x-vi[j]);
            yd=abs(y-vj[j]);
            if ((xc*yd-xd*yc)%2==0)
            {
                if (i==j) ansc=(ansc+((LL)k[i]*(k[i]-1)/2))%bigp; else ansc=(ansc+((LL)k[i]*k[j]))%bigp;
            }
        }
    return ansc;
}

int gcd(int a,int b)
{
    if (b==0) return a; else return gcd(b,a%b);
}

int main()
{
    vi[1]=1;vj[1]=1;
    vi[2]=1;vj[2]=0;
    vi[3]=0;vj[3]=1;
    vi[4]=0;vj[4]=0;
    //freopen("D.in","r",stdin);
    cin>>w>>h;
    ans=0;
    p1=(h+1)/2;
    p2=h/2+1;
    ji[0]=0;
    for (int i=1;i<=w;i++) ji[i]=ji[i-1]+i%2;
    for (int i=0;i<w;i++)
    {
        k[1]=(ji[w]-ji[i])*p1;
        k[2]=(ji[w]-ji[i])*p2;
        k[3]=((w-i)-(ji[w]-ji[i]))*p1;
        k[4]=((w-i)-(ji[w]-ji[i]))*p2;
        if (i%2==0)
        {
            ans=(ans+(LL)p1*doit(0,1)%bigp)%bigp;
            ans=(ans+(LL)p2*doit(0,0)%bigp)%bigp;
        }
        else
        {
            ans=(ans+(LL)p1*doit(1,1)%bigp)%bigp;
            ans=(ans+(LL)p2*doit(1,0)%bigp)%bigp;
        }
    }
    for (int i=0;i<w;i++)
        for (int j=1;j<=h;j++)
        {
            if (j%2==1) t=(w-i)/2; else t=w-i;
            ans=(ans+(LL)(h-j+1)*t*(h+1)%bigp)%bigp;
        }
    ans1=0;
    for (int i=1;i<=w;i++)
        for (int j=0;j<=h;j++)
            if ((i!=0)||(j!=0))
            {
                cs=gcd(i,j);
                t=(LL)((LL)(w-i+1)*(h-j+1)%bigp)*(cs-1)%bigp;
                if (i*j!=0) t*=2;
                ans1=(ans1+(t%bigp))%bigp;
            }
    ans=(ans-ans1+bigp)%bigp;
    cout<<((LL)ans*6)%bigp<<endl;
    return 0;
}