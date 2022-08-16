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

int solve() {
    while (n > 0) {
        if (n % 2021 == 0)
            return 1;
        n -= 2020;
    }
    return n == 0;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}