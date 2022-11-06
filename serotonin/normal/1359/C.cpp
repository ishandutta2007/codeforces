#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 5e5+5;

ll h, c, t;
char s[sz];

double fnc(ll x)
{
    double cc = c * x;
    double hh = h * (x + 1);
    x = 2 * x + 1;
    double res = (cc + hh) / x;
    return abs(t - res);
}

int main()
{
    ll tc;
    cin >> tc;
    while(tc--) {
        scanf("%lld %lld %lld", &h, &c, &t);

        if(t >= h) puts("1");
        else if(t <= (h + c) / 2) puts("2");
        else {
            ll yh = h - t, yc = t - c;
            // x * yc = x * yh + yh
            ll x = yh / (yc - yh);
            if(fnc(x+1) < fnc(x)) x++;
            printf("%lld\n", 2*x+1);
        }
    }
}