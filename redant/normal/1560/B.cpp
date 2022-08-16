#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        int n = 2 * (b - a);
        int d = n / 2;
        int r = -1;
        int k = b - a + 1;
        if (a <= n && b <= n && c <= n) {
            r = (c > d ? (c-d) : (c+d));
        }
        cout << r << "\n";
    }
    
    return 0;
}