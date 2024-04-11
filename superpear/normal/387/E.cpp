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

const int maxn=1000005;

int f[maxn],a[maxn],hash[maxn],lc[maxn],rc[maxn],pow2[maxn],where[maxn];
int minc[maxn][23];

int N,K,cs,o,e;

int getmin(int l,int r)
{
    int c=pow2[r-l+1];
    return min(minc[l][c],minc[r-(1<<c)+1][c]);
}

int getsum(int s)
{
    int e=0;
    while (s>0)
    {
        e+=f[s];
        s-=s&(-s);
    }
    return e;
}

void mplus(int s)
{
    while (s<=N)
    {
        ++f[s];
        s+=s&(-s);
    }
}

int main()
{
    pow2[1]=0;
    for (int i=2;i<=maxn-5;i++) pow2[i]=pow2[i/2]+1;

    scanf("%d %d",&N,&K);
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        where[a[i]]=i;
    }
    memset(hash,0,sizeof(hash));
    for (int i=1;i<=K;i++)
    {
        scanf("%d",&cs);
        hash[cs]=1;
    }
    memset(minc,0,sizeof(minc));
    for (int i=N;i>=1;i--)
    {
        if (hash[a[i]]==0) minc[i][0]=maxlongint; else minc[i][0]=a[i];
        e=0,o=1;
        while (i+o<=N)
        {
            ++e;
            minc[i][e]=min(minc[i][e-1],minc[i+o][e-1]);
            o*=2;
        }
    }
    memset(lc,0,sizeof(lc));
    memset(rc,0,sizeof(rc));
    for (int i=1;i<=N;i++)
    {
        int left=i+1,right=N,mid;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (getmin(i+1,mid)>a[i]) left=mid+1; else right=mid-1;
        }
        rc[i]=right;
        left=1,right=i-1;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (getmin(mid,i-1)>a[i]) right=mid-1; else left=mid+1;
        }
        lc[i]=left;
    }

    memset(f,0,sizeof(f));
    LL ans=0;
    for (int i=1;i<=N;i++)
        if (hash[i]==0)
        {
            cs=where[i];
            ans+=(rc[cs]-lc[cs]+1)-getsum(rc[cs])+getsum(lc[cs]-1);
            mplus(cs);
        }
    cout<<ans<<endl;

    return 0;
}