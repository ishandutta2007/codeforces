#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector< int > f(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }
    sort(f.begin(), f.end());
    int res = 0, i = 0;
    for (int curF = 2; curF <= f.back(); ++curF) {
        while (i < n && f[i] < curF) {
            ++i;
        }
        res += 2 * ((n - i + k - 1) / k) - 1;
    }
    res += f.back() - 1;
    cout << res << '\n';
    return 0;
}