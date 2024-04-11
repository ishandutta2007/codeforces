#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--) {
        ll c, s;
        cin >> c >> s;
        ll d = s / c;
        s %= c;
        cout << d * d * c + (d + d + 1) * s << '\n';
    }
}