#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    ll ans=LONG_LONG_MAX;
    for (ll p=0; p<=9; p++)
    for (ll k=1; k<=10000000000; k*=10)
    if (p*k>n) ans=min(ans,p*k);
    cout<<ans-n<<endl;
}