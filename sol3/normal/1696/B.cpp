#include <bits/stdc++.h>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
    register char c = getchar();
    register int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    return x * f;
}

int a[200005];

int main() {
    int t = qread();
    while (t--) {
        int n = qread();
        bool flg0 = 1, flg1 = 1;
        for (int i = 1;i <= n;i++) {
            a[i] = qread();
            if (a[i] != 0) flg0 = 0;
        }
        if (flg0) {
            cout << 0 << endl;
            continue;
        }
        int l, r;
        for (int i = 1;i <= n;i++) {
            if (a[i]) {
                l = i;
                break;
            }
        }
        for (int i = n;i >= 1;i--) {
            if (a[i]) {
                r = i;
                break;
            }
        }
        for (int i = l;i <= r;i++) {
            if (!a[i]) {
                flg1 = 0;
                break;
            }
        }
        if (flg1) cout << 1 << endl;
        else cout << 2 << endl;
    }
    return 0;
}