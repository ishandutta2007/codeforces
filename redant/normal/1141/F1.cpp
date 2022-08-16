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

const int MX = 1501;
int a[MX];
unordered_map<int, int> mend[MX];
int n;

void solve() {
    int mx = 0, mxs = 0;
    for (int i = 1; i <= n; i++) {
        mend[i] = unordered_map<int, int> (mend[i-1]);
        int s = 0;
        for (int j = i; j > 0; j--) {
            s += a[j];
            int cx = max(mend[j-1][s] + 1, mend[i][s]);
            mend[i][s] = cx;
            if (cx > mx) {
                mx = cx;
                mxs = s;
            }
        }
    }

    cout << mx << "\n";
    int k = 0;
    for (int j = 1; j <= n; j++) {
        int s = 0;
        for (int i = j; i > k; i--) {
            s += a[i];
            if (s == mxs) {
                cout << i << " " << j << "\n";
                k = j;
                break;
            }
        }
    }
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) {
        cin>>a[i+1];
    }
    solve();    
    return 0;
}