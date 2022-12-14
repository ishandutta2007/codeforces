#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int F[2000000];
int a[2000000];
long long P[1000001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    P[0]=1;
    for (int i=1;i<=n;i++)
        P[i]=(P[i-1]*2)%MOD;
    int tot = (1<<20)-1;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]=(tot-a[i]);
        F[a[i]]++;
    }

    for (int i=0;i<20;i++)
        for (int j=0;j<(1<<20);j++)
            if (j&(1<<i))
                F[j]+=F[j^(1<<i)];
    long long ret=0;
    for (int j=0;j<(1<<20);j++)
    {
        if (__builtin_popcount(tot-j)%2)
            ret = (ret+MOD-P[F[tot-j]]-1)%MOD;
        else
            ret = (ret+MOD+P[F[tot-j]]+1)%MOD;
    }
    cout<<ret<<endl;
}