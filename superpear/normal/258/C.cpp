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

const int bigp=1000000007;

int n,maxn,ans,c,o,t1,t2;
int a[100005],p[100005],l[100005],r[100005];

int powc(int a,int b)
{
    if (b==0) return 1;
    int d=powc(a,b/2);
    d=(LL)d*d%bigp;
    if (b%2==1) d=(LL)d*a%bigp;
    return d;
}

int main()
{
    //freopen("C.in","r",stdin);
    int left,right,mid;
    scanf("%d",&n);
    maxn=0;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),maxn=max(maxn,a[i]);
    sort(a+1,a+n+1);
    ans=0;
    for (int i=1;i<=maxn;i++)
    {
        o=0;
        for (int j=1;j*j<=i;j++)
            if (i%j==0)
            {
                ++o;p[o]=j;
                if (i!=j*j) ++o,p[o]=i/j;
            }
        sort(p+1,p+o+1);
        p[o+1]=maxlongint;
        c=0;
        l[0]=0;r[0]=0;
        while (r[c]<n)
        {
            c++;
            l[c]=r[c-1]+1;
            left=l[c];right=n;
            while (left<=right)
            {
                mid=(left+right)/2;
                if (a[mid]<p[c+1]) left=mid+1; else right=mid-1;
            }
            r[c]=right;
        }
        t1=1;
        for (int i=1;i<=c;i++)
            t1=(LL)t1*powc(i,r[i]-l[i]+1)%bigp;
        t2=1;
        for (int i=1;i<=c;i++)
            if (i!=c) t2=(LL)t2*powc(i,r[i]-l[i]+1)%bigp; else t2=(LL)t2*powc(i-1,r[i]-l[i]+1)%bigp;
        ans=((LL)ans+t1-t2)%bigp;
        //for (int i=1;i<=c;i++) cout<<l[i]<<" "<<r[i]<<"    "<<c<<endl;
        //cout<<ans<<endl;
    }
    ans=(ans+(LL)bigp)%bigp;
    printf("%d\n",ans);

    return 0;
}