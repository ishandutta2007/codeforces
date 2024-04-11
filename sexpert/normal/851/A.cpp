#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, t;
    cin >> n >> k >> t;
    cout << min({t, n + k - t, k}) << '\n';
}