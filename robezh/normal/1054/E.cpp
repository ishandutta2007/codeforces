#include <bits/stdc++.h>
using namespace std;

const int N = 305;

struct P {
    int x1, y1, x2, y2;
};

struct P2 {
    int x, y;
};

int n, m;
string str[N][N], epc[N][N];
P2 from[N][N][2];
int want[N][2];
int cnt[N][2];
vector<P> res;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> str[i][j];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> epc[i][j];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            reverse(str[i][j].begin(), str[i][j].end());
            reverse(epc[i][j].begin(), epc[i][j].end());
            for(char c : str[i][j]) {
                if(c - '0' != j) {
                    res.push_back({i, j, i, (c - '0')});
                    cnt[i][c - '0']++;
                } else {
                    int ni = (i - 1 >= 0 ? i - 1 : i + 1);
                    res.push_back({i, j, ni, (c - '0')});
                    cnt[ni][c - '0']++;
                }
            }
        }
    }
//    cout << "1: " << res.size() << endl;
    for(int i = 1; i < n; i++) {
        for(int c = 0; c < 2; c++) {
            for(int j = 0; j < cnt[i][c]; j++) {
                res.push_back({i, c, 0, c});
            }
            cnt[0][c] += cnt[i][c];
            cnt[i][c] = 0;
        }
    }
//    cout << "2: " << res.size() << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(j >= 2) {
                from[i][j][0] = {i, 0};
                from[i][j][1] = {i, 1};
            }
            else {
                from[i][j][j] = {(i - 1 >= 0 ? i - 1 : i + 1), j};
                from[i][j][!j] = {i, !j};
            }
            for(char c : epc[i][j]) {
                auto p = from[i][j][c-'0'];
                want[p.x][p.y]++;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < want[i][j]; k++) {
                res.push_back({0, j, i, j});
            }
        }
    }
//    cout << "3: " << res.size() << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(char c : epc[i][j]) {
                auto p = from[i][j][c-'0'];
                res.push_back({p.x, p.y, i, j});
            }
        }
    }
    cout << res.size() << '\n';
    int r = 0;
    for(auto p : res) {
//        cout << ++r << ": ";
        cout << p.x1 + 1 << " " << p.y1 + 1 << " " << p.x2 + 1 << " " << p.y2 + 1 << "\n";
    }

}