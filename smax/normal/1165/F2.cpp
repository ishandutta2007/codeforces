#include <bits/stdc++.h>
using namespace std;

int k[200000];
vector<int> sales[400000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, sum = 0;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> k[i];
        sum += k[i];
    }

    for (int i=0; i<m; i++) {
        int d, t;
        cin >> d >> t;
        sales[d-1].push_back(t-1);
    }

    int l = 0, r = 2 * sum;
    while (l < r) {
        int days = (l + r) / 2;
        vector<bool> visited(n);
        vector<vector<int>> use(days);
        for (int i=days-1; i>=0; i--)
            for (int t : sales[i])
                if (!visited[t]) {
                    visited[t] = true;
                    use[i].push_back(t);
                }

        int money = 0, tot = sum;
        for (int i=0; i<days; i++) {
            money++;
            for (int t : use[i]) {
                int mn = min(money, k[t]);
                money -= mn;
                tot -= mn;
            }
        }

        if (money >= 2 * tot)
            r = days;
        else
            l = days + 1;
    }

    cout << l << "\n";

    return 0;
}