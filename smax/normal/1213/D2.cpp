#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    vector<int> steps[200001];
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int a, cnt = 0;
        cin >> a;
        while (a > 0) {
            steps[a].push_back(cnt);
            a /= 2;
            cnt++;
        }
        steps[0].push_back(cnt);
    }

    int ret = INT_MAX;
    for (int i=0; i<=200000; i++)
        if (steps[i].size() >= k) {
            int sum = 0;
            sort(steps[i].begin(), steps[i].end());
            for (int j=0; j<k; j++)
                sum += steps[i][j];
            ret = min(ret, sum);
        }

    cout << ret << "\n";

    return 0;
}