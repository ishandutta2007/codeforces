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

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 300005;
int a[SZ];
LL T;
int n, m, k, x, y;

void solve() {
    map<int, int> s0;
    map<int, int> s1;
    REP(i, n) {
        int p = T - a[i];
        if (s0[p] > s1[p]) {
            cout << "1 ";
            s1[a[i]]++;
        } else {
            cout << "0 ";
            s0[a[i]]++;
        }
    }
    cout << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>T;
        REP(i, n) {
            cin>>a[i];
        }
        solve();
    }
    
    return 0;
}