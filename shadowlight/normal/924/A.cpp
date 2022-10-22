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
    int n, m;
    cin >> n >> m;
    vector <vector <int> > gr(n, vector <int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                gr[i][j] = 1;
            }
        }
    }
    vector <bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = true;
        for (int k = i + 1; k < n; k++) {
            bool fl = false;
            for (int j = 0; j < m; j++) {
                if (gr[k][j] && gr[i][j]) {
                    fl = true;
                    break;
                }
            }
            if (fl) {
                for (int j = 0; j < m; j++) {
                    if (gr[k][j] != gr[i][j]) {
                        cout << "No\n";
                        return 0;
                    }
                }
                used[k] = true;
            }
        }
    }
    cout << "Yes\n";
}