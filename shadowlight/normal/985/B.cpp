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
    vector <int> cnt(m, 0);
    vector <vector <int> > a(n, vector <int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            int x = c - '0';
            a[i][j] = x;
            cnt[j] += x;
        }
    }
    for (int i = 0; i < n; i++) {
        bool can = true;
        for (int j = 0; j < m; j++) {
            if (a[i][j] && cnt[j] < 2) {
                can = false;
                break;
            }
        }
        if (can) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}