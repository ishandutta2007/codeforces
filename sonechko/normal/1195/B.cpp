#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double

const int N = 3000 + 11;
const int MOD = 1e9 + 7;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    for (ll t=1; t<=min(1000000ll,n); t++)
    {
        ll p=t*(t+1)/2;
        ll c1=p-k;
        ll c2=n-t;
        if (c1==c2) return cout<<c1<<"\n", 0;
    }
}