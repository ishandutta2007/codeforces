#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

map<int,ll> mt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    ll res=0;
    for (int i=1; i<=n; i++)
    {
        ll l,r;
        cin>>l>>r;
        res-=mt[l];
        mt[l]=max(mt[l],r);
        res+=mt[l];
    }
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        ll l,r;
        cin>>l>>r;
        res-=mt[l];
        mt[l]=max(mt[l],r);
        res+=mt[l];
    }
    cout<<res<<endl;
}