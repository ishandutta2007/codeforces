#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > a(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector <vector <int> > mink(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mink[i][j] = i;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j][i] >= a[j - 1][i]) {
                mink[j][i] = min(mink[j][i], mink[j - 1][i]);
            }
        }
    }
    vector <int> g(n, INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            g[i] = min(g[i], mink[i][j]);
        }
        //cout << g[i] << " ";
    }
    //cout << endl;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (g[r] <= l) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
/*
1 2
0
1 1
1 1
*/