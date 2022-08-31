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
    int r = 0;
    int s = 0, k = 1;
    while (s < n) {
        ++r;
        s += k++;
    }
    int d = s - n;
    return r + (d == 1); 
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