#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

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
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int> > table(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            table[i][j] = (c == '.' ? 1 : 0);
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        int free = 0;
        for (j = 0; j < min(m, k); j++) {
            free += table[i][j];
        }
        if (free == k) {
            cnt++;
        }
        for (; j < m; j++) {
            free -= table[i][j - k];
            free += table[i][j];
            if (free == k) {
                cnt++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int j = 0;
        int free = 0;
        for (j = 0; j < min(n, k); j++) {
            free += table[j][i];
        }
        if (free == k) {
            cnt++;
        }
        for (; j < n; j++) {
            free -= table[j - k][i];
            free += table[j][i];
            if (free == k) {
                cnt++;
            }
        }
    }
    if (k == 1) {
        cnt /= 2;
    }
    cout << cnt;
}