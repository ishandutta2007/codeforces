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
int f[6][MX];
int n, q;
string s;

int main() {
    setIO();
    int t=1; // cin>>t;
    while(t--) {
        cin>>n>>q;
        cin>>s;

        vector<char> ch = {'a', 'b', 'c'};
        int p = 0;
        do {
            for (int i = 1; i <= n; i++) {
                f[p][i] = f[p][i-1] + (s[i-1] != ch[(i-1)%3]);
            }
            ++p;
        } while(next_permutation(begin(ch), end(ch)));

        int l, r;
        REP(i, q) {
            cin >> l >> r;
            int res = n;
            REP(p, 6) {
                res = min(res, f[p][r] - f[p][l-1]);
            }
            cout<<res<<"\n";   
        }
    }
    
    return 0;
}