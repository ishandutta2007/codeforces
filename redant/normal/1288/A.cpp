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

int n, d;

bool solve() {
    if (d <= n) return true;
    int sn = sqrt(1. * d) - 3;
    for (int i = 0; i < 6; i++, sn++) {
        if (sn < 1) continue;
        int need = sn + (d + sn) / (sn + 1);
        if (need <= n) return true;
    }
    return false;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>d;
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}