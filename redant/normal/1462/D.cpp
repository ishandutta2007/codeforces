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

const int MX = 3005;
int a[MX];
int n;
int r, mx, sum;

void check(int m) {
    int val = sum / m;
    // cout << "Checking " << val << endl;
    if (m > n || val < mx)
        return;
    int c = 0;
    for (int i = 0; i < n; i++) {
        int sm = a[i], j = i;
        while (j + 1 < n && sm < val) {
            sm += a[++j];
        }
        if (sm == val) {
            c += j - i;
            i = j;
        } else {
            return;
        }
        // cout << i << ", " << j << "  " << sm << " : " << c << endl;
    }
    // cout << val << " -> " << c << endl;
    r = min(r, c);
}

int solve() {
    r = n - 1;
    sum = 0;
    mx = 0;
    REP(i, n) { 
        sum += a[i];
        mx = max(mx, a[i]);
    }
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i != 0) continue;
        check(i);
        check(sum / i);
    }
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}