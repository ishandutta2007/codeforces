#include<bits/stdc++.h>
using namespace std;
pair<long long,long long> a[400000],b[400000];
int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    long long x,s;
    cin>>x>>s;
    for (int i=0;i<m;i++)
        scanf("%I64d",&a[i].second);
    for (int i=0;i<m;i++)
        scanf("%I64d",&a[i].first);
    for (int i=0;i<k;i++)
        scanf("%I64d",&b[i].second);
    for (int i=0;i<k;i++)
        scanf("%I64d",&b[i].first);
    sort(a,a+m);
    sort(b,b+k);
    for (int i=1;i<m;i++)
        a[i].second=min(a[i].second,a[i-1].second);
    for (int i=1;i<k;i++)
        b[i].second=max(b[i].second,b[i-1].second);
    long long ans=n*x;
    int j=k-1;

    while(j>=0  && b[j].first>s)j--;
    if (j>=0)
    {
        ans=0;
        long long h=n;
        h-=b[j].second;
        if (h>0)ans+=h*x;
    }
    for (int i=0;i<m;i++)
    {
        while(j>=0 && a[i].first+b[j].first>s)
            j--;
        if (a[i].first>s)continue;
        long long X=n;
        if (j!=-1)
            X-=b[j].second;
        long long cur=0;
        if (X>0)
        {
            cur+=X*a[i].second;
        }
        if (ans==-1)ans=cur;
        else ans=min(ans,cur);
    }
    cout<<ans<<endl;
}