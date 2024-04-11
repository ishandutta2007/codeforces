#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 107;
const double EPS = 1e-8;
const int LOGN = 30;

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    int n, m;
    cin >> n >> m;
    vector <pair <int, int> > a(m);
    int ans = -1;
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i < MAXN; i++) {
        bool fl = 0;
        for (auto p : a) {
            int id = p.first, num = p.second;
            if (id <= (num - 1) * i || id > num * i) {
                fl = 1;
                break;
            }
        }
        if (!fl) {
            if (ans == -1) {
                ans = (n - 1) / i + 1;
            } else if (ans != (n - 1) / i + 1) {
                cout << "-1";
                return 0;
            }
        }
    }
    if (ans == -1) {
        cout << -1;
        return 0;
    }
    cout << ans;
}