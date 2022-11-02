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
#define db double
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<db,db> PDD;
typedef pair<PDD,PDD> P4D;
typedef pair<PDD,int> line;

vector<P4D> ti1,ti2;
vector<PDD> ct;
int n;
db h,f,lc,rc,ld,rd,k1,b1,ans;

void pit(PDD a1,PDD a2)
{
    db k1,b1,k2,b2,xc,yc;
    if ((a1.w1<=a2.w1)&&(a1.w2<=a2.w2)) return;
    if ((a1.w1>=a2.w1)&&(a1.w2>=a2.w2)) return;
    if (a2.w1==a2.w2) swap(a1,a2);
    if (a1.w1==a1.w2)
    {
        k1=(2*h)/(a2.w1-a2.w2);
        b1=h-a2.w1*k1;
        ct.p_b(m_p(a1.w1,k1*a1.w1+b1));
    }
    else
    {
        k1=(2*h)/(a1.w1-a1.w2);
        b1=h-a1.w1*k1;
        k2=(2*h)/(a2.w1-a2.w2);
        b2=h-a2.w1*k2;
        xc=(b2-b1)/(k1-k2);
        yc=xc*k2+b2;
        ct.p_b(m_p(xc,yc));
    }
}

void louit(db l1,db r1,db l2,db r2,db h)
{
    if (l1>l2) {swap(l1,l2);swap(r1,r2);}
    if (r1<l2) return;
    if ((r1>=l2)&&(r1<r2))
    {
        ct.p_b(m_p(l2,h));
        ct.p_b(m_p(r1,h));
    }
    if (r1>=r2)
    {
        ct.p_b(m_p(l2,h));
        ct.p_b(m_p(r2,h));
    }
}

db cross(PDD a1,PDD a2,PDD a3)
{
    db s=(a2.w1-a1.w1)*(a3.w2-a1.w2)-(a2.w2-a1.w2)*(a3.w1-a1.w1);
    return s;
}

bool cmp(PDD a1,PDD a2)
{
    return cross(ct[0],a1,a2)>0;
}

db getarea()
{
    if (ct.size()==0) return 0;
    int ml;
    bool flag=true;
    db ans=0;
    while (flag)
    {
        flag=false;
        for (int i=0;i<ct.size();i++)
        {
            for (int j=i+1;j<ct.size();j++)
                if (ct[i]==ct[j])
                {
                    flag=true;
                    break;
                }
            if (flag)
            {
                ct.erase(ct.begin()+i);
                break;
            }
        }
    }
    PDD d=ct[0];
    ml=0;
    for (int i=1;i<ct.size();i++)
        if ((ct[i].w1>d.w1)||((ct[i].w1==d.w1)&&(ct[i].w2>d.w2))) d=ct[i],ml=i;
    swap(ct[0],ct[ml]);
    sort(ct.begin()+1,ct.end(),cmp);
    ct.p_b(ct[0]);
    for (int i=1;i<ct.size();i++)
        ans+=cross(ct[0],ct[i-1],ct[i]);
    return abs(ans/2);
}

db jiao(P4D a1,P4D a2)
{
    db l1,r1,l2,r2;
    ct.clear();
    pit(a1.w1,a2.w1);
    pit(a1.w2,a2.w1);
    pit(a1.w1,a2.w2);
    pit(a1.w2,a2.w2);
    l1=a1.w1.w1;
    r1=a1.w2.w1;
    l2=a2.w1.w1;
    r2=a2.w2.w1;
    louit(l1,r1,l2,r2,h);
    l1=a1.w1.w2;
    r1=a1.w2.w2;
    l2=a2.w1.w2;
    r2=a2.w2.w2;
    louit(l1,r1,l2,r2,-h);
    //for (int i=0;i<ct.size();i++) cout<<ct[i].w1<<" "<<ct[i].w2<<endl;
    return getarea();
}

int main()
{
    //freopen("E.in","r",stdin);
    cin>>n>>h>>f;
    for (int i=1;i<=n;i++)
    {
        cin>>lc>>rc;
        if (lc==0) ld=0; else
        {
            k1=(h-f)/lc;
            b1=f;
            ld=(-h-b1)/k1;
        }
        if (rc==0) rd=0; else
        {
            k1=(h-f)/rc;
            b1=f;
            rd=(-h-b1)/k1;
        }
        ti1.p_b(m_p(m_p(lc,ld),m_p(rc,rd)));
        ti2.p_b(m_p(m_p(ld,lc),m_p(rd,rc)));
    }
    ans=0;
    for (int i=0;i<ti1.size();i++) ans+=2*(ti1[i].w2.w1-ti1[i].w1.w1+ti1[i].w2.w2-ti1[i].w1.w2)*h;
    for (int i=0;i<ti1.size();i++)
        for (int j=0;j<ti2.size();j++)
            ans-=jiao(ti1[i],ti2[j]);
    printf("%.10lf\n",ans);

    return 0;
}