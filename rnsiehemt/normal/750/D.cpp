#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 33, maxc = 400;
const int dx[] = {0,1,1,1,0,-1,-1,-1};
const int dy[] = {1,1,0,-1,-1,-1,0,1};

int n, a[maxn], g[maxc][maxc], ans;

int ox, oy;
std::pair<int,int> flip(int d, int x, int y) {
    int dy = y-oy, dx = x-ox;
    if (d%4 == 0) {
        return {ox - dx, oy + dy};
    } else if (d%4 == 1) {
        return {ox + dy, oy + dx};
    } else if (d%4 == 2) {
        return {ox + dx, oy - dy};
    } else {
        return {ox - dy, oy - dx};
    }
}

void go(int i, int d, int x, int y) {
    if (i == n) return;
    int nx = x + dx[d] * a[i];
    int ny = y + dy[d] * a[i];
    go(i+1, (d+1)%8, nx, ny);
    oy = ny; ox = nx;
    for (int y = 0; y < maxc; y++) for (int x = 0; x < maxc; x++) {
        int ny, nx; std::tie(nx, ny) = flip(d, x, y);
        if (0 <= ny && ny < maxc && 0 <= nx && nx < maxc) {
            if (g[y][x] || g[ny][nx]) {
                g[y][x] = g[ny][nx] = 1;
            }
        }
    }
    for (int k = 1; k <= a[i]; k++) {
        g[y + dy[d] * k][x + dx[d] * k] = 1;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    go(0, 0, maxc/2,maxc/2);
    for (int y = 0; y < maxc; y++) for (int x = 0; x < maxc; x++) if (g[y][x]) ans++;
    printf("%d\n", ans);
}