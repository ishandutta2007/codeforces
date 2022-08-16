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

const int SZ = 222;
int A[SZ][SZ];
int n;

void solve() {
    vector<PI> r;
    int a = A[0][1], b = A[1][0];
    int c = A[n-2][n-1], d = A[n-1][n-2];
    if (a == b) {
        if (c == a) r.PB(MP(n-2,n-1));
        if (d == a) r.PB(MP(n-1,n-2));
    } else {
        if (c == d) {
            if (c == a) r.PB(MP(0,1));
            if (c == b) r.PB(MP(1,0));
        } else {
            r.PB(MP(0,1));
            a = 1 - a;
            if (c == a) r.PB(MP(n-2,n-1));
            if (d == a) r.PB(MP(n-1,n-2));
        }
    }


    int k = r.size();
    cout<<k<<"\n";
    ITR(x,r) cout <<(*x).F+1<<" "<<(*x).S+1<<"\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            string s; cin>>s;
            REP(j, n) {
                A[i][j] = s[j]-'0';
            }
        }
        solve();
    }
    
    return 0;
}