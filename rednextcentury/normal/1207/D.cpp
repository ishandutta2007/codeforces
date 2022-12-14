#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[1000000];
pair<int,int> b[1000000];
long long F[1000000];
long long mod=998244353;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    F[0]=1;
    for (int i=1;i<=n;i++)
        F[i]=(F[i-1]*i)%mod;
    for (int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
        b[i]={a[i].second,a[i].first};
    }
    long long ret=F[n];
    sort(a,a+n);sort(b,b+n);
    int num=1,last=a[0].first;
    long long S1=1;
    for (int i=1;i<n;i++)
    {
        if (a[i].first==last)num++;
        else
        {
            S1=(S1*F[num])%mod;
            num=1;
        }
        last=a[i].first;
    }
    S1=(S1*F[num])%mod;
    num=1,last=b[0].first;
    long long S2=1;
    for (int i=1;i<n;i++)
    {
        if (b[i].first==last)num++;
        else
        {
            S2=(S2*F[num])%mod;
            num=1;
        }
        last=b[i].first;
    }
    S2=(S2*F[num])%mod;
    S1+=S2;
    S1%=mod;
    ret=(ret-S1+mod)%mod;
    num=1;
    auto lst=a[0];
    long long S=1;
    for (int i=1;i<n;i++)
    {
        if (a[i].first<a[i-1].first)S=0;
        if (a[i].second<a[i-1].second)S=0;
        if (a[i]==lst)num++;
        else{
            S=(S*F[num])%mod;
            num=1;
        }
        lst=a[i];
    }
    S=(S*F[num])%mod;
    ret=(ret+S)%mod;
    cout<<ret<<endl;
}