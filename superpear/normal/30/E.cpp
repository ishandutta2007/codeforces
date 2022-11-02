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

const int base=3214567;
const int maxn=100005;

struct two
{
    int first,second;
} g[maxn],u[maxn];

string s;
int hash1[maxn],hash2[maxn],a[maxn],b[maxn],powc[maxn],kuo[maxn],she[maxn];
PII pa[10],t[maxn],nowmax[maxn];
int n,ans,ansk,el,bi,top,front;

bool equal(int a,int b,int c)
{
    int k1=hash1[a+c-1]-hash1[a-1]*powc[c];
    int k2=hash2[b+c-1]-hash2[b-1]*powc[c];
    if (k1==k2) return true; else return false;
}

bool cmp(const two &a,const two &b)
{
    if (a.second<b.second) return true;
    if (a.second>b.second) return false;
    return a.first<b.first;
}

int main()
{
    //freopen("E.in","r",stdin);

    cin>>s;
    n=s.size();
    for (int i=1;i<=n;i++)
    {
        a[i]=s[i-1];
        b[i]=s[n-i];
    }
    hash1[0]=0;
    for (int i=1;i<=n;i++) hash1[i]=hash1[i-1]*base+a[i];
    hash2[0]=0;
    for (int i=1;i<=n;i++) hash2[i]=hash2[i-1]*base+b[i];
    powc[0]=1;
    for (int i=1;i<=n;i++) powc[i]=powc[i-1]*base;
    int left,right,mid;
    for (int i=1;i<=n;i++)
    {
        left=0;right=min(i-1,n-i);
        while (left<=right)
        {
            mid=(left+right)/2;
            if (equal(i-mid,n+1-i-mid,mid*2+1)) left=mid+1; else right=mid-1;
        }
        kuo[i]=right;
    }
    for (int i=1;i<=n;i++)
    {
        left=1;right=n-i+1;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (equal(i,1,mid)) left=mid+1; else right=mid-1;
        }
        she[i]=right;
    }
    ans=0;
    for (int i=1;i<=n;i++) t[i]=m_p(0,0);
    nowmax[0]=m_p(0,0);
    for (int i=1;i<=n;i++)
    {
        if (she[i]>t[i+she[i]-1].first)
        {
            t[i+she[i]-1].first=she[i];
            t[i+she[i]-1].second=i;
        }
        if (t[i]>nowmax[i-1]) nowmax[i]=t[i]; else nowmax[i]=nowmax[i-1];
        el=kuo[i]*2+1;
        bi=min(nowmax[i-kuo[i]-1].first,n-i-kuo[i]);
        if (el+bi*2>ans)
        {
            ans=el+bi*2;
            ansk=0;
            if (bi!=0) ++ansk,pa[ansk]=m_p(nowmax[i-kuo[i]-1].second,bi);
            ++ansk;pa[ansk]=m_p(i-kuo[i],kuo[i]*2+1);
            if (bi!=0) ++ansk,pa[ansk]=m_p(n-bi+1,bi);
        }
    }
    for (int i=1;i<=n;i++)
    {
        g[i].first=i;g[i].second=i+she[i]-1;
    }
    sort(g+1,g+n+1,cmp);
    top=0;
    for (int i=1;i<=n;i++)
    {
        while ((top>0)&&(g[i].first<=u[top].first)) --top;
        ++top;u[top]=g[i];
    }
    front=1;
    for (int i=1;i<=n;i++)
    {
        while (u[front].second<i-kuo[i]) ++front;
        if (front<=top)
        {
            el=kuo[i]*2+1;
            bi=min(i-kuo[i]-u[front].first,n-i-kuo[i]);
            if (el+bi*2>ans)
            {
                ans=el+bi*2;
                ansk=0;
                if (bi!=0) ++ansk,pa[ansk]=m_p(u[front].first,bi);
                ++ansk;pa[ansk]=m_p(i-kuo[i],kuo[i]*2+1);
                if (bi!=0) ++ansk,pa[ansk]=m_p(n-bi+1,bi);
            }
        }
    }

    cout<<ansk<<endl;
    for (int i=1;i<=ansk;i++) cout<<pa[i].first<<" "<<pa[i].second<<endl;

    return 0;
}