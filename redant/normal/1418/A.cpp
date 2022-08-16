#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL x, y, k;

LL solve() {
    LL a = ((y+1)*k-1)/(x-1);
    if((1+a*(x-1)) < (k*y+k)) a++;
    // debug(a);
    return a+k;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>x>>y>>k;
        LL r = solve();
        cout<<r<<"\n";
    }
    
    return 0;
}