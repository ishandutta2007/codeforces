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

int hash[maxn],dat[maxn],powc[maxn],sa[maxn],lcp[maxn],mi2[maxn],rmq[maxn][20];
string s;
int n,e,o;
LL ans=0;

bool equals(int l,int r,int len)
{
    int c1=hash[l+len-1]-hash[l-1]*powc[len];
    int c2=hash[r+len-1]-hash[r-1]*powc[len];
    return (c1==c2);
}

int lcs(int l,int r)
{
    int left=1,right=n-max(l,r)+1,mid;
    while (left<=right)
    {
        mid=(left+right)/2;
        if (equals(l,r,mid)) left=mid+1; else right=mid-1;
    }
    return right;
}

bool cmp(int a,int b)
{
    int ec=lcs(a,b);
    if (a+ec>n) return true;
    if (b+ec>n) return false;
    return dat[a+ec]<dat[b+ec];
}

int getmin(int l,int r)
{
    if (l>r) return maxlongint;
    int c=mi2[r-l+1];
    return min(rmq[l][c],rmq[r-(1<<c)+1][c]);
}

void doit(int l,int r,int depth)
{
    //cout<<l<<" "<<r<<" "<<depth<<endl;
    int e,left,right,mid;
    if (l==r)
    {
        ans+=sa[l]-depth;
        return;
    }
    e=getmin(l,r-1);
    ans+=(LL)(r-l+1)*(r-l+2)/2*(e-depth);
    while (l<=r)
    {
        left=l;
        right=r;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (getmin(l,mid-1)>e) left=mid+1; else right=mid-1;
        }
        doit(l,right,e);
        l=right+1;
    }
}

int main()
{
    //freopen("D.in","r",stdin);
    cin>>s;
    n=s.size();
    memset(dat,0,sizeof(dat));
    for (int i=1;i<=n;i++)
        dat[i]=s[i-1]-96;
    powc[0]=1;
    for (int i=1;i<=n;i++)
        powc[i]=powc[i-1]*base;
    hash[0]=0;
    for (int i=1;i<=n;i++)
        hash[i]=hash[i-1]*base+dat[i];
    for (int i=1;i<=n;i++) sa[i]=i;
    sort(sa+1,sa+n+1,cmp);
    /*
    for (int i=1;i<=n;i++)
    {
        for (int j=sa[i];j<=n;j++)
            cout<<s[j-1];
        cout<<endl;
    }
    */
    for (int i=1;i<n;i++)
        lcp[i]=lcs(sa[i],sa[i+1]);
    mi2[1]=0;
    for (int i=2;i<=n;i++)
        mi2[i]=mi2[i/2]+1;
    for (int i=n-1;i>=1;i--)
    {
        rmq[i][0]=lcp[i];
        e=1;o=1;
        while (i+e<n)
        {
            rmq[i][o]=min(rmq[i+e][o-1],rmq[i][o-1]);
            e*=2;o++;
        }
    }
    ans=0;
    doit(1,n,0);
    cout<<ans<<endl;

    return 0;
}