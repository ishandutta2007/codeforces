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

const int SZ = 305;
int a[SZ];
int n;
int p[3][3] = {
    {0, 3, 4},
    {3, 0, -1},
    {4, -1, 0}
};

int solve() {
    int r = 0;
    REP(i, n-1) {
        int rr = p[a[i]-1][a[i+1]-1];
        if (rr == -1) return -1;
        r += rr;
        if (i + 2 < n && a[i] == 3 && a[i+1] == 1 && a[i+2] == 2)
            --r;
    }
    return r;
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) {
        cin>>a[i];
    }
    int r = solve();
    if (r == -1) {
        cout << "Infinite"<<endl;
    } else {
        cout <<"Finite\n"<<r<<endl;
    }    
    return 0;
}