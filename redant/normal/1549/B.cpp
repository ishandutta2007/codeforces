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
string a, b;

int solve() {
    int r = 0;
    REP(i, n) {
        if (b[i] == '0')
            continue;
        if (a[i] == '0')
            ++r;
        else if (i > 0 && a[i-1] == '1')
            ++r;
        else if (i+1 < n && a[i+1] == '1') {
            a[i+1] = '2';
            ++r;
        }
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>a>>b;
        cout<<solve()<<"\n";
    }
    
    return 0;
}