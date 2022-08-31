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

int n, m, k, x, y;

bool solve2() {
    if (n <= 1 || m <= 1) return true;
    return n == 2 && m == 2;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        cout<<(solve2()?"YES":"NO")<<"\n";
    }
    
    return 0;
}