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
    int n, s;
    cin >> n >> s;
    s++;
    int now = 0;
    for (int i = 0; i < n; i++) {
        int h, m;
        cin >> h >> m;
        int nxt = 60 * h + m;
        if (nxt - now >= s) {
            cout << now / 60 << " " << now % 60 << "\n";
            return 0;
        }
        now = nxt + s;
    }
    cout << now / 60 << " " << now % 60 << "\n";
}