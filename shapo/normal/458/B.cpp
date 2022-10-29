#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll
stopPoint(const vector< ll > &to, const vector< ll > &from)
{
    ll res = 0LL;
    ll sum = accumulate(from.begin(), from.end(), 0LL);
    res = sum;
    int sz = int(to.size());
    for (int i = sz - 2; i >= 0; --i) {
        res += min(to[i], sum);
    }
    return res;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> m >> n;
    vector< ll > a(m), b(n);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    ll res = min(stopPoint(a, b), stopPoint(b, a));
    cout << res << '\n';
    return 0;
}