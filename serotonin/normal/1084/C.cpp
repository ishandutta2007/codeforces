#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=2e5,p=1e9+7;

char s[sz];
vector <ll> divs;

int main()
{
    ll i,j,k;
    cin >> s;
    ll n=strlen(s);
    ll x=0;
    for(i=0; i<n; i++) {
        if(s[i]=='a') x++;
        else if(s[i]=='b') {
            if(x) divs.push_back(x);
            x=0;
        }
    }
    if(x) divs.push_back(x);

    ll ans=0;
    for(i=0; i<divs.size(); i++) {
        ll z=(ans*divs[i])%p;
        ans+=z;
        ans%=p;
        ans+=divs[i];
        ans%=p;
    }
    if(ans<0) ans+=p;
    cout << ans << endl;
}