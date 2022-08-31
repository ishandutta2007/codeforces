#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 200005;
int a[MX];
int n;
int m;

bool can(int k) {
    int s = 0;
    for (int i = 0, sub = 0; i < n; ) {
        s += max(0, a[i] - sub);
        if (s >= m) return true;
        i++;
        if (i % k == 0) ++sub;
    }
    return s >= m;
}

int solve() {
    sort(a, a+n);
    reverse(a, a+n);
    if (!can(n)) return -1;
    int lo = 0, hi = n;
    while (lo + 1 < hi) {
        int mid = (lo + hi) >> 1;
        if (can(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main() {
    setIO();
    cin>>n>>m;
    REP(i, n) {
        cin>>a[i];
    }
    cout<<solve()<<"\n";    
    return 0;
}