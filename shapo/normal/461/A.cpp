#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< ll > v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll res = 0ll;
    for (int i = 0; i < n; ++i) {
        res += v[i] * (i + 1);
        if (i != n - 1) {
            res += v[i];
        }
    }
    cout << res << '\n';
    return 0;
}