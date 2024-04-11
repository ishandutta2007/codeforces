#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll A, B, ans = 0;
    int t;
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> A >> B;
        for(ll x = 9; x <= B; x = 10*x + 9)
            ans += A;
        cout << ans << '\n';
    }
}