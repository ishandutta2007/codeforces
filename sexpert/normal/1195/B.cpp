#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    ll n, k;
    cin >> n >> k;
    ll lo = 1, hi = n;
    while(lo < hi) {
        ll mi = (lo + hi + 1)/2;
        ll b = n - mi;
        if(mi*(mi + 1ll)/2 - b <= k)
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << n - lo << '\n';
}