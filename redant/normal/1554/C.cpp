#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int n, m;

int solve() {
    int r = 0;
    int rr = 2e9;
    int last0 = -1;
    bool got = false;
    for (int i = 30; i >= 0; i--) {
        int a = n>>i&1;
        int b = m>>i&1;
        // cout << i << " : " << a << b << "   ";
        if (a == 0 && b == 0) {
            int v = 1 << i;
            if (v > m) rr = min(rr, v);
            last0 = i;
            // cout << "msb " << "\n";
        } else if (a == 0 && b == 1) {
            // cout << " 1<<i " << "\n";
            r ^= 1 << i;
        } else if (a == 1 && b == 0) {
            // cout << " break; " << "\n";
            got = true;
            break;
        }
    }

    if (!got) {
        if (last0 != -1) {
            r ^= (1<< last0);
            for (int i = 0; i < last0; i++)
                r^=(r&(1<<i));
        }
    }

    if ((n^r) > m)
        return min(r, rr);

    return rr;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        cout<<solve()<<"\n";
    }
    
    return 0;
}