#include <bits/stdc++.h>
using namespace std;
int a[1000000];
long long sum[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    int s,f;
    cin>>s>>f;
    int k = f-s;
    for (int i=n+1;i<=2*n;i++)
        sum[i]=sum[i-1]+a[i-n];
    long long ret=0,best=1;
    for (int i=k;i<n+k;i++)
    {
        if (sum[i]-sum[i-k]>=ret){
            long long cur = f-i;
            if (cur<=0)cur+=n;
            if (sum[i]-sum[i-k]>ret)
                best=cur;
            else
                best=min(best,cur);
            ret=sum[i]-sum[i-k];
        }
    }
    if (best<=0)best+=n;
    cout<<best<<endl;
}