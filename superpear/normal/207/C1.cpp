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

const int base=987654323;
const int maxn=100005;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

struct ljb
{
    int num,dest;
    ljb *next;
} *p,*head[maxn],*tail[maxn];

LL bzhash[maxn][17],powc[maxn],hasha[maxn];
int bzfa[maxn][17],dis1[maxn],dis2[maxn],sa[maxn],bak[maxn],f1[maxn],f2[maxn],flag[maxn],which[maxn],fa1[maxn],fa2[maxn],fac1[maxn],fac2[maxn];
PII qj[maxn];
int q,lc,rc,o1,o2,o,e,father;
char ch;

bool cmp(int xc,int yc)
{
    for (int i=16;i>=0;i--)
    {
        if ((bzfa[xc][i]!=0)&&(bzfa[yc][i]!=0))
            if (bzhash[xc][i]==bzhash[yc][i])
            {
                xc=bzfa[xc][i];
                yc=bzfa[yc][i];
            }
    }
    if (fa2[xc]==0) return true;
    if (fa2[yc]==0) return false;
    return fac2[xc]<fac2[yc];
}

void mpush(int x,int y,int z)
{
    ljb *p;
    p=new ljb;
    p->dest=y;p->num=z;
    p->next=0;
    tail[x]->next=p;
    tail[x]=p;
}

int getfa(int s,int k)
{
    for (int i=16;i>=0;i--)
        if (k>=(1<<i))
        {
            s=bzfa[s][i];
            k-=1<<i;
        }
    return s;
}

void dfs(int s,int left,int right)
{
    qj[s]=m_p(left,right);
    int c=0,ll,rr,mm,lc,rc,nowc;
    ljb *p=head[s]->next;
    //cout<<left<<"    "<<right<<endl;
    while (p!=0)
    {
        ll=left;rr=right;
        while (ll<=rr)
        {
            mm=(ll+rr)/2;
            nowc=getfa(sa[mm],dis1[s]-1);
            if (fac2[nowc]>=p->num) rr=mm-1; else ll=mm+1;
        }
        lc=ll;
        ll=left;rr=right;
        while (ll<=rr)
        {
            mm=(ll+rr)/2;
            nowc=getfa(sa[mm],dis1[s]-1);
            if (fac2[nowc]<=p->num) ll=mm+1; else rr=mm-1;
        }
        rc=rr;
        dfs(p->dest,lc,rc);
        p=p->next;
    }
}

void plus1(int s)
{
    while (s<=o2)
    {
        f1[s]++;
        s+=s&(-s);
    }
}

int gs1(int s)
{
    int ss=0;
    while (s>0)
    {
        ss+=f1[s];
        s-=s&(-s);
    }
    return ss;
}

int getsum1(int l,int r)
{
    return gs1(r)-gs1(l-1);
}

void pl2(int s,int flag)
{
    while (s<=o2)
    {
        f2[s]+=flag;
        s+=s&(-s);
    }
}

void plus2(int l,int r)
{
    pl2(l,1);
    pl2(r+1,-1);
}

int gettime2(int s)
{
    int ss=0;
    while (s>0)
    {
        ss+=f2[s];
        s-=s&(-s);
    }
    return ss;
}

int main()
{
    powc[0]=1;
    for (int i=1;i<=maxn;i++) powc[i]=powc[i-1]*base;

    //freopen("game.in","r",stdin);
    //freopen("game.out","w",stdout);

    o1=1;o2=1;
    scanf("%d\n",&q);
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d %c\n",&flag[i],&father,&ch);
        if (flag[i]==1)
        {
            ++o1;fa1[o1]=father;fac1[o1]=ch-96;
            which[i]=o1;
        }
        else
        {
            ++o2;fa2[o2]=father;fac2[o2]=ch-96;
            which[i]=o2;
        }
    }
    //cout<<o1<<" "<<o2<<endl;
    for (int i=1;i<=o2;i++)
    {
        if (i==1) bzhash[i][0]=0; else bzhash[i][0]=fac2[i];
        if (i==1) bzfa[i][0]=0; else bzfa[i][0]=fa2[i];
        o=1;e=fa2[i];
        while (bzfa[e][o-1]!=0)
        {
            bzhash[i][o]=bzhash[i][o-1]*powc[1<<(o-1)]+bzhash[e][o-1];
            bzfa[i][o]=bzfa[e][o-1];
            e=bzfa[i][o];
            o++;
        }
    }
    dis1[1]=1;
    for (int i=2;i<=o1;i++)
        dis1[i]=dis1[fa1[i]]+1;
    dis2[1]=1;
    for (int i=2;i<=o2;i++)
        dis2[i]=dis2[fa2[i]]+1;
    for (int i=1;i<=o2;i++) sa[i]=i;
    sort(sa+1,sa+o2+1,cmp);
    for (int i=1;i<=o2;i++) bak[sa[i]]=i;
    //for (int i=1;i<=o2;i++) cout<<sa[i]<<endl;return 0;

    for (int i=0;i<=o1;i++)
    {
        p=new ljb;
        p->dest=0;p->num=0;
        p->next=0;
        head[i]=p;tail[i]=p;
    }
    for (int i=2;i<=o1;i++) mpush(fa1[i],i,fac1[i]);
    dfs(1,1,o2);
    //for (int i=1;i<=o1;i++) cout<<qj[i].first<<" "<<qj[i].second<<endl;

    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    LL ans=1,nt;
    plus2(1,o2);
    plus1(1);
    for (int i=1;i<=q;i++)
    {
        if (flag[i]==1)
        {
            lc=qj[which[i]].first;
            rc=qj[which[i]].second;
            //cout<<lc<<"  "<<rc<<endl;
            ans+=getsum1(lc,rc);
            plus2(lc,rc);
        }
        else
        {
            lc=bak[which[i]];
            //cout<<lc<<"   c"<<endl;
            ans+=gettime2(lc);
            plus1(lc);
        }
        printf("%I64d\n",ans);
    }

    return 0;
}