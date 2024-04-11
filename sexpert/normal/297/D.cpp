#include <bits/stdc++.h>
using namespace std;

int h, w, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w >> k;
    vector<string> row, col;
    for(int i = 0; i < 2*h - 1; i++) {
        string s;
        cin >> s;
        if(i % 2)
            col.push_back(s);
        else
            row.push_back(s);
    }
    vector<vector<int>> grid(h);
    if(k == 1) {
        int cE = 0, cN = 0;
        for(auto s : col)
            for(auto c : s) {
                if(c == 'E')
                    cE++;
                else
                    cN++;
            }

        for(auto s : row)
            for(auto c : s) {
                if(c == 'E')
                    cE++;
                else
                    cN++;
            }

        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                grid[i].push_back(1);

        if(cE >= 3*cN) {
            cout << "YES\n";
            for(int i = 0; i < h; i++) {
                for(int j = 0; j < w; j++)
                    cout << grid[i][j] << " ";
                cout << '\n';
            }
        }
        else
            cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if(w > h) {
        for(int i = 0; i < h; i++) {
            string s = row[i];
            grid[i].push_back(1);
            for(auto c : s) {
                if(c == 'E')
                    grid[i].push_back(grid[i].back());
                else
                    grid[i].push_back(3 - grid[i].back());
            }
        }
        for(int i = 0; i < h - 1; i++) {
            string s = col[i];
            int good = 0;
            for(int j = 0; j < w; j++)
                if((s[j] == 'E' && grid[i][j] == grid[i + 1][j]) || (s[j] == 'N' && grid[i][j] != grid[i + 1][j]))
                    good++;
            if(2*good < w) {
                for(auto &x : grid[i + 1])
                    x = 3 - x;
            }
        }
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cout << grid[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else {
        swap(w, h);
        swap(row, col);
        grid = vector<vector<int>>(h);
        for(int i = 0; i < h; i++) {
            grid[i].push_back(1);
            for(int j = 0; j < w - 1; j++) {
                if(row[j][i] == 'E')
                    grid[i].push_back(grid[i].back());
                else
                    grid[i].push_back(3 - grid[i].back());
            }
        }
        for(int i = 0; i < h - 1; i++) {
            int good = 0;
            for(int j = 0; j < w; j++)
                if((col[j][i] == 'E' && grid[i][j] == grid[i + 1][j]) || (col[j][i] == 'N' && grid[i][j] != grid[i + 1][j]))
                    good++;
            if(2*good < w) {
                for(auto &x : grid[i + 1])
                    x = 3 - x;
            }
        }

        for(int j = 0; j < w; j++) {
            for(int i = 0; i < h; i++) {
                cout << grid[i][j] << " ";
            }
            cout << '\n';
        }
    }
}