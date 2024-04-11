#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    if(y < n) {
        cout << -1 << endl;
        return 0;
    }
    if((y - n + 1)*(y - n + 1) + n - 1 < x) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= n - 1; i++)
        cout << 1 << endl;
    cout << (y - n + 1) << endl;
}