#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define mid (l+r)/2
using namespace std;
long long dp[1000000];
long long best[1000000];
long long v[1000000];
long long c[1000000];
int main()
{
    long long mx1=0,mx2=0;
    long long col1=-1,col2=-1;
    long long n,q;
    cin>>n>>q;
    for (long long i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for (long long i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for (long long kok=0;kok<q;kok++)
    {
        long long mx1=0,mx2=0;
        long long col1=-1,col2=-1;
        for (long long i=0;i<=n;i++)
        {
            best[i]=-((long long)(1)<<60);
        }
        long long a,b;
        cin>>a>>b;
        dp[0]=max((long long)(0),v[0]*b);
        if (dp[0]>mx1)
        {
            mx1=dp[0];
            col1=c[0];
        }
            best[c[0]]=v[0]*b;
        long long ans=0;
        for (long long i=1;i<n;i++)
        {
            dp[i]=0;
            long long j;
            if (col1==c[i])
                j=mx2;
            else
                j=mx1;
            dp[i]=max(dp[i],v[i]*b+j);
            dp[i]=max(dp[i],v[i]*a+best[c[i]]);
            ans=max(ans,dp[i]);
            if (dp[i]>mx1)
            {
                if (col1==c[i])
                {
                    mx1=dp[i];
                }
                else
                {
                    mx2=mx1;
                    col2=col1;
                    mx1=dp[i];
                    col1=c[i];
                }
            }
            else if (dp[i]>mx2)
            {
                if (c[i]!=col1)
                {
                mx2=dp[i];
                col2=c[i];
                }
            }
            best[c[i]]=max(best[c[i]],max(v[i]*a+best[c[i]],v[i]*b+j));
        }
        cout<<ans<<endl;
    }
}