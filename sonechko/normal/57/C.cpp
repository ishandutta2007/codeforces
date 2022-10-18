#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define ff first
#define ss second
#define mod %MOD

const int N = 1e6 + 11;
const ll MOD = 1e9 + 7;

int fac[N];

int step(int x, int y)
{
    if (y==0) return 1;
    if (y%2==1) return (step(x,y-1)*1ll*x)mod;
    int c=step(x,y/2);
    return (c*1ll*c)mod;
}

int c(int n, int k)
{
    int d=fac[n];
    int p1=fac[n-k];
    int p2=fac[k];
    d=(d*1ll*step(p1,MOD-2))mod;
    d=(d*1ll*step(p2,MOD-2))mod;
    return d;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    fac[0]=1;
    for (int i=1; i<=n*2; i++)
        fac[i]=(fac[i-1]*1ll*i)mod;
    int ans=0;
    for (int i=1; i<=n; i++)
    {
        int p=n-1;
        p+=n-i;
        ans=(ans*1ll+1ll*c(p,n-1))mod;
    }
    cout<<(ans*2ll-n+MOD)mod;
}