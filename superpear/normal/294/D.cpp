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
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

int M,N,xc,yc,xx,yy,len;
int paintedge;
LL ans;
set<PII> f;
set<PII>::iterator lsg;
char st[10];

void pushit(int xc,int yc)
{
    lsg=f.l_b(m_p(xc,yc));
    if ((lsg==f.end())||(*lsg!=m_p(xc,yc)))
    {
        f.insert(m_p(xc,yc));
        ++paintedge;
    }
    if (xc==1) xx=1;
    if (yc==1) yy=1;
    if (xc==N) xx=-1;
    if (yc==M) yy=-1;
}

int main()
{
    scanf("%d %d",&N,&M);
    scanf("%d %d %s",&xc,&yc,st);
    if (st[0]=='U') xx=-1; else xx=1;
    if (st[1]=='L') yy=-1; else yy=1;
    paintedge=0;
    pushit(xc,yc);
    ans=1;
    for (int i=1;i<=(M+N)*2;i++)
    {
        len=maxlongint;
        if (xx==1) len=min(len,N-xc);
        if (xx==-1) len=min(len,xc-1);
        if (yy==1) len=min(len,M-yc);
        if (yy==-1) len=min(len,yc-1);
        ans+=len;
        xc+=len*xx;
        yc+=len*yy;
        pushit(xc,yc);
        if (paintedge==M+N-2)
        {
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}