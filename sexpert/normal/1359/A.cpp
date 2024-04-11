#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int amt = n / k;
    if(m <= amt) {
        cout << m << '\n';
        return;
    }
    cout << amt - (m - amt + k - 2)/(k - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--)
        solve();
}