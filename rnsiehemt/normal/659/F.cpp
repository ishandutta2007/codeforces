#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxc = 1005, dy[] = {0,1,0,-1}, dx[] = {-1,0,1,0};

int Y, X, p[maxc*maxc], size[maxc*maxc];
ll k, a[maxc][maxc], b[maxc][maxc];
std::vector<std::tuple<ll, int, int>> v;
bool seen[maxc][maxc];

int find(int i) {
    if (i == p[i]) return i;
    else return p[i] = find(p[i]);
}
void join(int a, int b) {
    a = find(a); b = find(b);
    if (a != b) {
        p[b] = a;
        size[a] += size[b];
    }
}
int count;
void go(int y, int x, ll p) {
    seen[y][x] = true;
    if (count) { b[y][x] = p; count--; }
    else b[y][x] = 0;
    for (int d = 0; d < 4; d++) {
        int ny = y + dy[d], nx = x + dx[d];
        if (0 <= ny && ny < Y && 0 <= nx && nx < X && !seen[ny][nx] && b[ny][nx]) {
            go(ny, nx, p);
        }
    }
}

int main() {
    scanf("%d%d%lld", &Y, &X, &k);
    for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) {
        scanf("%lld", &a[y][x]);
        v.eb(a[y][x], y, x);
        p[y*X+x] = y*X+x;
        size[y*X+x] = 1;
    }
    std::sort(all(v));
    std::reverse(all(v));
    for (auto &tuple : v) {
        ll p; int y, x; std::tie(p, y, x) = tuple;
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (0 <= ny && ny < Y && 0 <= nx && nx < X && b[ny][nx]) {
                join(y*X+x, ny*X+nx);
            }
        }
        int r = find(y*X+x);
        if (k % p == 0 && size[r] >= k/p) {
            count = k/p;
            printf("YES\n");
            go(y, x, p);
            for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) if (!seen[y][x]) b[y][x] = 0;
            for (int y = 0; y < Y; y++) for (int x = 0; x < X; x++) printf("%lld%c", b[y][x], " \n"[x == X-1]);
            return 0;
        }
        b[y][x] = a[y][x];
    }
    printf("NO\n");
}