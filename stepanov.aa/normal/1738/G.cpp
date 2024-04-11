#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define flt float

int n, k;
vector<vector<int>> a;
vector<vector<int>> ans;

bool solve() {
    ans.assign(n, vector<int>(n, 1));
    deque<int> x;
    vector<vector<deque<int>>> y(2, vector<deque<int>>(n, deque<int>()));
    for (int i = 0; i < n; i += 1) {
        if (a[i][i] == 1) {
            x.push_back(i);
        }
    }
    for (int i = 0; i < n; i += 1) {
        for (int t = 0; t < 2; t += 1) {
            for (int j = 0; j < n; j += 1) {
                int mi = i + 1 + j;
                int mj = j;
                if (t) {
                    swap(mi, mj);
                }
                if (mi < n && mj < n && a[mi][mj]) {
                    y[t][i].push_back(j);
                }
            }
        }
    }
    vector<vector<int>> lst(2, vector<int>(n + 1, -1));
    int f = n - k + 1;
    for (int i = 0; i < f; i += 1) {
        while (!x.empty() &&
               (x.front() <= lst[0][0] || x.front() <= lst[1][0])) {
            x.pop_front();
        }
        if (x.empty()) {
            return false;
        }
        int w = x.front();
        ans[w][w] = 0;
        x.pop_front();
        for (int t = 0; t < 2; t += 1) {
            int mlst = w;
            for (int j = 0; j < f - i - 1; j += 1) {
                while (!y[t][j].empty() && (y[t][j].front() < mlst ||
                                            y[t][j].front() <= lst[t][j + 1])) {
                    y[t][j].pop_front();
                }
                int x0 = j + 1;
                int y0 = 0;
                if (t) {
                    swap(x0, y0);
                }
                if (y[t][j].empty()) {
                    return false;
                }
                int c = y[t][j].front();
                x0 += c;
                y0 += c;
                y[t][j].pop_front();
                ans[x0][y0] = 0;
                lst[t][j] = c;
                mlst = c;
            }
        }
    }
    return true;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.assign(n, vector<int>(n));
        for (int i = 0; i < n; i += 1) {
            for (int j = 0; j < n; j += 1) {
                char c;
                cin >> c;
                a[i][j] = c - '0';
            }
        }
        if (solve()) {
            cout << "Yes"
                 << "\n";
            for (int i = 0; i < n; i += 1) {
                for (int j = 0; j < n; j += 1) {
                    cout << ans[i][j];
                }
                cout << "\n";
            }
        } else {
            cout << "No"
                 << "\n";
        }
    }
    return 0;
}

/*
1
4 3
1110
0101
1010
0111

*/