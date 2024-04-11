#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m;
vector<vector<char>> grid, ans;
vector<vector<int>> cnt;
vector<ii> cert;

bool good(int w) {
    vector<vector<int>> ps(n + 1, vector<int>(m + 1));
    cert.clear();
    for(int c = w; c + w < m; c++) {
        deque<ii> window;
        vi result;
        int k = 2*w + 1;
        for(int i = 0, j = 0; i + k <= n; i++) {
            while(j < i + k) {
                while(window.size() && cnt[j][c - w] <= window.back().first)
                    window.pop_back();
                window.push_back({cnt[j][c - w], j});
                j++;
            }
            while(window.size() && window.front().second < i)
                window.pop_front();
            result.push_back(window.front().first);
        }
        //for(auto x : result)
        //   cout << x << " ";
        //cout << endl;
        for(int r = w; r + w < n; r++) {
            if(result[r - w] >= 2*w + 1) {
                cert.push_back({r, c});
                ps[r - w][c - w]++;
                ps[r - w][c + w + 1]--;
                ps[r + w + 1][c - w]--;
                ps[r + w + 1][c + w + 1]++;
            }
        }
    }
    //cout << "k = " << w << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i)
                ps[i][j] += ps[i - 1][j];
            if(j)
                ps[i][j] += ps[i][j - 1];
            if(i && j)
                ps[i][j] -= ps[i - 1][j - 1];
            ans[i][j] = '.';
        }
    }
    for(auto p : cert)
        ans[p.first][p.second] = 'X';
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }*/
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            //cout << ps[i][j] << " ";
            if(grid[i][j] == 'X' && ps[i][j] == 0)
                return false;
        }
        //cout << endl;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    ans = grid;
    cnt.assign(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    for(int i = 0; i < n; i++) {
        cnt[i][m - 1] = (grid[i][m - 1] == 'X');
        for(int j = m - 2; j >= 0; j--)
            cnt[i][j] = (grid[i][j] == 'X' ? cnt[i][j + 1] + 1 : 0);
    }
    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << cnt[i][j] << " ";
        }
        cout << '\n';
    }*/
    int lo = 0, hi = min(n, m);
    while(lo < hi) {
        int mi = (lo + hi + 1)/2;
        if(good(mi))
            lo = mi;
        else
            hi = mi - 1;
    }
    cout << lo << endl;
    good(lo);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}