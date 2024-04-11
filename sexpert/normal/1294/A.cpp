#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b, c, x;
        cin >> a >> b >> c >> x;
        int s = a + b + c + x;
        if(s % 3) {
            cout << "NO\n";
            continue;
        }
        s /= 3;
        if(s >= a && s >= b && s >= c)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}