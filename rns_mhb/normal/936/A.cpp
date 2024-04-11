#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll k, d, t;
    scanf("%I64d%I64d%I64d", &k, &d, &t);
    ll cnt = k / d;
    if(k % d > 0) cnt ++;
    ll r = d * cnt - k;
    ll gas = 2 * t / (2 * k + r);
    ll rem = (2 * t) % (2 * k + r);
    double ans = cnt * d * gas;
    if(rem <= 2 * k) ans += rem * 0.5;
    else ans += rem - k;
    printf("%.1lf\n", ans);
}