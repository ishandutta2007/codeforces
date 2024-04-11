#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll st = n * ((k - 1)/(n - 1));
        k -= (n - 1)*((k - 1)/(n - 1));
        cout << st + k << '\n';
    }
}