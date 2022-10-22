#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

const int n = 50;

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
    int a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    cout << n << " " << n << "\n";
    int color[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < n / 2) {
                color[i][j] = 0;
            } else {
                color[i][j] = 3;
            }
        }
    }
    a[0]--;
    a[3]--;
    bool fl = true;
    for (int i = 0; i < n / 2; i += 2) {
        for (int j = 0; j < n; j += 2) {
            fl = false;
            for (int k = 1; k < 4; k++) {
                if (a[k]) {
                    a[k]--;
                    color[i][j] = k;
                    fl = true;
                    break;
                }
            }
            if (!fl) break;
        }
        if (!fl) break;
    }
    for (int i = n / 2 + 1; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            if (!a[0]) break;
            a[0]--;
            color[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (char) ('A' + color[i][j]);
        }
        cout << "\n";
    }
}