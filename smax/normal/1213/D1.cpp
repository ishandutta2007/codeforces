#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k, ret = 0, a[50], freq[200001] = {0};
    unordered_set<int> pos;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        freq[a[i]]++;
        if (freq[a[i]] == k) {
            cout << "0\n";
            return 0;
        }
        int nn = a[i];
        while (nn > 0) {
            pos.insert(nn);
            nn /= 2;
            if (i < k)
                ret++;
        }
    }
    sort(a, a + n);

    for (int i : pos) {
        int co = lower_bound(a, a + n, i) - a, g = upper_bound(a, a + n, i) - a;
        if (n - co < k)
            continue;
        int thisOne = 0;
        int cnt = freq[i];
        for (int j=g; cnt<k && j<n; j++) {
            int adder = 0, nn = a[j];
            while (nn > i) {
                nn /= 2;
                adder++;
            }
            if (nn == i) {
                thisOne += adder;
                cnt++;
            }
        }
        if (cnt == k)
            ret = min(ret, thisOne);
    }

    cout << ret << "\n";

    return 0;
}