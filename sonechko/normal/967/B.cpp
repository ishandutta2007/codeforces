#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 11;

ll d[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,a,b;
    cin>>n>>a>>b;
    for (int i=1; i<=n; i++)
        cin>>d[i];
    sort(d+2,d+n+1);
    ll s=0;
    for (int i=1; i<=n; i++)
        s+=d[i];
    if ((d[1]*a)/s>=b) {cout<<0<<endl; return 0;}
    for (int i=n; i>=2; i--)
    {
        s-=d[i];
        if ((d[1]*a)/s>=b) {cout<<n-i+1<<endl; return 0;}
    }
}