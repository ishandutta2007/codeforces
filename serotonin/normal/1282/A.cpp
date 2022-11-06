#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz=3e5+5;

int main()
{
    int t;
    cin >> t;
    while(t--) {
        ll a,b,c,r;
        cin >> a >> b >> c >> r;
        if(a>b) swap(a,b);
        ll x=max(c-r, a), y=min(c+r, b);
        ll z=max(y-x, 0LL);
        cout << b-a-z << endl;
    }
}