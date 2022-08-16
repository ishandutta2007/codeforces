#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n, a, b;

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>a>>b;
        LL m = n;
        n = (n + 1) / 2;
        LL k = (n + a - 1) / a;
        LL r = max(m, n + b * (k - 1));
        cout<<r<<"\n";
    }
    
    return 0;
}