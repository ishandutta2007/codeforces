#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 300005;
int a[MX];
int n;

int solve() {
    int r = 0;

    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        LL s = 0;
        REP(i, n) {
            int x; cin >> x;
            s += x;
        }
        // cout << "sum = " << s << endl;
        cout << (n - s % n) * (s % n) << endl;
    }
    
    return 0;
}