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

const int MX = 30004;
int a[MX];
int b[3];
int n;

void prb() {
    cout << b[0] << " " << b[1] << " " << b[2] << "\n";
}

int solve() {
    REP(i, 3) b[i] = 0;
    REP(i, n) b[a[i]%3]++;
    int r = 0;
    // prb();
    REP(k, 2) 
        REP(i, 3) {
            if (b[i]*3>n) {
                int ex = b[i] - n/3;
                r += ex;
                b[i] -= ex;
                b[(i+1)%3] += ex;
            }
            // prb();
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