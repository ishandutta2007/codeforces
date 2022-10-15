#include <bits/stdc++.h>

inline long long read() {
    char c, _c; long long x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1 << 21;

int T, n, x, y, z, sum, ans, f[6][6][6], g[6][6][6], c[N];
long long b[N];
std::vector<int> a[6][6][6];
std::map<int, int> vis;

inline int mex(int x, int y, int z) {
    bool mx[4] = {false, false, false, false};
    mx[x] = mx[y] = mx[z] = true;
    if (!mx[0]) { return 0; }
    if (!mx[1]) { return 1; }
    if (!mx[2]) { return 2; }
    return 3;
}

void dfs(int s, int d) {
    d++;
    int xl = s >> (30 - x * 6) & 3;
    int ym = s >> (32 - y * 6) & 3;
    int zr = s >> (34 - z * 6) & 3;
    int l = mex(xl, ym, zr), m = mex(xl, zr, zr), r = mex(xl, ym, ym);
    s >>= 6; s |= l << 24; s |= m << 26; s |= r << 28;
    if (vis[s] > 0) { f[x][y][z] = d; g[x][y][z] = d - vis[s]; return; }
    a[x][y][z].push_back(s); vis[s] = d;
    dfs(s, d);
}

int main() {
    for (x = 1; x <= 5; x++) {
        for (y = 1; y <= 5; y++) {
            for (z = y; z <= 5; z++) {
                vis.clear();
                a[x][y][z].push_back(-1); 
                a[x][y][z].push_back(0); vis[0] = 1;
                dfs(0, 1);
            }
        }
    }
    for (int T = read(); T; T--) {
        n = read(); x = read(); y = read(); z = read();
        if (y > z) { std::swap(y, z); }
        sum = 0;
        for (int i = 0; i < n; i++) {
            b[i] = read();
            if (b[i] >= f[x][y][z]) {
                b[i] -= ((b[i] - f[x][y][z]) / g[x][y][z] + 1) * g[x][y][z];
            }
            int s = a[x][y][z][b[i]];
            int xl = s >> (30 - x * 6) & 3;
            int ym = s >> (32 - y * 6) & 3;
            int zr = s >> (34 - z * 6) & 3;
            c[i] = mex(xl, ym, zr);
            sum ^= c[i];
        }
        if (sum == 0) {
            printf("0\n");
        } else  {
            ans = 0; 
            for (int i = 0; i < n; i++) {
                int s = a[x][y][z][b[i]];   
                int xl = s >> (30 - x * 6) & 3;
                int ym = s >> (32 - y * 6) & 3;
                int zr = s >> (34 - z * 6) & 3;
                if ((sum ^ c[i] ^ xl) == 0) { ans++; }
                if ((sum ^ c[i] ^ ym) == 0) { ans++; }
                if ((sum ^ c[i] ^ zr) == 0) { ans++; }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}