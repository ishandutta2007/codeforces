#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long

const int N = 1e6 + 11;

ll get(ll n, ll m)
{
    if (n>m) swap(n,m);
    if (n==1)
    {
        if (m%6<=3) return (m/6)*3;
        if (m%6==4) return (m/6)*3+1;
        if (m%6==5) return (m/6)*3+2;
    }
    if (n==2)
    {
        if (m==2) return 0;
        if (m==3) return 2;
        if (m==4) return 4;
        if (m==5) return 5;
        if (m==6) return 6;
        if (m==7) return 6;
    }
    return (n*m)/2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;
    cin>>n>>m;
    cout<<get(n,m)*2ll<<endl;
}