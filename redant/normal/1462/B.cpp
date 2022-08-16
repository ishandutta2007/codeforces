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
const string s2 = "2020";

bool solve() {
    REP(i, 5) {
        string s3 = s.substr(0, i) + s.substr(n - 4 + i, 4 - i);
        if (s2 == s3) return true;
    }
    return false;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>s;
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}