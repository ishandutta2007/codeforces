#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, c0, c1, h;
string s;

int solve() {
    int count[2] = {0};
    for (char c : s)
        count[c-'0']++;
    int r = count[0] * c0 + count[1] * c1;
    r = min(r, count[1] * h + n * c0);
    r = min(r, count[0] * h + n * c1);
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>c0>>c1>>h>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}