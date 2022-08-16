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

const int MX = 105;
int a[MX];
int n;

int solve() {
    int c[3] = {0};
    REP(i, n) c[a[i]]++;
    if (c[2] % 2 == 0) {
        return c[1] % 2 == 0;
    }
    if (c[1] < 2) return 0;
    c[1] -= 2;
    return c[1] % 2 == 0;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}