#include <bits/stdc++.h>
using namespace std;

int cnt[100001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    int ret = 0;
    map<int, int> mp;
    for (int i=0; i<n; i++) {
        int u;
        cin >> u;
        if (cnt[u] != 0) {
            if (--mp[cnt[u]] == 0)
                mp.erase(cnt[u]);
        }
        cnt[u]++;
        mp[cnt[u]]++;
        if (mp.size() == 1) {
            if (mp.begin()->first == 1 || mp.begin()->second == 1)
                ret = i + 1;
            else
                continue;
        } else if (mp.size() == 2) {
            pair<int, int> a = *mp.begin();
            pair<int, int> b = *mp.rbegin();
            // p.first - cnt of ribbon
            // p.second - number of types of ribbon with that cnt

            // case 1: 1 1 1 2
            if (a.first == 1 && a.second == 1 || b.first == 1 && b.second == 1)
                ret = i + 1;

            // case 2: 1 1 1 2 2
            else {
                if (a.first > b.first)
                    swap(a, b);
                if (b.first - a.first == 1 && b.second == 1)
                    ret = i + 1;
                else
                    continue;
            }

        } else
            continue;
    }

    cout << ret << "\n";

    return 0;
}