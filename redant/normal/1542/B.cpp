#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n, a, b;

int solve() {
    for (LL x = 1; x <= n; x *= a) {
        if ((n - x) % b == 0)
            return 1;
        if (a == 1)
            break;
    }
    return 0;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>a>>b;
        cout<<(solve()?"Yes":"No")<<"\n";
    }
    
    return 0;
}