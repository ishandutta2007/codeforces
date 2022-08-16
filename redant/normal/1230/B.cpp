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
string s;
int n, k;

void solve() {
    if (n == 1) {
        if (k > 0) s = '0';
        return;
    }
    if (k > 0 && s[0] > '1') {
        s[0] = '1';
        --k;
    }
    for (int i = 1; i < n && k > 0; i++) {
        if (s[i] > '0') {
            s[i] = '0';
            --k;
        }
    }
}

int main() {
    setIO();
    cin >> n >> k >> s;
    solve();
    cout << s << endl;
    return 0;
}