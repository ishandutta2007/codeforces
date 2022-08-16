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

LL n;
set<LL> cubes;

int solve() {
    for (auto x : cubes)
        if (cubes.count(n-x))
            return 1;
    return 0;
}

int main() {
    setIO();
    FOR(i, 1, 10004)
        cubes.insert(1ll*i*i*i);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}