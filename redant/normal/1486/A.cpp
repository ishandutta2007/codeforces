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
LL a[MX];
int n;

int solve() {
    REP(i, n) {
        if (a[i] < i)
            return 0;
        a[i+1] += a[i] - i;
    }
    return 1;
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