#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define y1 skfn

const int N = 1000 + 11;
const int MOD = 1e9 + 7;
#define mod %MOD

bool prost(ll d)
{
    for (int i=2; i<=(int)sqrt(d); i++)
        if (d%i==0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for (int i=1; i<=t; i++)
    {
        ll a,b;
        cin>>a>>b;
        ll c=a-b,d=a+b;
        if (c==1&&prost(d)) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    }
}