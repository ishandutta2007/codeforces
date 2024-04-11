#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

int n, a, b;

int ans = INF;

void bf(int x, int y, int cnt) {
    if (x == 4 && y == 2) {
        ans = min(ans, cnt);
        return;
    }
    for (int i = 0; i <= 4 - x; i++) {
        for (int j = 0; j <= 2 - y; j++) {
            if (!i && !j) continue;
            if (a * i + b * j > n) continue;
            bf(x + i, y + j, cnt + 1);
        }
    }
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
    cin >> n >> a >> b;
    bf(0, 0, 0);
    cout << ans;
}