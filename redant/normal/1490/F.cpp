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
int a[MX];
int n;

LL solve() {
    LL s = 0, p = 0;
    REP(i, n) s += a[i];
    sort(a, a+n);
    LL r = 1e18;
    REP(i, n) {
        r = min(r, p + s - 1ll * a[i] * (n-i));
        p += a[i];
        s -= a[i];
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        map<int, int> freq;
        REP(i, n) {
            int x; cin >> x;
            freq[x]++;
        }
        n = 0;
        for (auto v : freq) {
            a[n++] = v.second;
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}