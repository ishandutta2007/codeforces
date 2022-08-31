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

int solve() {
    int p = 0;
    while ((1<<p)<=n) ++p;
    return (1<<(p-1))-1;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        cout<<solve()<<"\n";
    }
    
    return 0;
}