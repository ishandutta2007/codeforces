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
    int now = 0;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        if (l > now) {
            cout << "NO\n";
            return 0;
        }
        now = max(now, r);
    }
    if (now == m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}