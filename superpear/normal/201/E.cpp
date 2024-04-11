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

int gcd(int a,int b)
{
    if (b==0) return a; else return(gcd(b,a%b));
}
int com(int m,int n)
{
    int a[16],b[16];
    int cs;
    LL e;
    n=min(n,m-n);
    if (n>=20) return maxlongint;
    for (int i=1;i<=n;i++) a[i]=m-i+1,b[i]=i;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            cs=gcd(a[i],b[j]);
            a[i]/=cs;
            b[j]/=cs;
        }
    e=1;
    for (int i=1;i<=n;i++)
    {
        e=e*(LL)a[i];
        if (e>maxlongint) return maxlongint;
    }
    return int(e);
}

int solveit(int m,int s)
{
    LL ans=0,t=(LL)s*m,cs;
    for (int i=0;i<=s;i++)
    {
        if (i==0) cs=1; else cs=t/i;
        if (cs==0) break;
        cs=min(cs,(LL)com(s,i));
        t-=((LL)cs*i);
        ans+=cs;
        if (ans>=maxlongint) return maxlongint;
    }
    return ans;
}

int main()
{
    //freopen("E.in","r",stdin);
    int tt,n,m,left,right,mid,cs;
    scanf("%d",&tt);
    for (int gb=1;gb<=tt;gb++)
    {
        scanf("%d %d",&n,&m);
        left=0;right=n;
        while (left<=right)
        {
            mid=(left+right)/2;
            cs=solveit(m,mid);
            if (cs>=n) right=mid-1; else left=mid+1;
        }
        printf("%d\n",left);
    }

    return 0;
}