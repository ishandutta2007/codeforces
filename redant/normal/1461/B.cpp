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

const int MX = 505;
string s[MX];
int a[MX][MX];
int n, m;

int get(int x, int y) {
    int k = 1;
    int l = y, r = y;
    int res = 0;
    while (x < n && l >= 0 && r < m) {
        int count = a[x][r];
        if (l > 0) count -= a[x][l-1];
        if (count == k) ++res;
        else break;
        k += 2;
        ++x;
        --l;
        ++r;
    }
    return res;
}

LL solve() {
    REP(i, n) {
        a[i][0] = (s[i][0] == '*');
        REP(j, m-1) a[i][j+1] = a[i][j] + (s[i][j+1] == '*');
        // REP(j, m) cout << a[i][j] << " ";
        // cout << endl;
    }
    LL r = 0;
    REP(i, n) REP(j, m) {
        r += get(i, j);
        // cout << get(i, j) << " \n"[j == m-1];
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            cin>>s[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}