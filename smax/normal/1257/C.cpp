#include <bits/stdc++.h>
using namespace std;

int a[200000];
vector<int> cnt[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
            cin >> a[i];

        for (int i=1; i<=n; i++)
            cnt[i].clear();

        for (int i=0; i<n; i++)
            cnt[a[i]].push_back(i);

        int ret = INT_MAX;
        for (int i=1; i<=n; i++)
            if (cnt[i].size() >= 2)
                for (int j=1; j<cnt[i].size(); j++)
                    ret = min(ret, cnt[i][j] - cnt[i][j-1] + 1);

        cout << (ret == INT_MAX ? -1 : ret) << "\n";
    }

    return 0;
}