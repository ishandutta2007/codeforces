#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, k;

bool solve() {
    if ((n&1) != (k&1)) return false;
    return (1ll*k*k)<=n;
}

int main() {
    setIO();    
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}