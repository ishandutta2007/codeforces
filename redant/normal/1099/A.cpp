#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 300005;
int a[MX];
int n;

int solve() {
    int r = 0;

    return r; 
}

int main() {
    setIO();
    int w, h;
    cin>>w>>h;

    int ws[2], hs[2];
    REP(i, 2) cin>>ws[i]>>hs[i];

    while (h > 0) {
        w += h;
        REP(i, 2) if (h == hs[i])
            w = max(0, w - ws[i]);
        --h;
    }
    
    cout<<w<<"\n";    
    return 0;
}