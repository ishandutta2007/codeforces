#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> pi2;

int a[12][2000];
int n, m;
//vector<vector<int>> rez;

int check(vector<vector<int>>& v) {
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        int cmax = 0;
        for (int j = 0; j < v[i].size(); j++) {
            cmax = max(cmax, v[i][j]);
        }
        ans += cmax;
    }
    return ans;
}

int mov(vector<vector<int>>& v, int col) {
    int ans = 0;
    int buf;
    for (int q = 0; q < n; q++) {
        buf = v[0][col];
        for (int i = 1; i < v.size(); i++) {
            v[i - 1][col] = v[i][col];
        }
        v[v.size() - 1][col] = buf;
        if (col == v[0].size()) {
            ans = max(check(v), ans);
        }
        else {
            ans = max(ans, mov(v, col + 1));
        }
    }
    return ans;
}

int vert(vector<int> ind) {
    vector<vector<int>> b(n, vector<int>(ind.size()));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < ind.size(); j++) {
            b[i][j] = a[i][ind[j]];
        }
    }
    return mov(b, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for (int qq = 0; qq < t; qq++) {
        cin >> n >> m;
        vector<pi2> a2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                a2.push_back(pi2(a[i][j], pii(i, j)));
            }
        }
        vector<int> cols(100, -1);
        sort(a2.begin(), a2.end());
        reverse(a2.begin(), a2.end());
        vector<int> column(1, a2[0].second.second);
        for (int i = 1; i < a2.size(); i++) {
            if (column.size() == n)
                break;
            bool fitt = true;
            for (int j = 0; j < column.size(); j++) {
                if (column[j] == a2[i].second.second) {
                    fitt = false;
                }
            }
            if (fitt) {
                column.push_back(a2[i].second.second);
            }
        }
        cout << vert(column) << '\n';
    }
    return 0;
}