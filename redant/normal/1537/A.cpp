#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 55;
int a[MX];
int n;

int solve() {
    int sum = 0;
    REP(i, n) sum += a[i];
    if (sum == n) return 0;
    if (sum < n) return 1;
    return sum - n;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";    
    }
    
    return 0;
}