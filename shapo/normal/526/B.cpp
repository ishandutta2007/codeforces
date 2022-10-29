#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 2500;

int n;
int a[MAXN];
int sum[MAXN];

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    int cnt_vals = (1 << (n + 1));
    for (int i = 2; i < cnt_vals; ++i) {
        cin >> a[i];
    }
    for (int i = (1 << n); i < cnt_vals; ++i) {
        sum[i] = 0;
    }
    int ans = 0;
    for (int i = (1 << n) - 1; i >= 1; --i) {
        sum[i] = max(sum[i * 2] + a[i * 2], sum[i * 2 + 1] + a[i * 2 + 1]);
        ans += 2 * sum[i] - sum[i * 2] - a[i * 2] - sum[i * 2 + 1] - a[i * 2 + 1];
    }
    cout << ans << endl;
    return 0;
}