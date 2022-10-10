#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> pts(100000);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            int c;
            cin >> c;
            c--;
            pts[c].emplace_back(i, j);
        }
    
    long long ret = 0;
    for (auto &v : pts)
        if (!v.empty())
            for (int rep=0; rep<2; rep++) {
                sort(v.begin(), v.end());
                int cnt = 0;
                long long sum = 0;
                for (auto &[x, y] : v) {
                    ret += (long long) cnt * x - sum;
                    cnt++;
                    sum += x;
                    swap(x, y);
                }
            }
    cout << ret << "\n";
    
    return 0;
}