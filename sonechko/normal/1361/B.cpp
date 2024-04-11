#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;
const int MOD = 1e9 + 7;

int a[N];

ll step(ll x, ll y)
{
    if (y==0) return 1;
    if (y%2==1) return (x*step(x,y-1))%MOD;
    ll p=step(x,y/2);
    return (p*p)%MOD;
}

void up()
{
    ll n,p;
    cin>>n>>p;
    if (p==1)
    {
        ll kol=0;
        for (int i=1; i<=n; i++)
        {
            cin>>a[i];
            kol++;
        }
        if (kol%2==1) cout<<1<<"\n"; else cout<<0<<"\n";
        return;
    }
    for (int i=1; i<=n; i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    ll kk=0,res=0;
    a[n+1]=a[n];
    for (int i=n; i>=1; i--)
    {
        int x=a[i+1]-a[i];
        if (kk==0)
        {
            kk++;
            res=(res+step(p,a[i]))%MOD;
        } else
        {
            while (x>0&&kk<1e7)
            {
                x--;
                kk*=p;
            }
            res=(res-step(p,a[i])+MOD)%MOD;
            kk--;
        }
    }
    cout<<res<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) up();
}