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
        if((n %2 != k % 2) || n < k * k)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}