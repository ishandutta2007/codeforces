#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
const int MOD = 1e9 + 7;
#define mod %MOD

const int N = 2e5 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x,d;
    cin>>x>>d;
    ll c=1;
    for (int d=1; d<=30; d++)
        c*=2;
    ll ts=1;
    vector<ll> v;
    for (int i=30; i>=1; i--)
   {
       while (c-1<=x)
        {
            x-=c-1;
            for (int d=1; d<=i; d++)
                v.pb(ts);
            ts+=d;
        }
    c/=2;
   }
   cout<<v.size()<<endl;
   for (int i=0; i<v.size(); i++)
   cout<<v[i]<<" ";
   cout<<endl;
}