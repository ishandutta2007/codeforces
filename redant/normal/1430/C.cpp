#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

LL n;

void f2() {
    cout << "1 2\n";
}

void f3() {
    cout << "1 3\n";
    cout << "2 2\n";
}

void solve() {
    cout << "2\n";
    if (n==2) return f2();
    if (n==3) return f3();
    int a = n - 2;
    cout << n << " " << n-2 << "\n";
    cout << n-1 << " " << n-1 << "\n";
    int b = n - 1;
    while (--a) {
        cout << a << " " << b << "\n";
        b = (a + b) / 2;
    }
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        solve();
    }
    
    return 0;
}