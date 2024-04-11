#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll to = 0, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        sum += k;
        to += ((i % 2) ? k / 2 : (k + 1) / 2);
    }
    cout << min(to, sum - to) << '\n';
}