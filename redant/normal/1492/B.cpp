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

const int MX = 100005;
int a[MX];
int pos[MX];
int n;

void solve() {
    int k = n;
    while (k) {
        if (pos[k]) {
            for (int i = pos[k]; i <= n && pos[a[i]]; i++) {
                cout << a[i] << " ";
                pos[a[i]] = 0;
            }
        }
        k--;
    }
    cout << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i+1];
            pos[a[i+1]] = i+1;
        }
        solve();
    }
    
    return 0;
}