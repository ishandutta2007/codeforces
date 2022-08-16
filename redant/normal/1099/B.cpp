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
    int r = sqrt(1.*n);
    if (r*r<n) ++r;
    // cout << r << endl;
    return r + (n + r - 1) / r; 
}

int main() {
    setIO();
    cin>>n;
    cout<<solve()<<"\n";
    return 0;
}