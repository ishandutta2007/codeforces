#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

pii
compute_range(int x, pii prev_range)
{
    int prev_l, prev_r;
    tie(prev_l, prev_r) = prev_range;
    int r = x + prev_r - 2;
    if (x > prev_r) {
        return make_pair(x - prev_r + 2, r);
    } else if (x < prev_l) {
        return make_pair(prev_l - x + 2, r);
    } else {
        if ((x - prev_l) % 2 == 0) {
            return make_pair(4, r);
        } else {
            return make_pair(3, r);
        }
    }
}

int
get_prev_tgt(int tgt, pii prev_range, int x)
{
    int prev_l, prev_r;
    tie(prev_l, prev_r) = prev_range;
    if (x > prev_r) {
        // We need to check right border of range (i.e. prev_r)
        return prev_r;
    } else if (x < prev_l) {
        // For given t, we have range [t - x + 2, t + x - 2]
        // We want to find t, such that tgt in [t - x + 2, t + x - 2]
        // At least one of the following cases holds:
        // (a) tgt in [prev_l - x + 2; prev_l + x - 2]
        // (b) tgt in [prev_r - x + 2; prev_r + x - 2]
        // (c) There is t in [prev_l; prev_r] such that tgt = t + x - 2
        if (prev_l + x - 2 >= tgt) { // Check for case(a)
            return prev_l;
        } else if (prev_r - x + 2 <= tgt) { // Check for case (b)
            return prev_r;
        } else { // Case (c) must hold
            return tgt - x + 2;
        }
    } else {
        // x in [prev_l; prev_r]
        if ((x - prev_l) % 2 == 0) {
            if (tgt <= 2 * x - 2) {
                return x;
            } else {
                return tgt - x + 2;
            }
        } else {
            if (tgt <= 2 * x - 3) {
                return x - 1;
            } else {
                return tgt - x + 2;
            }
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    int f;
    cin >> f;
    vector<int> rev_ord(f);
    vector<int> a(f);
    for (int i = 0; i < f; ++i) {
        cin >> a[i];
    }
    {
        vector<pii> sort_a(f);
        for (int i = 0; i < f; ++i) {
            sort_a[i] = make_pair(a[i], i);
        }
        sort(sort_a.begin(), sort_a.end());
        for (int i = 0; i < f; ++i) {
            a[i] = sort_a[i].first;
            rev_ord[sort_a[i].second] = i;
        }
    }
    vector<pii> range(f);
    range[0] = make_pair(a[0], a[0]);
    for (int i = 1; i < f; ++i) {
        range[i] = compute_range(a[i], range[i - 1]);
    }
    // cerr << range.back().first << " " << range.back().second << endl;
    vector<int> rules(f, 0);
    for (int i = f - 1, tgt = range.back().first; i > 0; --i) {
        int prev_tgt = get_prev_tgt(tgt, range[i - 1], a[i]);
        rules[i] = (a[i] + prev_tgt - tgt) / 2;
        tgt = prev_tgt;
        // cerr << tgt << endl;
    }
    // Get rid of rules that use only one edge
    {
        vector<int> bad_rules, good_rules;
        for (int i = 1; i < f; ++i) {
            if (a[i] == 3) continue;
            if (rules[i] == 1) {
                bad_rules.push_back(i);
            } else if (rules[i] > 2) {
                good_rules.push_back(i);
            }
        }
        reverse(good_rules.begin(), good_rules.end());
        while (false && !bad_rules.empty() && !good_rules.empty()) {
            int u = bad_rules.back();
            int v = good_rules.back();
            rules[u]++;
            rules[v]--;
            bad_rules.pop_back();
            if (rules[v] == 2) {
                good_rules.pop_back();
            }
        }
    }
    // Recover answer with given rules
    vector<vector<int>> ans(f);
    int v_cnt = a[0];
    vector<int> cur_hull(a[0]);
    for (int i = 0; i < a[0]; ++i) {
        cur_hull[i] = i;
    }
    ans[0] = cur_hull;
    int idx = 1;
    if (a[0] == 3) {
        int tgt = 3;
        while (idx < f && a[idx] == 3) {
            int del_e = rules[idx];
            tgt = tgt + 3 - 2 * del_e;
            ++idx;
        }
        // Count number of triangles we want to collapse
        int cnt = idx - (tgt - 2) + 1;
        for (int i = 1; i < cnt; i += 2) {
            ans[i] = {0, v_cnt - 1, v_cnt};
            ans[i + 1] = {1, v_cnt - 1, v_cnt};
            cur_hull.back() = v_cnt;
            ++v_cnt;
        }
        // Add remaining triangles
        for (int i = cnt; i < idx; ++i) {
            ans[i] = {0, v_cnt - 1, v_cnt};
            cur_hull.push_back(v_cnt);
            ++v_cnt;
        }
    }
    for (int i = idx; i < f; ++i) {
        /*
        for (int x : cur_hull) {
            cerr << x + 1 << ' ';
        }
        cerr << endl;
        */
        ans[i].reserve(a[i]);
        // cerr << a[i] << ' ' << rules[i] << endl;
        int del_e = rules[i];
        int add_e = a[i] - del_e;
        ans[i].push_back(cur_hull.back());
        for (int j = 0; j < del_e - 1; ++j) {
            cur_hull.pop_back();
            ans[i].push_back(cur_hull.back());
        }
        for (int j = 0; j < add_e - 1; ++j) {
            cur_hull.push_back(v_cnt);
            ans[i].push_back(cur_hull.back());
            v_cnt++;
        }
        ans[i].push_back(0);
    }
    cout << v_cnt << endl;
    for (int i = 0; i < f; ++i) {
        for (int v : ans[rev_ord[i]]) {
            cout << v + 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}