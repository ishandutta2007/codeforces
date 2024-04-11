#include <bits/stdc++.h>
using namespace std;

int b[4000], dp[4000][4000];
set<int> pos[4000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> v;
    for (int i=0; i<n; i++) {
        cin >> b[i];
        v.push_back(b[i]);
    }

    sort(v.begin(), v.end());
    unordered_map<int, int> compression;
    for (int i=0; i<n; i++)
        compression[v[i]] = i;
    for (int i=0; i<n; i++) {
        b[i] = compression[b[i]];
        pos[b[i]].insert(i);
    }

    int ret = 0;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            dp[i][j] = 1;
            auto it = pos[j].lower_bound(i);
            if (it != pos[j].begin())
                dp[i][j] = dp[*--it][b[i]] + 1;
            ret = max(ret, dp[i][j]);
        }

    cout << ret << "\n";

    return 0;
}