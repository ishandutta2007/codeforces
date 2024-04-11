#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll a,b,x,y,z;
    ll t = 0, k = 0;
    cin >> a >> b;
    cin >> x >> y >> z;
    t = 2 * x + y;
    k = y + 3 * z;
    ll ans = (t >= a ? t - a : 0) + (k >= b ? k - b : 0);
    cout << ans;
}