#include<bits/stdc++.h>
using namespace std;
long long best[1000000];
int main()
{
    long long n,L;
    cin>>n>>L;
    for (int i=2;i<=30;i++)
        best[i]= ((1LL)<<62);
    for (int i=1;i<=n;i++)
        cin>>best[i];

    for (int i=2;i<=30;i++)
        best[i]=min(best[i],best[i-1]*2);
    for (int i=29;i>=0;i--)
        best[i]=min(best[i],best[i+1]);
    long long ans=0;
    for (long long i=1;i<=31;i++){
        if ((1<<(i-1))&L)
            ans+=best[i];
    }

    for (int j=1;j<=30;j++){
        long long ret=best[j];
        for (long long i=j;i<=30;i++){
            if ((1<<(i-1))&L)
                ret+=best[i];
        }
        ans=min(ans,ret);
    }
    cout<<ans<<endl;
}