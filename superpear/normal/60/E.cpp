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
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int maxn=1000005;

struct matrix
{
    int a1,a2,b1,b2;
} f1,g1,v1[70],f2,g2,v2[70],f3,g3,v3[70],dw;

LL x,y,xbak;
int n,bigp,dao1,dao2,allsum,firstsum,tc,nowmax,anssum,a[maxn];

matrix m_m(int a,int b,int c,int d)
{
    matrix f;
    f.a1=a;f.a2=b;f.b1=c;f.b2=d;
    return f;
}

matrix times(matrix a,matrix b)
{
    matrix c;
    c.a1=((LL)a.a1*b.a1+(LL)a.b1*b.a2)%bigp;
    c.a2=((LL)a.a2*b.a1+(LL)a.b2*b.a2)%bigp;
    c.b1=((LL)a.a1*b.b1+(LL)a.b1*b.b2)%bigp;
    c.b2=((LL)a.a2*b.b1+(LL)a.b2*b.b2)%bigp;
    return c;
}

int main()
{
    //freopen("E.in","r",stdin);
    cin>>n>>x>>y>>bigp;
    xbak=x;
    for (int i=1;i<=n;i++) cin>>a[i];
    allsum=0;
    for (int i=1;i<=n;i++) allsum=((LL)allsum+a[i])%bigp;
    f1=m_m(3,-1,0,1);
    dw=m_m(1,0,0,1);
    v1[0]=f1;
    for (int i=1;i<=69;i++) v1[i]=times(v1[i-1],v1[i-1]);
    g1=dw;
    tc=62;
    while (x>0)
    {
        while (x<((LL)1<<tc)) --tc;
        g1=times(g1,v1[tc]);
        x-=(LL)1<<tc;
    }
    firstsum=((LL)allsum*g1.a1+(LL)(a[1]+a[n])*g1.a2)%bigp;
    //cout<<firstsum<<endl;
    f2=m_m(0,1,1,1);
    v2[0]=f2;
    for (int i=1;i<=69;i++) v2[i]=times(v2[i-1],v2[i-1]);
    g2=dw;
    tc=62;
    x=xbak;
    while (x>0)
    {
        while (x<((LL)1<<tc)) --tc;
        g2=times(g2,v2[tc]);
        x-=(LL)1<<tc;
    }
    dao2=((LL)a[n-1]*g2.a2)%bigp;
    dao1=((LL)a[n]*g2.b2)%bigp;
    nowmax=((LL)dao2+dao1)%bigp;
    f3=m_m(3,-1,0,1);
    dw=m_m(1,0,0,1);
    v3[0]=f3;
    for (int i=1;i<=69;i++) v3[i]=times(v3[i-1],v3[i-1]);
    g3=dw;
    tc=62;
    while (y>0)
    {
        while (y<((LL)1<<tc)) --tc;
        g3=times(g3,v3[tc]);
        y-=(LL)1<<tc;
    }
    anssum=(((LL)firstsum*g3.a1+(LL)(a[1]+nowmax)*g3.a2)%bigp+bigp)%bigp;
    cout<<anssum<<endl;

    return 0;
}