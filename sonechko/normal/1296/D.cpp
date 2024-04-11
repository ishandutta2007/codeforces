#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 2e5 + 11;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    int ans=0;
    vector<ll> vv;
    for (int i=1; i<=n; i++)
    {
        ll x;
        cin>>x;
        ll y=x%(a+b);
        if (y!=0&&y<=a) {ans++;} else
        {
            y=x/(a+b);
            x-=y*(a+b);
            if (x==0) x+=a+b;
            x-=a;
            ll p=(x+a-1)/a;
            vv.pb(p);
        }
    }
    sort(vv.begin(),vv.end());
    reverse(vv.begin(),vv.end());
    while (vv.size()>0&&vv.back()<=k)
    {
        k-=vv.back();
        ans++;
        vv.pop_back();
    }
    cout<<ans;
}