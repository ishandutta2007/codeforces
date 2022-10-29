#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> v2i;

const int BAD_VAL = 1000000001;

int
main()
{
    int k;
    cin >> k;
    v2i a(k);
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;
        a[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    map<ll, int> bucket;
    for (int i = 0; i < k; ++i) {
        for (int x : a[i]) {
            bucket[x] = i;
        }
    }
    vector<ll> arr_sum(k, 0ll);
    for (int i = 0; i < k; ++i) {
        arr_sum[i] = accumulate(a[i].begin(), a[i].end(), 0ll);
    }
    ll total_sum = accumulate(arr_sum.begin(), arr_sum.end(), 0ll);
    // cerr << total_sum << endl;
    vi fill_mask(1 << k, BAD_VAL);
    if (total_sum % k == 0) {
        total_sum /= k;
        for (int i = 0; i < k; ++i) {
            for (int x : a[i]) {
                int used_mask = 0;
                int cur_id = i;
                ll cur_num = x;
                // cerr << "Start " << i << ' ' << x << endl;
                do {
                    used_mask |= (1 << cur_id);
                    cur_num = total_sum - (arr_sum[cur_id] - cur_num);
                    auto it = bucket.find(cur_num);
                    cur_id = (it == bucket.end()) ? -1 : it->second;
                    // cerr << cur_num << ' ' << cur_id << endl;
                } while (cur_id != -1 && !(used_mask & (1 << cur_id)));
                // cerr << "----" << endl;
                if (cur_id == i && cur_num == x) {
                    fill_mask[used_mask] = x;
                    // cerr << i << ' ' << x << ' ' << used_mask << endl;
                }
            }
        }
    }
    vi dp(1 << k, -1);
    for (int i = 0; i < (1 << k); ++i) {
        if (fill_mask[i] != BAD_VAL) {
            dp[i] = 0;
        } else {
            for (int v = (i - 1) & i; v; v = (v - 1) & i) {
                if (dp[v] != -1 && dp[i ^ v] != -1) {
                    dp[i] = v;
                    break;
                }
            }
        }
    }
    if (dp[(1 << k) - 1] != -1) {
        cout << "Yes\n";
        vi val(k, 0), to(k, -1);
        for (int v = (1 << k) - 1; v; v = dp[v]) {
            int cur_num = fill_mask[v ^ dp[v]];
            int cur_id = bucket.at(cur_num);
            int used_mask = 0;
            do {
                used_mask |= (1 << cur_id);
                int prev_id = cur_id;
                cur_num = total_sum - (arr_sum[cur_id] - cur_num);
                cur_id = bucket.at(cur_num);
                val[cur_id] = cur_num;
                to[cur_id] = prev_id;
            } while (!(used_mask & (1 << cur_id)));
        }
        for (int i = 0; i < k; ++i) {
            cout << val[i] << ' ' << to[i] + 1 << '\n';
        }
    } else {
        cout << "No\n";
    }
    return 0;
}