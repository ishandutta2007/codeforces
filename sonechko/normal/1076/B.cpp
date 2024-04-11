#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

const ll N = 1e6 + 11;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    if (n%2==0)
    {
        cout<<n/2<<endl;
        return 0;
    }
    for (ll j=2; j<=sqrt(n); j++)
    if (n%j==0) {cout<<(n-j)/2+1<<endl; return 0;}
    cout<<1<<endl;
}