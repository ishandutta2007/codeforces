#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a, b, c, r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> a >> b >> c >> r;
        if(a > b) swap(a, b);
        ll elim = (min(c + r, b) - max(c - r, a));
        cout << b - a - max(0LL, elim) << '\n';
    }
}