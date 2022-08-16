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

const int MX = 200005;
int a, b, k;
int ac[MX], bc[MX];
int A[MX], B[MX];

LL solve() {
    REP(i, a) ac[i+1] = 0;
    REP(i, b) bc[i+1] = 0;
    REP(i, k) {
        cin >> A[i];
        ac[A[i]]++;
    }
    REP(j, k) {
        cin >> B[j];
        bc[B[j]]++;
    }
    LL r = 0;
    REP(i, k) {
        LL p = k - ac[A[i]] - bc[B[i]] + 1;
        r += p;
    }
    return r >> 1;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>a>>b>>k;
        cout<<solve()<<"\n";
    }
    
    return 0;
}