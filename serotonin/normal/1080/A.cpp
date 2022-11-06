#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5,p=1e9+7;

int main()
{
    ll n,k,x;
    cin >> n >> k;
    ll ans=0;
    x=(n*2)/k;
    if((n*2)%k) x++;
    ans+=x;
    x=(n*5)/k;
    if((n*5)%k) x++;
    ans+=x;
    x=(n*8)/k;
    if((n*8)%k) x++;
    ans+=x;
    cout << ans << endl;
}