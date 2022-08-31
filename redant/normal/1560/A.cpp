#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 1003;

int main() {
    setIO();
    vector<int> res; res.push_back(0);
    for (int x = 1; res.size() < MX; x++) {
        if (x % 3 != 0 && x%10 != 3)
            res.push_back(x);
    }
    int t, n; cin>>t;
    while(t--) {
        cin>>n;
        cout << res[n] << "\n";
    }
    
    return 0;
}