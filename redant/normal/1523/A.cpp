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
string s;
int a[MX];
int l[MX], r[MX];
int n, m;

string solve() {
    int x = m+n+5;
    for (int i = n - 1; i >= 0; i--) {
        r[i] = x;
        if (s[i] == '1') x = i;
    }

    x = -(m+n+5);
    REP(i, n) {
        l[i] = x;
        if (s[i] == '1') x = i;
    }

    REP(i, n) {
        if (s[i] == '1') continue;
        int a = i - l[i], b = r[i] - i;
        if (a < b && a <= m) s[i] = '1';
        else if (b < a && b <= m) s[i] = '1';
    }

    return s;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}