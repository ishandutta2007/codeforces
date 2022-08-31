#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 5;
int a[MX];
int n;

int solve() {
    for (int i = 1; i < 15; i++) {
        int b[2] = {0};
        REP(j, 4)
            b[(i>>j)&1] += a[j];
        if (b[0] == b[1])
            return true;
    }
    return false;
}

int main() {
    setIO();
    n = 4;
    REP(i, n) {
        cin>>a[i];
    }
    cout<<(solve()?"YES":"NO")<<"\n";    
    return 0;
}