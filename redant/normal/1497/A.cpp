#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 105;
int a[MX];
int f[MX], cf;
int n;

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        memset(f, 0, sizeof f);
        REP(i, n) {
            cin>>a[i];
            f[a[i]] += 1;
        }
        REP(i, 101) {
            if (f[i]) {
                cout << i << " ";
                --f[i];
            }
        }
        REP(i, 101) {
            while (f[i]) {
                cout << i << " ";
                --f[i];
            }
        }
        cout << "\n";
    }
    
    return 0;
}