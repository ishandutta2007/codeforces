#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,k;

int main() {
    cin >> n >> k;
    ll l, r;
    if(k <= 2) return !printf("0");

    l = (k % 2 ? k/2 : k/2-1), r = k / 2 + 1;
    if(r > n) return !printf("0");

    ll res = min(l, n - r + 1);
    cout << res;

}