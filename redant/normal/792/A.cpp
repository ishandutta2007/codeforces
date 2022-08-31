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
int n;

void solve() {
    map<int, int> mp;
    sort(a, a+n);
    REP(i, n-1) {
        mp[a[i+1]-a[i]]++;
    }
    auto f = *mp.begin();
    cout << f.first << " " << f.second << endl;
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) {
        cin>>a[i];
    }
    solve();    
    return 0;
}