#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009];
map<ll,ll> M;
ll P=1e18;
main()
{
    ll n;
    cin>>n;
    for (ll i=0; i<n; i++)
        cin>>a[i];
        ll s=0;
        pair<ll,ll> ANS={0,0};
    for (ll i=0; i<n; i++)
    {
        ll X=i*a[i]-s-M[a[i]-1]+M[a[i]+1];
        ANS.second+=X;
        ANS.first+=ANS.second/P;
        ANS.second%=P;
        s+=a[i];
        M[a[i]]++;
    }
    if(ANS.first) 
    cout<<ANS.first<<setw(18)<<setfill('0')<<abs(ANS.second)<<endl;
    else 
    cout<<ANS.second<<endl;
}