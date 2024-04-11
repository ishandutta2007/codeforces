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

int bigp;
LL maxc,l,r,k;
vector<LL> f;

struct matrix
{
    int a1,a2,b1,b2;
};

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

int getnthfibonacci(LL n)
{
    --n;
    matrix fc=m_m(0,1,1,1),dw=m_m(1,0,0,1),g2,v2[70];
    LL x,tc;
    v2[0]=fc;
    for (int i=1;i<=69;i++) v2[i]=times(v2[i-1],v2[i-1]);
    g2=dw;
    tc=62;
    x=n;
    while (x>0)
    {
        while (x<((LL)1<<tc)) --tc;
        g2=times(g2,v2[tc]);
        x-=(LL)1<<tc;
    }
    return g2.b2%bigp;
}

LL check(LL l,LL r,LL s)
{
    if (s==0) return -1;
    return (r/s)-((l-1)/s+1)+1;
}

int main()
{
    cin>>bigp>>l>>r>>k;
    for (int i=1;(LL)i*i<=l;i++)
    {
        f.p_b(i);
        f.p_b(l/i);
        f.p_b(l/i+1);
        f.p_b(l/i-1);
    }
    for (int i=1;(LL)i*i<=r;i++)
    {
        f.p_b(i);
        f.p_b(r/i);
        f.p_b(r/i+1);
        f.p_b(r/i-1);
    }
    maxc=0;
    for (int i=0;i<f.size();i++)
        if (check(l,r,f[i])>=k)
            maxc=max(maxc,f[i]);
    cout<<getnthfibonacci(maxc)<<endl;

    return 0;
}