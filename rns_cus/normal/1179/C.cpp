#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline char nc() {
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
template <class T> inline void read(T &x){
	char c=nc(),b=1;
	for (;!(c>='0'&&c<='9'||c==EOF);c=nc()) if (c=='-') b=-b;
	for (x=0;c>='0'&&c<='9';x=x*10+c-'0',c=nc()); x*=b;
}

#define N 1000100

int cnt[N], mx[N << 2], addv[N << 2];
#define le v << 1
#define ri v << 1 | 1
#define mi (vl + vr >> 1)
inline void apply(int v, int d) {
    addv[v] += d;
    mx[v] += d;
}
inline void push_dn(int v) {
    if (addv[v]) {
        apply(le, addv[v]);
        apply(ri, addv[v]);
        addv[v] = 0;
    }
}
inline void push_up(int v) {
    mx[v] = max(mx[le], mx[ri]);
}

void build(int v, int vl, int vr) {
    addv[v] = 0;
    if (vl == vr) mx[v] = cnt[vl];
    else {
        build(le, vl, mi), build(ri, mi + 1, vr);
        push_up(v);
    }
}
void modify(int v, int vl, int vr, int l, int r, int d) {
    if (l > vr || vl > r) return;
    if (l <= vl && vr <= r) apply(v, d);
    else {
        push_dn(v);
        modify(le, vl, mi, l, r, d);
        modify(ri, mi + 1, vr, l, r, d);
        push_up(v);
    }
}
int query(int v, int vl, int vr) {
    if (vl == vr) return vl;
    push_dn(v);
    if (mx[ri] > 0) return query(ri, mi + 1, vr);
    else return query(le, vl, mi);
}
#undef le
#undef ri
#undef mi

int a[N], b[N];

int main() {
    int n, m;
    read(n), read(m);
    for (int i = 1; i <= n; i ++) read(a[i]), cnt[a[i]] ++;
    for (int i = 1; i <= m; i ++) read(b[i]), cnt[b[i]] --;
    int T = 1e6;
    for (int i = T; i >= 1; i --) cnt[i] += cnt[i+1];
    build(1, 1, T);
    int q;
    read(q);
    while (q --) {
        int ty, i, x;
        read(ty), read(i), read(x);
        if (ty == 1) {
            if (a[i] < x) modify(1, 1, T, a[i] + 1, x, 1);
            else if (x < a[i]) modify(1, 1, T, x + 1, a[i], -1);
            if (mx[1] <= 0) puts("-1");
            else printf("%d\n", query(1, 1, T));
            a[i] = x;
        }
        else {
            if (b[i] < x) modify(1, 1, T, b[i] + 1, x, -1);
            else if (x < b[i]) modify(1, 1, T, x + 1, b[i], 1);
            if (mx[1] <= 0) puts("-1");
            else printf("%d\n", query(1, 1, T));
            b[i] = x;
        }
    }

}