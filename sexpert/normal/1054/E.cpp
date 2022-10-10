#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using op = array<int, 4>;

int n, m;

vector<op> force(vector<vector<string>> &board) {
    vector<op> res;

    for(int j = 1; j < m; j++) {
        for(int x = 0; x < board[0][j].size(); x++)
            res.push_back({1, j + 1, 1, 1});
    }
    for(int i = 1; i < n; i++) {
        for(int x = 0; x < board[i][0].size(); x++)
            res.push_back({i + 1, 1, 1, 1});
    }
    vector<int> ro(m), co(n);
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            for(int ps = (int)board[i][j].size() - 1; ps >= 0; ps--) {
                char c = board[i][j][ps];
                if(c == '0') {
                    ro[j]++;
                    res.push_back({i + 1, j + 1, 1, j + 1});
                }
                else {
                    co[i]++;
                    res.push_back({i + 1, j + 1, i + 1, 1});
                }
            }
        }
    }
    for(int j = 2; j < m; j++) {
        for(int x = 0; x < ro[j]; x++)
            res.push_back({1, j + 1, 1, 2});
    }
    for(int i = 2; i < n; i++) {
        for(int x = 0; x < co[i]; x++)
            res.push_back({i + 1, 1, 2, 1});
    }
    for(int ps = (int)board[0][0].size() - 1; ps >= 0; ps--) {
        char c = board[0][0][ps];
        if(c == '1')
            res.push_back({1, 1, 2, 1});
        else
            res.push_back({1, 1, 1, 2});
    }
    for(int j = 1; j < m; j++) {
        for(int ps = (int)board[0][j].size() - 1; ps >= 0; ps--) {
            char c = board[0][j][ps];
            if(c == '1')
                res.push_back({1, 1, 2, 1});
            else
                res.push_back({1, 1, 1, 2});
        }
    }
    for(int i = 1; i < n; i++) {
        for(int ps = (int)board[i][0].size() - 1; ps >= 0; ps--) {
            char c = board[i][0][ps];
            if(c == '1')
                res.push_back({1, 1, 2, 1});
            else
                res.push_back({1, 1, 1, 2});
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<string>> grid(n, vector<string>(m));
    for(int i = 0; i < n; i++)
        for(auto &s : grid[i])
            cin >> s;

    vector<op> res1 = force(grid);
    for(int i = 0; i < n; i++)
        for(auto &s : grid[i]) {
            cin >> s;
            reverse(s.begin(), s.end());
        }

    vector<op> res2 = force(grid);
    reverse(res2.begin(), res2.end());
    cout << res1.size() + res2.size() << '\n';
    for(auto& [a, b, c, d] : res1)
        cout << a << " " << b << " " << c << " " << d << '\n';
    for(auto& [a, b, c, d] : res2)
        cout << c << " " << d << " " << a << " " << b << '\n';

}