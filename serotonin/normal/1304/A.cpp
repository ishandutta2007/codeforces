#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=105;

int main()
{
    int tcs;
    cin >> tcs;
    while(tcs--) {
        ll x,y,a,b;
        scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
        ll d=y-x;
        ll z=d/(a+b);
        if(d%(a+b)) puts("-1");
        else printf("%lld\n", z);
    }
}