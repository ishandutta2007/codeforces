#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll n, r;
        cin >> n >> r;
        r = min(n, r);
        if(n == r)
            cout << r*(r - 1)/2 + 1 << '\n';
        else
            cout << r*(r + 1)/2 << '\n';
    }
}