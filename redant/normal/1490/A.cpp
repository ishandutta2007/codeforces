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

const int MX = 55;
int a[MX];
int n;

int get(int x, int y) {
    int mx = max(x, y);
    int mn = min(x, y);
    int r = 0;
    int cur = mx;
    while (2 * mn < cur) {
        ++r;
        cur = (cur + 1) / 2;
    }
    return r;
}

int solve() {
    int r = 0;
    REP(i, n-1) r += get(a[i], a[i+1]);
    return r; 
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