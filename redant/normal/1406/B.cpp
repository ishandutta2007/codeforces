#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 100005;
int n, m;
int a[SZ];
LL best;
int lim;

void solve(int u, int need, LL cur) {
    if (need == 0) {
        best = max(best, cur);
        return;
    }
    if (u == n) return;
    if (u == 5 && u != lim) {
        solve(lim, need, cur);
        return;
    }
    solve(u + 1, need, cur);
    solve(u + 1, need - 1, cur * a[u]);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for (int i = 0; i < n; i++) {
            cin>>a[i];
        }
        sort(a, a+n);
        best=-1e18;
        lim=max(5, n-5);
        solve(0, 5, 1);
        cout<<best<<"\n";
    }
    
    return 0;
}