#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

const int D = 4;
vector <int> dx = {0, -1, 0, 1};
vector <int> dy = {1, 0, -1, 0};

vector <vector <bool> > used;
vector <vector <char> > a;
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
    a.resize(n, vector <char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    used.resize(n, vector <bool> (m, false));
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            if (a[i][j] == '.') {
                used[i][j] = true;
                continue;
            }
            bool can = true;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (x == 1 && y == 1) continue;
                    if (a[i + x][j + y] == '.') {
                        can = false;
                        break;
                    }
                }
            }
            if (!can) continue;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (x == 1 && y == 1) continue;
                    used[i + x][j + y] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#' && !used[i][j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
}