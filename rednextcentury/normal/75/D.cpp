# include <bits/stdc++.h>
# include <cstdlib>
#define EPS 1e-9
using namespace std;
long long l[1000];
long long a[51][5001];
long long sum[1000];
long long en[1000];
long long beg[1000];
long long best[1000];
int main()
{
    long long n;
    cin>>n;
    long long m;
    cin>>m;
    for (long long i=0;i<n;i++)
    {
        cin>>l[i];
        beg[i]=-(1LL<<60);
        en[i]=-(1LL<<60);
        for (long long j=0;j<l[i];j++)
            cin>>a[i][j],sum[i]+=a[i][j],beg[i]=max(beg[i],sum[i]);
        long long cur=0;
        for (long long j=l[i]-1;j>=0;j--)
            cur+=a[i][j],en[i]=max(en[i],cur);
        cur=0;
        best[i]=-(1LL<<60);
        for (long long j=0;j<l[i];j++)
        {
            if (cur<0)
                cur=0;
            cur+=a[i][j];
            best[i]=max(best[i],cur);
        }
    }
    long long e=0;
    long long ans=-(1LL<<60);
    for (long long i=0;i<m;i++)
    {
        long long x;
        cin>>x;
        ans=max(ans,best[x-1]);
        ans=max(ans,beg[x-1]+e);
        e=max(en[x-1],sum[x-1]+e);
    }
    cout<<ans<<endl;
}