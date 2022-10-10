#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k, a[100000], queries[100000] = {0};
    long long diff[100000] = {0};
    pair<int, pair<int, int>> operations[100000];
    cin >> n >> m >> k;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<m; i++)
        cin >> operations[i].first >> operations[i].second.first >> operations[i].second.second;
    for (int i=0; i<k; i++) {
        int x, y;
        cin >> x >> y;
        queries[x-1]++;
        if (y < m)
            queries[y]--;
    }

    for (int i=0; i<m; i++) {
        if (i > 0) queries[i] += queries[i-1];
        diff[operations[i].first-1] += (long long) operations[i].second.second * queries[i];
        if (operations[i].second.first < n)
            diff[operations[i].second.first] -= (long long) operations[i].second.second * queries[i];
    }

    for (int i=0; i<n; i++) {
        if (i > 0) diff[i] += diff[i-1];
        cout << a[i] + diff[i] << " ";
    }
    cout << "\n";

    return 0;
}