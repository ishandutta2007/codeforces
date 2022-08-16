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

const int MX = 200005;
int a[MX];
int n, m, K;

LL nck(int n, int k) {
    assert(k == 3);
    if (n < k) return 0;
    if (k == 0 || n == k) return 1;
    LL r = 1ll * n * (n - 1) / 2;
    r = r * (n - 2) / 3;
    return r;
}


LL solve() {
    sort(a, a+n);
    LL r = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = max(j, i);
        while (j+1 < n && a[j+1] - a[i] <= K)
            ++j;
        int total = j - i + 1;
        int icount = 1;
        while (i+1 < n && a[i+1] == a[i]) {
            ++i;
            ++icount;
        }
        r += nck(total, m) - nck(total - icount, m);
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n; m = 3; K = 2;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}