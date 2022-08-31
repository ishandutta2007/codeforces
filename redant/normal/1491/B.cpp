#include <bits/stdc++.h>
using namespace std;

template<class T> bool tmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool tmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, u, v;

int solve() {
    int r = 0;

    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>u>>v;
        int pr; cin >> pr;
        int mx = 0;
        REP(i, n-1) {
            int cr; cin >> cr;
            tmax(mx, abs(cr-pr));
            pr = cr;
        }
        int r = 0;
        if (mx == 1) r = min(u, v);
        else if (mx == 0) r = v + min(u, v);
        cout << r << "\n";
    }
    
    return 0;
}