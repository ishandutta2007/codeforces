#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <utility>
#include <tuple>

using namespace std;
    
void
process()
{
    int m, k;
    cin >> m >> k;
    vector< int > a(k, 0);
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
    }
    vector< int > t(m - 1, 0), r(m - 1, 0);
    vector< int > eat(k, 0);
    for (int i = 0; i < m - 1; ++i) {
        cin >> t[i] >> r[i];
        if (t[i]) {
            eat[t[i] - 1]++;
        }
    }
    auto min_pos_it = std::find(r.begin(), r.end(), 1);
    if (min_pos_it == r.end()) {
        // no refusions
        int sum_blind = 0;
        for (auto x : t) {
            if (!x) {
                ++sum_blind;
            } else {
                --a[x - 1];
            }
        }
        string ans = "";
        for (int i = 0; i < k; ++i) {
            ans += (a[i] <= sum_blind) ? "Y" : "N";
        }
        cout << ans << '\n';
    } else {
        int min_pos = min_pos_it - r.begin();
        vector< int > is_fail(k, 1);
        for (int i = min_pos; i < m - 1; ++i) {
            if (t[i]) {
                is_fail[t[i] - 1] = 0;
            }
        }
        vector< int > part_eat(k, 0);
        int sum_blind = 0, partial_blind = 0;
        for (int i = 0; i < min_pos; ++i) {
            if (!t[i]) {
                ++sum_blind;
                ++partial_blind;
            } else {
                part_eat[t[i] - 1]++;
            }
        }
        for (int i = min_pos; i < m - 1; ++i) {
            if (!t[i]) {
                ++sum_blind;
            }
        }
        int first_fail_id = -1;
        for (int i = 0; i < k; ++i) {
            if (!is_fail[i]) {
                continue;
            }
            if (first_fail_id == -1 || (a[first_fail_id] - part_eat[first_fail_id] >
                        a[i] - part_eat[i])) {
                first_fail_id = i;
            }
        }
        string ans = "";
        for (int i = 0; i < k; ++i) {
            ans += "N";
        }
        for (int i = 0; i < k; ++i) {
            if (is_fail[i] && a[i] <= part_eat[i] + partial_blind) {
                ans[i] = 'Y';
            } else if (a[i] <= eat[i] + 
                    (sum_blind - (a[first_fail_id] - part_eat[first_fail_id]))) {
                ans[i] = 'Y';
            }
        }
        cout << ans << '\n';
    }
}
    
int
main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        process();
    }
    return 0;
}