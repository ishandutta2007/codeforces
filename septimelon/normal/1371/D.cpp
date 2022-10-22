#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> a(n, vector<int>(n, 0));
    int cx = -1, cy = -1;
    for (int i = 0; i < k; ++i) {
        ++cx;
        ++cy;
        if (cy == n) {
            ++cx;
            cy = 0;
        }
        while (cx >= n) {
            cx -= n;
        }
        a[cx][cy] = 1;
    }
    
    if (k % n == 0) {
        cout << "0\n";
    } else {
        cout << "2\n";
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
       solve();
    }
   
    return 0;
}