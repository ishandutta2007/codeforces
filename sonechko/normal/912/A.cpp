#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b,x,y,z;
    cin>>a>>b>>x>>y>>z;
    ll rr1=x*2+y;
    ll rr2=y+z*3;
    cout<<max(0ll,rr1-a)+max(0ll,rr2-b);
}