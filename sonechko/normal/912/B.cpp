#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 11;

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll rr=0;
    for (ll p=1; p<=n; p*=2)
        rr=p;
    if (k==1) cout<<n<<endl; else cout<<rr*2-1<<endl;
}