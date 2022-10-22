#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int N = 413;

bool dp[N][N];

int dist(int x1, int y1, int x2, int y2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    return dx * dx + dy * dy;
}

int main() {
    int x, y, n, d;
    cin >> x >> y >> n >> d;

    d *= d;

    int x0 = 200;
    int y0 = 200;

    x += x0;
    y += y0;

    vector<pii> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }


    for(int i = N - 1; i >= 0; i--) {
        for(int j = N - 1; j >= 0; j--) {
            dp[i][j] = false;

            if(dist(x0, y0, i, j) > d) {
                dp[i][j] = true;
                continue;
            }

            for(auto p : a) {
                int x1 = i + p.x, y1 = j + p.y;
                if(x1 < N && y1 < N && !dp[x1][y1]) {
                    dp[i][j] = true;
                    break;
                }
            }
        }
    }

    cout << (dp[x][y] ? "Anton" : "Dasha");
}