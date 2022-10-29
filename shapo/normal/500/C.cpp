#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector< int > used(n + 1, 0);
    vector< int > w(n + 1, 0);
    vector< int > actions(m + 1, 0);
    vector< int > ans(1);
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    for (int j = 1; j <= m; ++j) {
        cin >> actions[j];
        int cur = actions[j];
        if (!used[cur]) {
            ans.push_back(cur);
            used[cur] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ans.push_back(i);
        }
    }
    /*for (int i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
    cout << endl;*/
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        int cur = 0;
        while (ans[cur] != actions[i]) {
            ++cur;
        }
        for (int j = cur; j > 1; --j) {
            swap(ans[j], ans[j - 1]);
            res += w[ans[j]];
        }
    }
    cout << res << '\n';
    return 0;
}