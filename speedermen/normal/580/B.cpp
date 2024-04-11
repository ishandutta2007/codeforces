#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1e5 + 10;

pair < int, int > all[MaxN];
vector < long long > sum;
int n, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> all[i].first >> all[i].second;
    }
    sort(all, all + n);
    sum.resize(n);
    for (int i = 0; i < n; ++i) {
        sum[i] = all[i].second;
        if (i > 0) {
            sum[i] += sum[i - 1];
        }
    }
    long long ans = -1;
    for (int l = 0; l < n; ++l) {
        int r = upper_bound(all, all + n, make_pair(all[l].first + d, -1)) - all - 1;
        ans = max(ans, sum[r] - (l > 0 ? sum[l - 1] : 0));
    }
    cout << ans << endl;
    return 0;
}