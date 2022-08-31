#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 300005;
int n, m;
int st[2 * SZ];

void update(int idx, int l, int r, int ql, int qr, int x) {
    // cout << tl << ", " << tr << "   " << ql << ", " << qr << endl;
    if (ql > qr) return;
    if (st[idx]) return;
    if (l == ql && r <= qr) {
        // cout<<tl<<","<<tr<<" = "<<x<<endl;
        st[idx] = x;
        return;
    }
    int m = (l + r) >> 1;
    update(idx + 1, l, m, ql, min(m, qr), x);
    update(idx + 2 * (m - l + 1), m+1, r, max(m+1, ql), qr, x);
}

void push(int idx, int l, int r, int x) {
    if (st[idx]) x = st[idx];
    if (l == r) {
        // ans[tl] = x;
        cout << x << " ";
        return;
    }
    int m = (l + r) >> 1;
    push(idx + 1, l, m, x);
    push(idx + 2 * (m - l + 1), m + 1, r, x);
}

int main() {
    setIO();
    cin>>n>>m;
    for (int i = 1; i <= m; i++) {
        int ql, qr, qx;
        cin >> ql >> qr >> qx;
        update(1, 1, n, ql, qx - 1, qx);
        update(1, 1, n, qx + 1, qr, qx);
    }
    push(1, 1, n, 0);
    cout<<endl;
    return 0;
}