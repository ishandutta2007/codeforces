#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>
using namespace std;
long long m[100001];
long long c[100001];
long long dp[101][100001];
long long d[100001];
long long a[100001];
long long tot;
long long sum[100001];
bool bad(long long x,long long l1,long long l2,long long l3)
{
    return (c[l3]-c[l1])*(m[l1]-m[l2])<(c[l2]-c[l1])*(m[l1]-m[l3]);
}
void add(long long ms,long long cs,long long x)
{
    m[tot]=ms;
    c[tot++]=cs;
    while(tot>=3 && bad(x,tot-3,tot-2,tot-1))
    {
        m[tot-2]=m[tot-1];
        c[tot-2]=c[tot-1];
        tot--;
    }
}
long long cur;
void query(long long x,long long val)
{
    if (cur>=tot)
        cur=tot-1;
    while(cur<tot-1 && (val*m[cur]+c[cur])>=(val*m[cur+1]+c[cur+1]))
        cur++;
}
int main()
{
    long long n,g,p;
    cin>>n>>g>>p;
    d[1]=0;
    for (long long i=2;i<=n;i++)
    {
        cin>>d[i];
        d[i]+=d[i-1];
    }
    for (long long i=1;i<=g;i++)
    {
        long long h,t;
        cin>>h>>t;
        t-=d[h];
        a[i]=t;
    }
    sort(a+1,a+g+1);
    for (long long i=1;i<=g;i++)
    {
        sum[i]=sum[i-1]+a[i];
    }
    for (long long x=1;x<=p;x++)
    {

        tot=0;
        cur=0;
        for (long long i=1;i<=g;i++)
        {
            if (x>1 || i==1) add(-i+1,dp[x-1][i-1]+sum[i-1],x);
            query(x-1,a[i]);
            dp[x][i]=a[i]*m[cur]+c[cur]+i*a[i]-sum[i];
        }
    }
     long long ans=100000000;
    cout<<dp[p][g]<<endl;
}