#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

const int D = 4;
vector <int> dx = {0, 1, 0, -1};
vector <int> dy = {1, 0, -1, 0};
int n, m;

bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    cin >> n >> m;
    vector <vector <char> > a(n, vector <char> (m));
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                sx = i, sy = j;
            }
        }
    }
    vector <vector <int> > data;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) continue;
            for (int k = 0; k < 4; k++) {
                if (i == k || j == k) continue;
                for (int l = 0; l < 4; l++) {
                    if (l == i || l == j || l == k) continue;
                    data.push_back({i, j, k, l});
                }
            }
        }
    }
    string s;
    cin >> s;
    int cnt = 0;
    for (auto mas : data) {
        int x = sx, y = sy;
        for (char c : s) {
            int k = mas[c - '0'];
            x += dx[k], y += dy[k];
            if (!isCorrect(x, y)) {
                break;
            }
            if (a[x][y] == 'E') {
                cnt++;
                break;
            }
            if (a[x][y] == '#') {
                break;
            }
        }
    }
    cout << cnt;
}