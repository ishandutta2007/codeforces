#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n, m, k, a, b, x, y;

LL solve() {
    x = abs(x);
    y = abs(y);    
    LL r = a * (x + y);
    LL mn = min(x, y);
    x -= mn; y -= mn;
    r = min(r, mn * b + a * (x + y));
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>x>>y;
        cin>>a>>b;
        cout<<solve()<<"\n";
    }
    
    return 0;
}