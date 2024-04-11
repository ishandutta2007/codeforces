#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <utility>

using namespace std;

const int MAXN = 100500;

vector< vector< int > > inv;
int next_pos[2][MAXN];
int n;
vector< pair< int, int > > res;

inline int
find_next(int cur_pos, int delta, int id)
{
    int pos = next_pos[id][cur_pos];
    if (pos != -1) {
        pos += delta - 1;
    }
    return (pos >= 0 && pos < int(inv[id].size())) ? inv[id][pos] : -1;
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector< int > val(n);
    inv.clear();
    inv.resize(2);
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
        val[i]--;
        inv[val[i]].push_back(i);
    }
    res.clear();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            auto it = lower_bound(inv[j].begin(), inv[j].end(), i);
            if (it != inv[j].end()) {
                next_pos[j][i] = it - inv[j].begin();
            } else {
                next_pos[j][i] = -1;
            }
        }
    }
    for (int t = 1; t <= n; ++t) {
        int cnt[2] = {0, 0};
        int cur_pos = 0;
        while (cur_pos != n) {
            int id1 = find_next(cur_pos, t, 0),
                id2 = find_next(cur_pos, t, 1);
            if (id1 == -1 && id2 == -1) {
                cur_pos = -1;
                break;
            } else if (id1 != -1 && (id2 == -1 || id1 < id2)) {
                ++cnt[0];
                cur_pos = id1 + 1;
            } else {
                ++cnt[1];
                cur_pos = id2 + 1;
            }
        }
        if (cur_pos == n && cnt[0] != cnt[1] &&
                inv[max_element(cnt, cnt + 2) - cnt].back() == n - 1) {
            res.push_back({max(cnt[0], cnt[1]), t});
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}