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
int a[MX], b[MX];
int n;

int solve() {
    REP(i, n+1) b[i] = -1;
    REP(i, n) {
        int v = a[i+1];
        if (b[v] == -1) b[v] = i + 1;
        else b[v] = -2;
    }
    int r = -1;
    REP(i, n+1)
        if (b[i] > 0) {
            r = b[i];
            break;
        }
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
        cout<<solve()<<"\n";
    }
    
    return 0;
}