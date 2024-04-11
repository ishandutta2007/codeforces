#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define ll long long

const int N = 1e6 + 11;

long long a[N],b[N],p[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,l;
    cin>>n>>l;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=n-1; i>=1; i--)
        a[i]=min(a[i],a[i+1]);
    for (int i=2; i<=n; i++)
    {
        long long res=0;
        for (int x=1; x<i; x++)
            res+=a[x];
        res+=a[1];
        a[i]=min(a[i],res);
        for (int x=1; x<i; x++)
        {
            res-=a[x]+a[x];
            res+=a[x+1];
            a[i]=min(a[i],res);
        }
    }
    p[1]=1;
    for (int i=2; i<=n; i++)
        p[i]=p[i-1]*2;
    long long ans=0,rres=4e18;
    int x=n;
    for (int i=n; i>=1; i--)
    {
        l=max(l,0);
        long long d=l/p[i];
        rres=min(rres,ans+(d+1)*a[i]);
        if (a[x]==a[i])
        {
        ans+=a[x]*d;
        l-=d*p[x];
        } else
        {
        ans+=a[i]*d;
        l-=d*p[i];
        x=i;
        }
    }
    rres=min(rres,ans);
    cout<<rres<<endl;
}