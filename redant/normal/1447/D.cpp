#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int inf = 1e8;
const int MX = 5001;
int mem[MX][MX];
int n1, n2;
string s1, s2;

int f(int p1, int p2) {
    if (p1 >= n1 || p2 >= n2)
        return 0;
    int &r = mem[p1][p2];
    if (r > -inf) return r;
    if (s1[p1] == s2[p2]) {
        return r = 2 + f(p1 + 1, p2 + 1);
    }
    r = 0;
    r = max(r, f(p1 + 1, p2) - 1);
    r = max(r, f(p1, p2 + 1) - 1);
    return r;
}

int solve() {
    REP(i, n1) REP(j, n2) mem[i][j] = -inf;
    int r = 0;
    REP(i, n1) REP(j, n2)
        if (s1[i] == s2[j])
            r = max(r, f(i, j));
    return r;
}

int main() {
    setIO();
    cin>>n1>>n2;
    cin>>s1>>s2;
    cout<<solve()<<"\n";    
    return 0;
}