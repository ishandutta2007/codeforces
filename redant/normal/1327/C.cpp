#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

typedef long long LL;

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m, k;

int main() {
    setIO();
    cin>>n>>m>>k;
    REP(i, k) {
        int a, b;
        cin >> a >> b;
    }
    REP(i, k) {
        int a, b;
        cin >> a >> b;
    }
    
    string r = "";

    REP(i, n-1) r += "U";
    REP(i, m-1) r += "L";

    while (n > 0) {
        REP(i, m-1) r += "R";
        n--;
        if (n > 0) {
            r += "D";
            REP(i, m-1) r += "L";
            n--;
            if (n > 0) {
                r += "D";
            }
        }
    }

    cout << r.length() << "\n" << r << endl;    
    return 0;
}