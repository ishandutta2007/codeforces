#include <bits/stdc++.h>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> r(n, 0), a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // find unique ages
    vector<int> ages = a;
    sort(ages.begin(), ages.end());
    ages.erase(unique(ages.begin(), ages.end()), ages.end());

    int q;
    cin >> q;
    vector<tuple<int, int, int, int>> qs(q);
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        int ages_min = max(a[x], a[y]) - k;
        int ages_max = min(a[x], a[y]) + k;
        ages_min = lower_bound(ages.begin(), ages.end(), ages_min) - ages.begin();
        ages_max = upper_bound(ages.begin(), ages.end(), ages_max) - ages.begin();
        qs[i] = {max(r[x], r[y]), i, ages_min, ages_max};
    }

    sort(qs.rbegin(), qs.rend());

    vector<pair<int, int>> leaders;
    for (int i = 0; i < n; ++i) {
        leaders.push_back({r[i], i});
    }
    vector<int> leader_cnt(n, 0);
    {
        sort(leaders.begin(), leaders.end());
        int v = 2;
        while (v < int(ages.size())) v *= 2;
        vector<int> seg_sum(2 * v, 0);
        for (int l = 0; l < n; ) {
            int r = l;
            while (r < n && leaders[l].first == leaders[r].first) ++r;
            for (int i = l; i < r; ++i) {
                int id = leaders[i].second;
                int age_idx = lower_bound(ages.begin(), ages.end(), a[id]) - ages.begin();
                for (int idx = v + age_idx; idx; idx /= 2) {
                    seg_sum[idx]++;
                }
            }
            for (int i = l; i < r; ++i) {
                int id = leaders[i].second;
                int age_min = lower_bound(ages.begin(), ages.end(), a[id] - k) - ages.begin();
                int age_max = upper_bound(ages.begin(), ages.end(), a[id] + k) - ages.begin();
                age_min += v;
                age_max += v - 1;
                int cnt = 0;
                while (age_min < age_max) {
                    if (age_min % 2 == 1) cnt += seg_sum[age_min];
                    if (age_max % 2 == 0) cnt += seg_sum[age_max];
                    age_min = (age_min + 1) / 2;
                    age_max = (age_max - 1) / 2;
                }
                if (age_min == age_max) cnt += seg_sum[age_min];
                leader_cnt[id] = cnt;
            }
            l = r;
        }
    }

    vector<int> ans(q);
    {
        sort(leaders.rbegin(), leaders.rend());
        int v = 2;
        while (v < int(ages.size())) v *= 2;
        vector<int> seg_max(v * 2, -1);
        for (int l_ptr = 0, q_ptr = 0; q_ptr < q; ++q_ptr) {
            auto [qr, qid, qmin, qmax] = qs[q_ptr];
            while (l_ptr < n && leaders[l_ptr].first >= qr) {
                int id = leaders[l_ptr].second;
                int age_idx = lower_bound(ages.begin(), ages.end(), a[id]) - ages.begin();
                for (int idx = v + age_idx; idx; idx /= 2) {
                    seg_max[idx] = max(seg_max[idx], leader_cnt[id]);
                }
                l_ptr++;
            }
            int res = -1;
            qmin += v, qmax += v - 1;
            while (qmin < qmax) {
                if (qmin % 2 == 1) res = max(res, seg_max[qmin]);
                if (qmax % 2 == 0) res = max(res, seg_max[qmax]);
                qmin = (qmin + 1) / 2;
                qmax = (qmax - 1) / 2;
            }
            if (qmin == qmax) res = max(res, seg_max[qmin]);
            ans[qid] = res;
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}