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

int n;
string s;

int dd(char c) {
    return c == '-' ? 0 : (c == '>' ? 1 : -1);
}

int solve() {
    int d = dd(s[0]);
    REP(i, n) {
        int nd = dd(s[i]);
        if (nd==0) continue;
        if (d!=0 && d!=nd) {
            d=-2; break;
        }
        d = nd;
    }
    if (d!=-2) return n;
    int r = 0;
    REP(i, n) {
        r += (s[i]=='-'||s[(i-1+n)%n]=='-');
    }
    return r;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>s;
        cout<<solve()<<"\n";
    }    
    return 0;
}