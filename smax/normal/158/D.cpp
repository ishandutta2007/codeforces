#include <bits/stdc++.h>
using namespace std;

int t[20000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, ret = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> t[i];
        ret += t[i];
    }

    for (int d=2; d<=n/3; d++)
        if (n % d == 0) {
            int sum[6666] = {};
            for (int i=0; i<n; i++)
                sum[i%d] += t[i];
            for (int i=0; i<d; i++)
                ret = max(ret, sum[i]);
        }

    cout << ret << "\n";

    return 0;
}