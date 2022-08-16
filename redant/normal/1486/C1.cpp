#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;

int isP(int l, int r, int p) {
    if (l >= r) return false;
    cout << "? " << l << " " << r << endl;
    int q; cin >> q;
    return p == q;
}

int sLeft(int p) {
    int l = 1, r = p;
    while (l < r) {
        int m = (l + r + 1) >> 1;
        if (isP(m, p, p))
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int sRight(int p) {
    int l = p, r = n;
    while (l < r) {
        int m = (l + r) >> 1;
        if (isP(p, m, p))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int solve() {
    cout << "? " << 1 << " " << n << endl;
    int p1; cin >> p1;
    if (n == 2)
        return p1 == 1 ? 2 : 1;
    if (p1 == 1) return sRight(1);
    if (p1 == n) return sLeft(n);
    cout << "? " << p1 << " " << n << endl;
    int p2; cin >> p2;
    if (p1 == p2)
        return sRight(p1);
    return sLeft(p1);
}

int main() {
    setIO();
    cin>>n;
    int r = solve();
    cout << "! " << r << endl;
    return 0;
}