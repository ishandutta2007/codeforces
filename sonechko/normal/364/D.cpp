#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const int N = 2e6 + 11;

ll a[N];
ll ans;
int n;
int ks;
int kkk[N];
ll d[N];
ll t[N];
map<ll,int> mt;



void up(ll x)
{
    mt.clear();
    ks=0;
    for (ll j=1; j<=(ll)sqrt(x); j++)
        if (x%j==0)
        {
            ks++;
            mt[j]=ks;
            d[ks]=j;
            kkk[ks]=0;
            if (x/j!=j)
            {
                ks++;
                mt[x/j]=ks;
                d[ks]=x/j;
                kkk[ks]=0;
            }
        }
    for (int i=1; i<=n; i++)
    {
        ll y=__gcd(a[i],x);
        kkk[mt[y]]++;
    }
    for (int i=1; i<=ks; i++)
        if (d[i]>ans)
    {
        int kk=0;
        for (int j=1; j<=ks; j++)
            if (d[j]%d[i]==0) kk+=kkk[j];
        if (kk>=(n+1)/2) ans=d[i];
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    random_shuffle(a+1,a+n+1);
    ans=1;
    int ks=0;
    for (int i=1; i<=min(n,13); i++)
        up(a[i]);
    cout<<ans<<endl;
}
/**
8
1 1 1 1 210 140 84 60
**/