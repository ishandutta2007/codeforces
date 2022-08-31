#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 100005;
int a[MX], b[MX];
int n;

int solve() {
    a[n+1] = 0;
    for (int i = n; i > 1; i--) a[i] += a[i+1];
    for (int i = 1; i < n; i++) b[i] += b[i-1];
    int r = 2e9;
    for (int i = 1; i <= n; i++)
        r = min(r, max(a[i+1], b[i-1]));
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i+1];
        }
        REP(i, n) {
            cin>>b[i+1];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}