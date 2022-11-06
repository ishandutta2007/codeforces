#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll a,b;
        cin >> a >> b;
        if(a>b) swap(a,b);

        if(a*2<b) puts("NO");
        else {
            ll x=2*a-b;
            if(x%3==0) puts("YES");
            else puts("NO");
        }
    }
}