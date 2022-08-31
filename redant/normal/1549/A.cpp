#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;

void solve() {
    map<int, int> m;
    for (int i = 2;;i++) {
        int mod = n % i;
        if (m.count(mod)) {
            cout << m[mod] << " " << i << "\n";
            break;
        }
        m[mod] = i;
    }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        solve();
    }
    
    return 0;
}