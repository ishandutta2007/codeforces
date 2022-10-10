#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k, q, cnt[200000] = {0}, prefixSum[200000];
    cin >> n >> k >> q;
    for (int i=0; i<n; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l-1]++;
        if (r < 200000) cnt[r]--;
    }

    prefixSum[0] = cnt[0] >= k;
    for (int i=1; i<200000; i++) {
        cnt[i] += cnt[i-1];
        prefixSum[i] = prefixSum[i-1] + (cnt[i] >= k);
    }

    for (int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        cout << prefixSum[b-1] - (a > 1 ? prefixSum[a-2] : 0) << "\n";
    }

    return 0;
}