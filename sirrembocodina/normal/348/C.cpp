#include "bits/stdc++.h"

using namespace std;

#define int long long

const int K = 333;

int32_t main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> s(m);
    vector<int> sum(m);
    vector<int> big;
    vector<int> where_in_big(m, -1);
    vector<vector<int>> where(n);
    vector<vector<int>> where_big(n);
    for (int i = 0; i < m; i ++) {
        int l = 0;
        cin >> l;
        s[i].resize(l);
        for (int j = 0; j < l; j ++) {
            cin >> s[i][j];
            s[i][j]--;
            sum[i] += a[s[i][j]];
            where[s[i][j]].push_back(i);
            if (l >= K) {
                where_big[s[i][j]].push_back(i);
            }
        }
        if (l >= K) {
            where_in_big[i] = big.size();
            big.push_back(i);
        }
    }
    vector<vector<int>> pc(m, vector<int>(big.size(), 0));
    // pc[i][j] --  i-   j-  
    for (int i = 0; i < n; i ++) {
        for (auto j : where[i]) {
            for (auto k : where_big[i]) {
                pc[j][where_in_big[k]] += 1;
            }
        }
    }
    vector<int> buf(m, 0);
    for (int iii = 0; iii < q; iii ++) {
        string c;
        cin >> c;
        if (c == "?") {
            int ind;
            cin >> ind;
            ind--;
            if (where_in_big[ind] == -1) {
                int ans = 0;
                for (int i: s[ind]) {
                    ans += a[i];
                }
                for (int i = 0; i < big.size(); i++) {
                    ans += buf[big[i]] * pc[ind][i];
                }
                cout << ans << endl;
            } else {
                cout << sum[ind] << endl;
            }
        }
        else if (c == "+") {
            int ind, x;
            cin >> ind >> x;
            ind--;
            if (where_in_big[ind] == -1) {
                for (int i: s[ind]) {
                    a[i] += x;
                }
                for (int i = 0; i < big.size(); i++) {
                    sum[big[i]] += x * pc[ind][i];
                }
            } else {
                for (int i = 0; i < big.size(); i++) {
                    sum[big[i]] += x * pc[ind][i];
                }
                buf[ind] += x;
            }
        }
    }
    return 0;
}