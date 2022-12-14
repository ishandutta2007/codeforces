#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[300005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    for(int i=1; i<=300000; ++i) a[i] = a[i-1] ^ i;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (a[n - 1] == m) cout << n << '\n';
        else if ((a[n - 1] ^ n) == m) cout << n + 2 << '\n';
        else cout << n + 1 << '\n';
    }
}