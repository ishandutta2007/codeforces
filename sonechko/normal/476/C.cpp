#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define ss second
#define ff first
const ll MOD = 1000000007;
#define mod %MOD
#define pb push_back
#define ld long double
const int N = 1e6 + 11;
const int MAX = 1e8;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b;
    cin>>a>>b;
    ll res=0;
    for (ll i=1; i<=a; i++)
    {
        ll p1=(i*b+1)mod;
        ll p2=(b*(b-1)/2)mod;
        ll p=(p1*p2)mod;
        res=(res+p)mod;
    }
    cout<<res<<endl;
}