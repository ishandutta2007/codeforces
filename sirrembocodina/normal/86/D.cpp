#include "bits/stdc++.h"

#define int long long

using namespace std;

const int K = 500;

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, t;
    cin >> n >> t;
    vector<int> in(n);
    for(int i = 0; i < n; i ++) {
        cin >> in[i];
    }
    vector<int> in2 = in;
    sort(in2.begin(), in2.end());
    map<int, int> to;
    for (int i = 0; i < n; i++) {
        to[in2[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        in[i] = to[in[i]];
    }
    vector<vector<pair<pair<int, int>, int>>> q((n - 1) / K + 1);
    for(int i = 0; i < t; i ++) {
        int l, r;
        cin >> l >> r;
        l--;
        q[l / K].push_back({{r, l}, i});
    }
    vector<int> ans(t);
    for(int i = 0; i < q.size(); i ++) {
        sort(q[i].begin(), q[i].end());
        int l = i * K, r = i * K;
        vector<int> cnt(n);
        int res = 0;
        for (auto x: q[i]) {
            int cur_l = x.first.second;
            int cur_r = x.first.first;
            int cur_ind = x.second;
            while (r < cur_r) {
                res -= cnt[in[r]] * cnt[in[r]] * in2[in[r]];
                cnt[in[r]]++;
                res += cnt[in[r]] * cnt[in[r]] * in2[in[r]];
                r++;
            }
            while (l > cur_l) {
                l--;
                res -= cnt[in[l]] * cnt[in[l]] * in2[in[l]];
                cnt[in[l]]++;
                res += cnt[in[l]] * cnt[in[l]] * in2[in[l]];
            }
            while (l < cur_l) {
                res -= cnt[in[l]] * cnt[in[l]] * in2[in[l]];
                cnt[in[l]]--;
                res += cnt[in[l]] * cnt[in[l]] * in2[in[l]];
                l++;
            }
            ans[cur_ind] = res;
        }
    }
    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}