#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 1003;
int res[MX], rp;
int a[2][MX], ap[2], n[2];
int k;

int solve(int k, vector<int> &p) {
    if (p[0] == n[0] && p[1] == n[1])
        return 1;
    REP(i, 2)
        if (p[i] < n[i] && a[i][p[i]] == 0) {
            res[rp++] = a[i][p[i]++];
            return solve(k + 1, p);
        }
    int pi = 0;
    REP(i, 2) {
        if (p[i] < n[i] && (p[1-i] == n[1-i] || a[i][p[i]] <= a[1-i][p[1-i]])) {
            if (a[i][p[i]] <= k) {
                res[rp++] = a[i][p[i]++];
                return solve(k, p);
            }
        }
    }
    return 0;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>k>>n[0]>>n[1];
        rp = 0;
        REP(j, 2)
            REP(i, n[j]) {
                cin>>a[j][i];
            }
        vector<int> p(2, 0);
        if (solve(k, p)) {
            REP(i, rp)
                cout << res[i] << " ";
                cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
    
    return 0;
}