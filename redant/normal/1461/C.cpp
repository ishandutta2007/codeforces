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
int n, m;

double solve() {
    int mn = 0;
    REP(i, n) {
        if (a[n-i] != n-i) {
            mn = n-i;
            break;
        }
    }
    double s = (mn == 0);
    double ns = (mn > 0);
    REP(i, m) {
        int x; double p;
        cin >> x >> p;
        if (x >= mn) {
            s += ns * p;
            ns *= (1. - p);
        }
    }
    return s;
}

int main() {
    setIO();
    cout << fixed << setprecision(20);
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            cin>>a[i+1];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}