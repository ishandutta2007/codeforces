#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll ans;
ll n, k, a, b;

ll calc(int x) {
//    cout<<x<<endl;
    if (x == 1) return 0;
    ll q = x / k, r = x % k;
    if (q == 0) return (r - 1) * a;
    if (r) return calc(q * k) + r * a;
    if ((q * k - q) * a < b) return calc(q) + a * (q * k - q);
    else {
//        if (x == 18) cout<<calc(q);
        return calc(q) + b;
    }
}

int main() {
    scanf("%I64d %I64d %I64d %I64d", &n, &k, &a, &b);
//    cout<<calc(2);
    if (k == 1) {
        printf("%I64d\n", a * n - a);
    }
    else {
        printf("%I64d\n", calc(n));
    }
	return 0;
}