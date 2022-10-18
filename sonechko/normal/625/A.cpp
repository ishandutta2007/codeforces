#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define mp make_pair
const int N = 1e6 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    if (a<=b-c||n<b) cout<<n/a<<endl; else
    {
        ll p=(n-c)/(b-c);
        n-=(b-c)*p;
        cout<<n/a+p<<endl;
    }
}