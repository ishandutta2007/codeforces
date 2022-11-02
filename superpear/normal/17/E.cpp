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
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

const int bigp=51123987;
const int base=987654323;
const int maxn=2000005;

int n,tt,cc,ans;
char ch;
int a[maxn],cha1[maxn],cha2[maxn],v1[maxn],v2[maxn],sum[maxn];
LL hash1[maxn],hash2[maxn],powc[maxn];

bool ok(int start,int len)
{
    LL c1=hash1[start+len-1]-hash1[start-1]*powc[len];
    int q1=n+1-(start+len-1);
    LL c2=hash2[q1+len-1]-hash2[q1-1]*powc[len];
    if (c1==c2) return true; else return false;
}

int main()
{
    int left,right,mid,ll,rr;

    scanf("%d\n",&n);
    powc[0]=1;
    for (int i=1;i<=n;i++) powc[i]=powc[i-1]*base;
    for (int i=1;i<=n;i++)
    {
        ch=getchar();
        a[i]=ch-96;
    }
    hash1[0]=0;
    for (int i=1;i<=n;i++) hash1[i]=hash1[i-1]*base+a[i];
    hash2[0]=0;
    for (int i=1;i<=n;i++) hash2[i]=hash2[i-1]*base+a[n+1-i];
    memset(cha1,0,sizeof(cha1));
    memset(cha2,0,sizeof(cha2));
    memset(v1,0,sizeof(v1));
    memset(v2,0,sizeof(v2));
    tt=0;
    for (int i=1;i<=n;i++)
    {
        left=1;right=min(i,n-i+1);
        while (left<=right)
        {
            mid=(left+right)/2;
            if (ok(i-mid+1,mid*2-1)) left=mid+1; else right=mid-1;
        }
        ll=i-right+1;rr=i;
        cha1[ll]++;cha1[rr+1]--;
        ll=i;rr=i+right-1;
        cha2[ll]++;cha2[rr+1]--;
    }
    for (int i=1;i<n;i++)
        if (a[i]==a[i+1])
        {
            left=1;right=min(i,n-i);
            while (left<=right)
            {
                mid=(left+right)/2;
                if (ok(i-mid+1,mid*2)) left=mid+1; else right=mid-1;
            }
            ll=i-right+1;rr=i;
            cha1[ll]++;cha1[rr+1]--;
            ll=i+1;rr=i+right;
            cha2[ll]++;cha2[rr+1]--;
        }
    v1[0]=0;
    tt=0;
    for (int i=1;i<=n;i++) v1[i]=v1[i-1]+cha1[i],tt=(tt+v1[i])%bigp;
    v2[0]=0;
    for (int i=1;i<=n;i++) v2[i]=v2[i-1]+cha2[i];
    sum[0]=0;
    for (int i=1;i<=n;i++) sum[i]=(sum[i-1]+v2[i])%bigp;
    cc=0;
    for (int i=2;i<=n;i++) cc=(cc+(LL)v1[i]*sum[i-1])%bigp;
    ans=(((LL)tt*(tt-1)/2)%bigp-cc+bigp)%bigp;
    printf("%d\n",ans);

    return 0;
}