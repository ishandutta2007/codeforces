#include <bits/stdc++.h>

using namespace std;

int
advance(const vector<int>& arr, int start, int val)
{
    int n = int(arr.size());
    while (start < n && arr[start] != val) ++start;
    return start;
}

int
main()
{
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    vector<int> avail_ones;
    avail_ones.reserve(n);
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 1) {
            avail_ones.push_back(i);
        }
    }
    int next_val[4] = {-1, -1, -1, -1};
    for (int i = 0; i < 4; ++i) {
        next_val[i] = advance(a, next_val[i] + 1, i);
    }
    vector<pair<int, int>> ans;
    ans.reserve(2 * n);
    bool fail = false;
    for (int i = 0; i < n && !fail; ++i) {
        if (a[i] == 0 || next_val[a[i]] != i) continue;
        next_val[a[i]] = advance(a, next_val[a[i]] + 1, a[i]);
        if (a[i] == 3) {
            int nv = min(min(next_val[2], next_val[3]), next_val[1]);
            if (nv == n) {
                fail = true;
                break;
            } else {
                ans.push_back({i, i});
                ans.push_back({i, nv});
            }
        } else if (a[i] == 2) {
            int nv = next_val[1];
            if (nv == n) {
                fail = true;
                break;
            } else {
                ans.push_back({i, i});
                ans.push_back({i, nv});
                next_val[1] = advance(a, next_val[1] + 1, 1);
            }
        } else if (a[i] == 1) {
            ans.push_back({i, i});
        } else { // a[i] == 0
        }
    }
    if (!fail) {
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x + 1 << ' ' << y + 1 << '\n';
        }
    } else {
        cout << "-1\n";
    }
    return 0;
}