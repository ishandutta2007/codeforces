#include <bits/stdc++.h>
using namespace std;

#define N 200200

char s[N];
typedef long long ll;
const int inf = 1e9;

template <class T>
inline void chkmax(T &x, T y) {if (x < y) x = y;}
template <class T>
inline void chkmin(T &x, T y) {if (x > y) x = y;}

inline int dir(char c) {
    if (c == 'D') return 0;
    if (c == 'A') return 1;
    if (c == 'S') return 2;
    if (c == 'W') return 3;
    return -1;
}

struct rect{
    int mnx, mny, mxx, mxy;
    rect() {
        mnx = mny = mxx = mxy = 0;
    }
    rect update(int x, int y) {
        rect rlt = (*this);
        chkmax(rlt.mxx, x), chkmax(rlt.mxy, y);
        chkmin(rlt.mnx, x), chkmin(rlt.mny, y);
        return rlt;
    }
    rect move(int d, int x = 0, int y = 0) {
        rect rlt = *this;
        if (d == 0) rlt.mnx ++, rlt.mxx ++;
        else if (d == 1) rlt.mnx --, rlt.mxx --;
        else if (d == 2) rlt.mny --, rlt.mxy --;
        else rlt.mny ++, rlt.mxy ++;
        return rlt.add(x, y);
    }
    rect add(int x, int y) {
        rect rlt = *this;
        rlt.mnx += x, rlt.mxx += x;
        rlt.mny += y, rlt.mxy += y;
        return rlt;
    }
    friend rect Merge(rect a, rect b) {
        rect rlt = a;
        chkmax(rlt.mxx, b.mxx), chkmax(rlt.mxy, b.mxy);
        chkmin(rlt.mnx, b.mnx), chkmin(rlt.mny, b.mny);
        return rlt;
    }
    ll area() {
        return 1ll * (mxx - mnx + 1) * (mxy - mny + 1);
    }
} pre[N], suf[N];

void Move(int d, int &x, int &y) {
    if (d == 0) x ++;
    else if (d == 1) x --;
    else if (d == 2) y --;
    else y ++;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        pre[0] = suf[n+1] = rect();
        for (int i = 1, cx = 0, cy = 0; i <= n; i ++) {
            Move(dir(s[i]), cx, cy);
            pre[i] = pre[i-1].update(cx, cy);
        }
        for (int i = n; i; i --) {
            suf[i] = suf[i+1].move(dir(s[i])).update(0, 0);
        }
        ll rlt = pre[n].area();
        for (int i = 0, cx = 0, cy = 0; i <= n; i ++) {
            for (int d = 0; d < 4; d ++) {
                chkmin(rlt, Merge(pre[i], suf[i+1].move(d, cx, cy)).area());
            }
            if (i == n) continue;
            int d = dir(s[i+1]);
            Move(d, cx, cy);
        }
        printf("%I64d\n", rlt);
    }
}