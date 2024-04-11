#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        for (int i=0; i<n; i++)
            cin >> b[i];
        
        vector<int> sa = a, sb = b;
        sort(sa.begin(), sa.end());
        sort(sb.begin(), sb.end());
        long long ret = LLONG_MAX;
        for (int x=0; x<3; x++)
            for (int y=0; y<3; y++) {
                long long cur = (x == 0 ? 0 : x == 1 ? abs(a[0] - b[0]) : abs(a[0] - b[n-1])) + (y == 0 ? 0 : y == 1 ? abs(a[n-1] - b[0]) : abs(a[n-1] - b[n-1]));
                if (x == 0) {
                    auto it = lower_bound(sb.begin(), sb.end(), a[0]);
                    cur += min(it == sb.end() ? INT_MAX : abs(a[0] - *it), it == sb.begin() ? INT_MAX : abs(a[0] - *prev(it)));
                }
                if (y == 0) {
                    auto it = lower_bound(sb.begin(), sb.end(), a[n-1]);
                    cur += min(it == sb.end() ? INT_MAX : abs(a[n-1] - *it), it == sb.begin() ? INT_MAX : abs(a[n-1] - *prev(it)));
                }
                if (x != 1 && y != 1) {
                    auto it = lower_bound(sa.begin(), sa.end(), b[0]);
                    cur += min(it == sa.end() ? INT_MAX : abs(b[0] - *it), it == sa.begin() ? INT_MAX : abs(b[0] - *prev(it)));
                }
                if (x != 2 && y != 2) {
                    auto it = lower_bound(sa.begin(), sa.end(), b[n-1]);
                    cur += min(it == sa.end() ? INT_MAX : abs(b[n-1] - *it), it == sa.begin() ? INT_MAX : abs(b[n-1] - *prev(it)));
                }
                ret = min(ret, cur);
            }
        cout << ret << "\n";
    }
    
    return 0;
}