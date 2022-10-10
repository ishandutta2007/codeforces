#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll s, x;
    cin >> s >> x;
    if(s < x || (s%2) != (x%2)) {
        cout << "0\n";
        return 0;
    }
    ll a = (s - x)/2, res = 1;
    if(a & x) {
        cout << "0\n";
        return 0;
    }
    for(ll b = 0; b < 50; b++) {
        if(((1LL << b) & a) == 0 && ((1LL << b) & x) != 0)
            res *= 2;
    }
    if(s == x)
        res -= 2;
    cout << res << '\n';
}