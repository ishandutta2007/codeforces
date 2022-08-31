#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL d, k, p;

bool g(LL x) {
    if (x == 1) return true;
    x -= 2;
    LL k = 3;
    while (2 * k <= x) {
        x -= 2 * k;
        k += 2;
    }
    return x >= k;
}

bool solve() {
    p = (d * d) / (k * k);    
    return g(p);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>d>>k;
        cout<<(solve()?"Ashish":"Utkarsh")<<"\n";
    }
    return 0;
}