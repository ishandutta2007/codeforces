#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
 
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
 
void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
 
const int MX = 2001;
const LL INF = 1e15;
LL l[MX], r[MX], a[MX];
LL n, k;
LL mem[MX];
 
LL f(int i) {
    if (i == n) return -k;
    LL &ans = mem[i];
    if (ans != -INF) return ans;
    ans = INF;
    LL ks = 0;
    LL kr = k;
    for (int j = i; j < n; j++) {
        LL ar = a[j];
        LL p = min(kr, ar);
        ar -= p; kr -= p;
        p = (ar + k - 1) / k;
        LL nks = p * 1ll * k;
        kr += nks - ar;
        ks += nks;
        if (l[j] + p > r[j]) {
            return ans;
        } else if (l[j] + p < l[j+1]) {
            ans = min(ans, ks + k + f(j + 1));
        }
    }
    ans = min(ans, ks - kr);
    return ans;
}
 
LL solve() {
    REP(i, n+1) mem[i] = -INF;
    LL r = k + f(0);
    return r >= INF ? -1 : r;
}
 
int main() {
    setIO();
    cin>>n>>k;
    REP(i, n) {
        cin>>l[i]>>r[i]>>a[i];
    }
    l[n] = r[n] = r[n-1] + 1;
    cout<<solve()<<"\n";    
    return 0;
}