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

struct pear
{
    int first,second,which;
    bool operator < (const pear &b) const
    {
        if (second>b.second) return true;
        if (second<b.second) return false;
        return first>b.first;
    }
};

vector<pear> f[280000],k[280000];
vector<int> u[280000];
LL ansnum;
int n,q,leftc,rightc,midc,ans,ai,bi,timenow;
pear a[280000];

pear make_pear(int x,int y,int z)
{
    pear cs;
    cs.first=x;cs.second=y;cs.which=z;
    return cs;
}

int more(pear a,pear b)
{
    int left,right,mid;
    LL ct1,ct2;
    left=1;right=1000000000;
    while (left<=right)
    {
        mid=(left+right)/2;
        ct1=(LL)a.second*mid+a.first;
        ct2=(LL)b.second*mid+b.first;
        if (ct1>=ct2) right=mid-1; else left=mid+1;
    }
    return left;
}

void maketree(int s,int l,int r)
{
    vector<pear> g;
    int nowmax,o;
    if (l==r)
    {
        f[s].push_back(a[l]);
        k[s].push_back(a[l]);
    }
    else
    {
        maketree(s*2,l,(l+r)/2);
        maketree(s*2+1,(l+r)/2+1,r);
        f[s].resize(f[s*2].size()+f[s*2+1].size());
        merge(f[s*2].begin(),f[s*2].end(),f[s*2+1].begin(),f[s*2+1].end(),f[s].begin());
        nowmax=-maxlongint;
        //cout<<f[s][0].first<<endl;
        for (int i=0;i<f[s].size();i++)
            if (f[s][i].first>nowmax)
            {
                g.push_back(f[s][i]);
                nowmax=f[s][i].first;
            }
        pear stack[g.size()+10];
        o=0;
        for (int i=g.size()-1;i>=0;i--)
        {
            while ((o>1)&&(more(g[i],stack[o])<=more(stack[o],stack[o-1]))) --o;
            ++o;stack[o]=g[i];
        }
        for (int i=1;i<=o;i++) k[s].push_back(stack[i]);
        for (int i=1;i<o;i++) u[s].push_back(more(k[s][i],k[s][i-1]));
        /*cout<<l<<"   "<<r<<endl;
        cout<<g.size()<<endl;
        for (int i=0;i<k[s].size();i++) cout<<"("<<k[s][i].first<<","<<k[s][i].second<<","<<k[s][i].which<<") ";
        cout<<endl;*/
    }
}

void doit(int s,int l,int r)
{
    if ((l>rightc)||(r<leftc)) return;
    if ((l==leftc)&&(r<=rightc))
    {
        int left,right,mid;
        pear qq;
        left=0;right=u[s].size()-1;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (u[s][mid]<=timenow) left=mid+1; else right=mid-1;
        }
        qq=k[s][right+1];
        if ((LL)qq.second*timenow+qq.first>ansnum)
        {
            ansnum=(LL)qq.second*timenow+qq.first;
            ans=qq.which;
        }
        leftc=r+1;
    }
    else
    {
        doit(s*2,l,(l+r)/2);
        doit(s*2+1,(l+r)/2+1,r);
    }
}

int main()
{
    //freopen("E.in","r",stdin);
    scanf("%d %d",&n,&q);
    for (int i=1;i<=n;i++)
    {
        scanf("%d %d",&ai,&bi);
        a[i]=make_pear(ai,bi,i);
    }
    maketree(1,1,n);
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d %d",&leftc,&rightc,&timenow);
        ans=0;ansnum=0;
        doit(1,1,n);
        printf("%d\n",ans);
    }

    return 0;
}