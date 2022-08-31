#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 100005;
int a[MX];
LL ps[MX];
int n, q;
set<LL> sums;

void addps(int l, int r) {
    LL s = ps[r];
    if (l > 0) s -= ps[l-1];
    // cout << l << ", " << r << " = " << s << "\n";
    sums.insert(s);
}

void go(int l, int r) {
    if (l > r) return;
    addps(l, r);
    if (l == r || a[l] == a[r]) return;
    int mid = (a[l] + a[r]) / 2;
    int split = upper_bound(a, a+n, mid) - a;
    // cout << l << ", " << r << " = " << split << "\n";
    // cout << a[l] << " " << a[r] << " ~ " << a[mid] << "\n";
    go(l, split-1);
    go(split, r);
}

void doit() {
    sums.clear();
    sort(a, a+n);
    ps[0] = a[0];
    REP(i, n-1) ps[i+1] = ps[i] + a[i+1];
    go(0, n-1);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>q;
        REP(i, n) {
            cin>>a[i];
        }
        doit();
        while (q--) {
            int s; cin >> s;
            cout << (sums.count(s) ? "Yes" : "No") << "\n";
        }
    }
    
    return 0;
}