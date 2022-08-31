#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 2003;
int a[MX];
LL s[MX];
int n;

int solve() {
    REP(i, n+1) s[i] = -1;
    s[0] = 0;
    REP(i, n) {
        for (int j = i; j >= 0; j--) {
            if (s[j] >= 0)
                s[j+1] = max(s[j+1], s[j] + a[i]);
        }
    }
    int r = 0;
    REP(i, n+1)
        if (s[i] >= 0) r = i;
    return r;
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) {
        cin>>a[i];
    }
    cout<<solve()<<"\n";
    return 0;
}