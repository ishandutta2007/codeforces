#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

const int MX = 2005;
int a[MX];
int n;

int solve() {
    int m = n - 1;
    int r = 0;
    REP(i, n) {
        if (a[i] % 2 == 0) {
            r += m--;
            continue;
        }
        REP(j, i) {
            if (a[j] % 2 == 1 && gcd(a[i], a[j]) > 1) {
                // cout << a[i] << ", " << a[j] << endl;
                ++r;
            }
        }
    }
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