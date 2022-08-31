#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n;
string s;

bool solve() {
    int m = 0;
    REP(i, n) {
        if (s[n-1-i] == ')') ++m;
        else break;
    }
    return m > n - m;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>s;
        cout<<(solve()?"Yes":"No")<<"\n";
    }
    
    return 0;
}