#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m,k,l;
    cin>>n>>m>>k>>l;
    ll t=k+l;
    ll ans=(t/m)+(t%m>0);
    if (ans*m>n) {cout<<-1<<endl; return 0;}
    cout<<ans<<endl;
}