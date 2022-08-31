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

LL a1, b1, a2, b2;

LL solve() {
    LL r = abs(a1-a2) + abs(b1-b2);
    if ((a1 == a2) || (b1 == b2)) return r;
    return r+2;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin >> a1 >> b1 >> a2 >> b2;
        cout<<solve()<<"\n";
    }    
    return 0;
}