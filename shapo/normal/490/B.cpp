#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int
main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< int > before(1005000, 0), after = before;
    vector< int > from(n), to(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        from[i] = a, to[i] = b;
        before[b] = a;
        after[a] = b;
    }
    vector< int > ans(n, 0);
    int cur = after[0], pos = 1;
    while (cur != 0) {
        ans[pos] = cur;
        pos += 2;
        cur = after[cur];
    }
    cur = before[0], pos = n - 2;
    while (cur != 0) {
        ans[pos] = cur;
        pos -= 2;
        cur = before[cur];
    }
    if (n % 2 == 1) {
        vector< int > cnt(1005000, 0);
        for (int i = 0; i < n; ++i) {
            cnt[from[i]]++;
            cnt[to[i]]--;
        }
        int v1 = max_element(cnt.begin(), cnt.end()) - cnt.begin();
        int v2 = min_element(cnt.begin(), cnt.end()) - cnt.begin();
        int cur = v1, pos = 0;
        while (cur != v2) {
            ans[pos] = cur;
            pos += 2;
            cur = after[cur];
        }
        ans[n - 1] = v2;
    }
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}