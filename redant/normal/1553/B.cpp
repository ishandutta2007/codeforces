#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 502;
int a[MX];
int mem[MX][2*MX][2];
int n, m;
string s, t;

int get(int i, int j, int k) {
    if (j + 1 >= m) return 1;
    int &r = mem[i][j][k];
    if (r != -1)
        return r;
    r = 0;
    if (i > 0 && s[i-1] == t[j+1])
        r += get(i - 1, j + 1, 1);
    if(k != 1 && (i + 1) < n && s[i+1] == t[j+1])
        r += get(i + 1, j + 1, 0);
    // cout << i << j << k << " = " << r << endl;
    return r;
}

int solve() {
    n = s.length();
    m = t.length();
    REP(i, n+1) REP(j, m+1) REP(k, 2) mem[i][j][k] = -1;
    REP(i, n)
        if (s[i] == t[0]) {
            if (get(i, 0, 0))
                return 1;
        }
    return 0;
}

int main() {
    setIO();
    int tt; cin>>tt;
    while(tt--) {
        cin>>s>>t;
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}