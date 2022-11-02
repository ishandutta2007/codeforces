#include <bits/stdc++.h>
#define sz(x) (int((x).size()))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
template<typename T> bool domax(T &a, T b) { return (b > a ? (a = b, true) : false); }
template<typename T> bool domin(T &a, T b) { return (b < a ? (a = b, true) : false); }
typedef long long ll;

const int maxn = 100*1000+5;

int Y, X, n, y[maxn], x[maxn];
ll tt[maxn];
std::vector<int> p[maxn+maxn], mm[maxn+maxn];
std::vector<int> *m = mm+maxn;
bool donep[maxn+maxn], donemm[maxn+maxn];
bool *donem = donemm+maxn;

int main() {
    scanf("%d%d%d", &X, &Y, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", x+i, y+i);
        p[x[i]+y[i]].pb(i);
        m[x[i]-y[i]].pb(i);
        tt[i] = 1e16;
    }
    int cy = 0, cx = 0, dy = 1, dx = 1;
    ll t = 0;
    do {
        //printf("at (%d, %d), going in (%d, %d)\n", cy, cx, dy, dx);
        if (dy == dx) {
            if (!donem[cx - cy]) {
                donem[cx - cy] = true;
                for (int &i : m[cx - cy]) domin(tt[i], t + (y[i] - cy) / dy);
            }
        } else {
            if (!donep[cx + cy]) {
                donep[cx + cy] = true;
                for (int &i : p[cx + cy]) domin(tt[i], t + (x[i] - cx) / dx);
            }
        }
        int ty, tx;
        if (dy == 1) ty = Y - cy;
        else ty = cy;
        //printf("dy = %d, cy = %d, Y = %d, ty = %d\n", dy, cy, Y, ty);
        if (dx == 1) tx = X - cx;
        else tx = cx;
        int tt = std::min(ty, tx);
        t += tt;
        cy += dy * tt;
        cx += dx * tt;
        if (cy == 0 || cy == Y) dy = -dy;
        if (cx == 0 || cx == X) dx = -dx;
    } while (!((cy == 0 || cy == Y) && (cx == 0 || cx == X)));
    for (int i = 0; i < n; i++) if (tt[i] == 1e16) tt[i] = -1;
    for (int i = 0; i < n; i++) printf("%lld\n", tt[i]);
}