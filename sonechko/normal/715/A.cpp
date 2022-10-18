#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N = 2e5 + 11;
const int MOD = 1e6 + 3;
#define mod %MOD

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    cout<<2<<"\n";
    for (ll i=2; i<=n; i++)
        cout<<(i+1)*(i+1)*i-i+1<<"\n";
}