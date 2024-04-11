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

struct ten
{
    int a[10];
} nowten,times[maxn];

list<PII> f;
list<PII>::iterator cp,last,kc;
int n,m,dp,nt,xc,yc,mt;
string s;
int vis[maxn],fore[maxn],back[maxn];

void outten(ten s)
{
    for (int i=0;i<9;i++) cout<<s.a[i]<<" ";
    cout<<s.a[9]<<endl;
}

int main()
{
    cin>>n>>m;
    cin>>s;
    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='>') f.p_b(m_p(-1,i+1));
        if (s[i]=='<') f.p_b(m_p(-2,i+1));
        if ((s[i]>='0')&&(s[i]<='9')) f.p_b(m_p(s[i]-48,i+1));
    }
    nt=0;
    for (int i=0;i<=9;i++) nowten.a[i]=0;
    cp=f.begin();
    last=f.end();
    dp=1;
    memset(vis,127,sizeof(vis));
    memset(back,127,sizeof(back));
    memset(fore,127,sizeof(fore));
    vis[0]=0;
    while (true)
    {
        int elf=1;
        if (cp->first!=biglongint)
        {
            if ((last!=f.end())&&(last->first==biglongint)) last->first=biglongint;
            if (cp->first>=0)
            {
                ++nowten.a[cp->first];
                --cp->first;
                if (cp->first<0) cp->first=biglongint;
            }
            else
            {
                if ((last!=f.end())&&(last->first<0)&&(cp->first<0)) last->first=biglongint;
                if (cp->first==-1) dp=1; else dp=2;
            }
            ++nt;
            times[nt]=nowten;
            if (vis[cp->second]==biglongint)
                vis[cp->second]=nt;
            last=cp;
        }
        else
        {
            if ((back[cp->second]!=biglongint)&&(fore[cp->second]!=biglongint))
            {
                kc=cp;
                if (last==kc) last=f.end();
                if (dp==2)
                {
                    if (cp==f.begin()) dp=1,++cp; else --cp;
                }
                else
                {
                    ++cp;
                    if (cp==f.end()) break;
                }
                f.erase(kc);
                elf=0;
            }
        }
        if (elf==1)
        {
            if (dp==2)
            {
                if (back[cp->second]==biglongint)
                    back[cp->second]=nt;
            }
            if (dp==1)
            {
                if (fore[cp->second]==biglongint)
                    fore[cp->second]=nt;
            }
            if (dp==2)
            {
                if (cp==f.begin()) dp=1; else --cp;
            }
            else
            {
                ++cp;
                if (cp==f.end()) break;
            }
        }
    }
    vis[n+1]=nt+1;
    fore[0]=0;
    for (int i=1;i<=m;i++)
    {
        cin>>xc>>yc;
        mt=min(vis[yc+1]-1,back[xc]);
        if (fore[xc-1]==biglongint)
        {
            for (int j=0;j<=9;j++) cout<<0<<" ";cout<<" ";
        }
        else
        {
            for (int j=0;j<=9;j++) cout<<times[mt].a[j]-times[fore[xc-1]].a[j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}