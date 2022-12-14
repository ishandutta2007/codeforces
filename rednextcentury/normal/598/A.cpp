#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
using namespace std ;
int main ()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ret=n*(n+1)/2;
        for (ll i=1;i<=n;i*=2)
            ret-=2*i;
        cout<<ret<<endl;
    }
}