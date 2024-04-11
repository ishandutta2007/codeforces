#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ss second
#define ff first
#define mp make_pair
#define pb push_back
const int N = 2e5 + 11;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a,b;
    cin>>a>>b;
    ll ks=1;
    for (ll p=a+1; p<=b; p++)
    {
        ks=(ks*(p%10))%10;
        if (ks==0) break;
    }
    cout<<ks<<endl;
}