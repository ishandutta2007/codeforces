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

int t3(int i, int j, int k) {
    if (a[i] <= a[j] && a[j] <= a[k])
        return 0;
    if (a[i] >= a[j] && a[j] >= a[k])
        return 0;
    return 1;
}

int f(int l, int r) {
    int n = r - l + 1;
    if (n <= 2) return 1;
    if (n == 3) {
        return t3(l, l+1, r);
    }
    return t3(l, l+1, l+2) && t3(l, l+1, l+3) && t3(l, l+2, l+3) && t3(l+1, l+2, l+3);
}

int solve() {
    int r = 0;
    REP(i, n)
        for (int j = max(0, i - 3); j <= i; j++) {
            r += f(j, i);
        }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}