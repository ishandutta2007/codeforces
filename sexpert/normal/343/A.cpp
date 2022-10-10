#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, ans = 0;
    cin >> a >> b;
    while(a > 0 && b > 0) {
        if(a >= b) {
            ans += a / b;
            a %= b;
        }
        else {
            ans += b / a;
            b %= a;
        }
    }
    cout << ans << endl;
}