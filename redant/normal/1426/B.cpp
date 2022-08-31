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

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        bool x = false, y = false;
        REP(i, n) {
            int a, b, c, d;
            cin>>a>>b>>c>>d;
            x=x||(c==b);
            y=y||(a==d && b==c);
        }
        bool ans = false;
        if (m&1) {}
        // else if(m==2) {ans = x;}
        else {ans = x; } // &&y;}
        cout<<(ans?"YES":"NO")<<"\n";
    }
    
    return 0;
}