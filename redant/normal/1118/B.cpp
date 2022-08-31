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
int A[MX];
int n;

int solve() {
    if (n == 1) return 1;
    int a = 0, b = 0;
    for (int i = 0; i < n; i += 2) {
        a += A[i];
        b += A[i+1];
    }
    int r = 0;
    int c = 0, d = 0;
    REP(i, n) {
        if (i & 1) b -= A[i];
        else a -= A[i];

        // cout << c << " " << d << endl;
        // cout << a << " " << b << endl;
        // cout << endl;

        r += (c+b == d+a);

        if (i & 1) d += A[i];
        else c += A[i];
    }
    return r; 
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) {
        cin>>A[i];
    }
    cout<<solve()<<"\n";
    return 0;
}