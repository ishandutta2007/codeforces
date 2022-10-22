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

int n;
long long a[200005];

inline void Read() {
    n = qread();
    for (int i = 1;i <= n;i++) a[i] = qread();
}

inline void Solve() {
    for (int i = 1;i <= n;i++) a[i] += a[i - 1];
    if (a[n] != 0) {
        cout << "No" << endl;
        return;
    }
    int pos = 0;
    for (int i = n;i >= 1;i--) {
        if (a[i] != 0) {
            pos = i;
            break;
        }
    }
    for (int i = 1;i <= pos;i++) {
        if (a[i] <= 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int t = qread();
    while (t--) {
        Read();
        Solve();
    }
    return 0;
}