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
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

string s;
char ch,ans[3000006];
int k,m,o,c1,c2,c3,le,stopflag,mr,mf,lk,ov;
int l[5005],r[5005],whichchr[3000006],blocksize[3000006],next[3000006],pre[3000006];
set<int> lg;
set<int>::iterator ee;

int main()
{
    s="";
    while (true)
    {
        ch=getchar();
        if ((ch>='A')&&(ch<='Z')) s+=ch; else break;
    }
    scanf("%d",&k);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
        scanf("%d %d",&l[i],&r[i]);
    memset(whichchr,0,sizeof(whichchr));
    memset(blocksize,0,sizeof(blocksize));
    memset(next,0,sizeof(next));
    memset(pre,0,sizeof(pre));
    for (int i=1;i<=k;i++) next[i]=i+1,pre[i]=i-1;
    blocksize[1]=k;
    lg.insert(1);
    for (int i=m;i>=1;i--)
    {
        c1=1;le=l[i]-1;
        while (le>=blocksize[c1])
        {
            le-=blocksize[c1];
            c1+=blocksize[c1]-1;
            c1=next[c1];
            if (c1>k) break;
        }
        c1+=le;
        if (c1>k) continue;
        c2=c1;
        le=r[i]-l[i]+1;
        ee=lg.l_b(c2+1),ee--,lk=*ee;
        ov=lk+blocksize[lk]-c2;
        if (le>=ov)
        {
            le-=ov;
            c2=next[lk+blocksize[lk]-1];
            if (c2>k) continue;
            while (le>=blocksize[c2])
            {
                le-=blocksize[c2];
                c2+=blocksize[c2]-1;
                c2=next[c2];
                if (c2>k) break;
            }
        }
        c2+=le;
        if (c2>k) continue;
        stopflag=c2;
        c3=next[c1];
        while ((c3<stopflag)&&(c2<=k))
        {
            whichchr[c2]=c3;
            c2=next[c2];
            c3=next[c3];
            if (c3<stopflag) c3=next[c3];
        }
        c3=c1;
        while ((c3<stopflag)&&(c2<=k))
        {
            whichchr[c2]=c3;
            c2=next[c2];
            c3=next[c3];
            if (c3<stopflag) c3=next[c3];
        }
        mr=stopflag;
        mf=mr;
        for (int j=1;j<=r[i]-l[i];j++)
        {
            if (next[mf]>k) break;
            mf=next[mf];
        }
        ee=lg.l_b(mr+1),ee--,lk=*ee;
        if (mf-mr==r[i]-l[i])
        {
            next[pre[mr]]=next[mf];
            pre[next[mf]]=pre[mr];
            if (next[mf]==mf+1)
            {
                blocksize[next[mf]]=lk+blocksize[lk]-1-next[mf]+1;
                lg.insert(next[mf]);
            }
            if (pre[mr]==mr-1) blocksize[lk]=pre[mr]-lk+1; else lg.erase(mr);
        }
        else
        {
            next[pre[mr]]=next[mf];
            pre[next[mf]]=pre[mr];
            if (pre[mr]==mr-1) blocksize[lk]=pre[mr]-lk+1; else lg.erase(mr);
            if (next[mf]==mf+1)
            {
                ee=lg.l_b(next[mf]+1),ee--,lk=*ee;
                blocksize[next[mf]]=lk+blocksize[lk]-1-next[mf]+1;
                lg.insert(next[mf]);
            }
        }
    }
    o=0;
    for (int i=1;i<=k;i++)
        if (whichchr[i]==0)
        {
            ans[i]=s[o];
            ++o;
        }
        else
            ans[i]=ans[whichchr[i]];
    for (int i=1;i<=k;i++) putchar(ans[i]);putchar('\n');

    return 0;
}