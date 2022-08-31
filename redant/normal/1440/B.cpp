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
int n, k;

LL solve() {
    LL r = 0;
    int mp = n * k - n / 2;
    REP(i, k) {
        r += a[mp];
        mp -= n / 2 + 1;
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        REP(i, n*k) {
            cin>>a[i+1];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}