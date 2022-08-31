#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int a[3][2];   

int f(int a, int b, int c) {
    int aa = min(a, b);
    int bb = max(a, b);
    if (aa < c && c < bb)
        return bb - aa + 2;
    return bb - aa;
}

int solve() {
    REP(i, 2)
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i]) {
            return f(a[0][1-i], a[1][1-i], a[2][1-i]);
        }
    return abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        REP(i, 3) {
            cin>>a[i][0]>>a[i][1];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}