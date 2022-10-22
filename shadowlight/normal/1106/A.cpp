#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

vector <int> dx = {0, -1, -1, 1, 1};
vector <int> dy = {0, -1, 1, -1, 1};

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
    int n;
    cin >> n;
    vector <vector <char> > a(n, vector <char> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            bool can = true;
            for (int d = 0; d < 5; d++) {
                int x = i + dx[d], y = j + dy[d];
                if (a[x][y] == '.') {
                    can = false;
                    break;
                }
            }
            if (can) res++;
        }
    }
    cout << res;
}