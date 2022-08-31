#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 200005;
int a[MX];
int n, m;

bool poss(int t) {
    LL rem = 0;
    REP(i, n) {
        if (a[i] > t) {
            rem -= (a[i] - t);
        } else {
            rem += (t - a[i]) / 2;
        }
    }
    // cout << "t = " << t << " = " << rem << endl;
    return rem >= 0;
}

int solve() {
    int lo = 0, hi = 1e6;
    while (lo < hi) {
        int md = (lo+hi)>>1;
        if (poss(md)) hi = md;
        else lo = md+1;
    }
    return lo;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        int x;
        REP(i, n) a[i]=0;
        REP(i, m) {
            cin>>x;
            a[x-1]++;
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}