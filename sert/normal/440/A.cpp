#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 34;
ll n, x, sum;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x;
        sum += x;
    }
    cout << (n + 1) * n / 2 - sum;

    return 0;
}