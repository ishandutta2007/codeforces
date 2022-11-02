#include<bits/stdc++.h>
using namespace std;
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}
#define N 400010

int mx[N], n, m;

inline void update(int x, int y) {for(; x <= n; x += x & -x) chkmax(mx[x], y);}

inline int query(int x) {
    int ret = 0;
    for(; x; x &= x - 1) chkmax(ret, mx[x]);
    return ret;
}

struct tree {
    int hi, ps, quiz;
    bool re;
    bool operator < (const tree &T) const {return hi < T.hi;}
}h[N << 1];

int a[N], lft[N], rht[N], cnt[N], gas[N], val[N], mxlen;
bool must[N];

int main() {
    int i, j, k, L, R, pos, len, rlt;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i ++) {
        scanf("%d", &k);
        h[i].ps = i;
        h[i].hi = k;
        h[i].re = 1;
    }
    for(i = 1; i <= m; i ++) {
        scanf("%d%d", a + i, &k);
        h[i + n].hi = k;
        h[i + n].ps = a[i];
        h[i + n].re = 0;
        h[i + n].quiz = i;
    }
    sort(h + 1, h + n + m + 1);
    fill(cnt, cnt + m + 4, 1);
    for(i = j = 1; i <= n + m; i = j) {
        while(h[i].hi == h[j].hi) j ++;
        for(k = i; k < j; k ++) {
            pos = h[k].ps;
            L = query(pos - 1);
            if(h[k].re) lft[pos] = L + 1;
            else cnt[h[k].quiz] += L;
        }
        for(k = i; k < j; k ++) if(h[k].re) {
            pos = h[k].ps;
            update(pos, lft[pos]);
        }
    }
    memset(mx, 0, sizeof mx);
    for(i = j = n + m; i; i = j) {
        while(h[i].hi == h[j].hi) j --;
        for(k = i; k > j; k --) {
            pos = n + 1 - h[k].ps;
            R = query(pos - 1);
            if(h[k].re) rht[pos] = R + 1;
            else cnt[h[k].quiz] += R;
        }
        for(k = i; k > j; k --) if(h[k].re) {
            pos = n + 1 - h[k].ps;
            update(pos, rht[pos]);
        }
    }
    for(i = 1; i <= n; i ++) chkmax(mxlen, lft[i]);
    for(i = 1; i <= n; i ++) {
        len = lft[i] + rht[n + 1 - i] - 1;
        if(len == mxlen) {
            gas[lft[i]] ++;
            val[lft[i]] = i;
        }
    }
    for(i = 1; i <= mxlen; i ++) if(gas[i] == 1) must[val[i]] = 1;
    for(i = 1; i <= m; i ++) {
        rlt = cnt[i];
        chkmax(rlt, mxlen - must[a[i]]);
        printf("%d\n", rlt);
    }
}