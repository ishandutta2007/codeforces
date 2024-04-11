#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 10;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    if (m == 1) cout << n - 1 << "\n";
    else cout << n * (m-1) << "\n";
}