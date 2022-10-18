#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ss second
#define ff first
#define endl "\n"
#define ld long double
#define ll long long
#define pb push_back
const int MOD = 1e9 + 7;
#define mod %MOD


const int N = 3e5 + 11;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll l,r,x,y,k;
    cin>>l>>r>>x>>y>>k;
    for (ll i=x; i<=y; i++)
    {
        if (i*k>=l&&i*k<=r) {cout<<"YES"<<endl; return 0;}
    }
    cout<<"NO"<<endl;
}