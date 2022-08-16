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
int d[MX];
int n;
LL H;

LL solve() {
    LL a = 0, b = 0;
    REP(i, n) {
        b += d[i];
        a = min(a, b);
        if (H + b <= 0) {
            return i + 1;
        }
    }
    if (b >= 0) return -1;
    LL k = 1 + (H + a - 1) / -b;
    LL r = n * k;
    H -= k * -b;
    // cout << -a << ", " << -b << ", " << r << endl;
    // cout << H << endl;
    REP(i, n) {
        H += d[i];
        if (H <= 0) {
            return r + i + 1;
        }
    }
    assert(false);
    return -1;
}

int main() {
    setIO();
    cin>>H>>n;
    REP(i, n) {
        cin>>d[i];
    }
    cout<<solve()<<"\n";    
    return 0;
}