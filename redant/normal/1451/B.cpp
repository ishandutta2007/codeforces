#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, l, r;
string s;

bool solve2() {
    for (int i = r + 1; i < n; i++)
        if (s[i] == s[r]) return true;
    for (int i = 0; i < l; i++)
        if (s[i] == s[l]) return true;
    return false;
}

int main() {
    setIO();
    int t, q; cin>>t;
    while(t--) {
        cin>>n>>q>>s;
        while(q--) {
            cin >> l >> r;
            --l; --r;
            cout<<(solve2()?"YES":"NO")<<"\n";
        }
    }
    
    return 0;
}