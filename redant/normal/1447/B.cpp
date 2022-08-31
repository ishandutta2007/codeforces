#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 305;
int a[MX];
int n, m, k;

int solve() {
    sort(a, a+k);
    int r = 0;
    int i = 0;
    for (; i + 1 < k; i += 2) {
        r += max(a[i]+a[i+1],-a[i]-a[i+1]);
    }
    if (i < k) r += a[i];
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        k=0;
        REP(i, n) REP(j, m) {
            cin>>a[k++];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}