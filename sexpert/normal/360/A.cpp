#include <bits/stdc++.h>
using namespace std;

int mx[5005], diff[5005], b[5005];

int main() {
    for(int i = 1; i < 5005; i++)
        mx[i] = 1000000000;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> q;
    for(int i = 0; i < m; i++) {
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        q.push_back({t, l, r, x});
        if(t == 1) {
            for(int j = l; j <= r; j++)
                diff[j] += x;
        }
        if(t == 2) {
            for(int j = l; j <= r; j++)
                mx[j] = min(mx[j], x - diff[j]);
        }
    }
    for(int i = 1; i <= n; i++)
        b[i] = mx[i];
    for(int i = 0; i < m; i++) {
        int t = q[i][0], l = q[i][1], r = q[i][2], x = q[i][3];
        if(t == 1) {
            for(int j = l; j <= r; j++)
                b[j] += x;
        }
        else {
            int mcs = -1000000001;
            for(int j = l; j <= r; j++)
                mcs = max(mcs, b[j]);
            if(mcs != x) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++)
        cout << mx[i] << " ";
    cout << endl;
}