#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n % 2 == 1) {
        int k = (n + 1)/2;
        cout << 2*k*(k + 1) << '\n';
        return 0;
    }
    int k = (n + 2)/2;
    cout << k * k << '\n';
}