#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=4e5,INF=1e17;

int main()
{
    ll n;
    cin >> n;
    ll x=sqrt(n),m;
    for(m=max(x-2,0LL); ; m++) {
        if(m*m>=n) break;
    }
    ll more=n/m;
    if(n%m) more++;
    cout << m+more << endl;
}