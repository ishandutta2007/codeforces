#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q, a[200000], ranges[200000] = {0};
    cin >> n >> q;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<q; i++) {
        int l, r;
        cin >> l >> r;
        ranges[l-1]++;
        if (r < n)
            ranges[r]--;
    }

    for (int i=1; i<n; i++)
        ranges[i] += ranges[i-1];

    sort(a, a + n);
    sort(ranges, ranges + n);
    long long ret = 0;
    for (int i=0; i<n; i++)
        ret += (long long) a[i] * ranges[i];

    cout << ret << "\n";

    return 0;
}