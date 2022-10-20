// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int M = 1000000007;
const long long LM = 1LL << 60;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int q;
    cin >> q;
    vector<vector<int>> que(q);
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            que[i] = { t, x };
        }
        else {
            int x, y;
            cin >> x >> y;
            que[i] = { t, x, y };
        }
    }
    vector<int> ans;
    vector<int> to(500010);
    for (int i = 0; i < 500010; ++i) {
        to[i] = i;
    }
    for (int i = q - 1; i >= 0; --i) {
        int t = que[i][0];
        if (t == 1) {
            ans.push_back(to[que[i][1]]);
        }
        else {
            to[que[i][1]] = to[que[i][2]];
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i] << (i < (int)ans.size() - 1 ? ' ' : '\n');
    }
    return 0;
}