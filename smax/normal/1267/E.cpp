#include <bits/stdc++.h>
using namespace std;

int a[100][100];
vector<int> ret[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin >> a[i][j];

    int k = INT_MAX, candidate;
    for (int j=0; j<n-1; j++) {
        int balance = 0;
        vector<pair<int, int>> stations;
        for (int i=0; i<m; i++) {
            stations.emplace_back(a[i][n-1] - a[i][j], i + 1);
            balance += a[i][n-1] - a[i][j];
        }

        sort(stations.begin(), stations.end(), greater<pair<int, int>>());
        int i = 0;
        while (i < m && balance > 0) {
            balance -= stations[i].first;
            ret[j].push_back(stations[i].second);
            i++;
        }

        if (i < k) {
            k = i;
            candidate = j;
        }
    }

    cout << k << "\n";
    for (int i : ret[candidate])
        cout << i << " ";
    cout << "\n";

    return 0;
}