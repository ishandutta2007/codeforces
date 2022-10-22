#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;

const int D = 8;
vector <int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector <int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
int n;

bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
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
    cin >> n;
    vector <vector <bool> > a(n, vector <bool> (n, 0));
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    ax--, ay--, bx--, by--, cx--, cy--;
    for (int d = 0; d < D; d++) {
        int x = ax, y = ay;
        while (isCorrect(x, y)) {
            a[x][y] = true;
            x += dx[d];
            y += dy[d];
            //cout << x << " " << y << "\n";
        }
    }
    vector <vector <bool> > can(n, vector <bool> (n, false));
    can[bx][by] = true;
    queue <pair <int, int> > q;
    q.push({bx, by});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        //cout << x << " " << y << "\n";
        q.pop();
        for (int d = 0; d < D; d++) {
            int x1 = x + dx[d], y1 = y + dy[d];
            if (!isCorrect(x1, y1)) continue;
            if (can[x1][y1] || a[x1][y1]) continue;
            can[x1][y1] = true;
            q.push({x1, y1});
        }
    }
    cout << (can[cx][cy] ? "YES" : "NO");
}