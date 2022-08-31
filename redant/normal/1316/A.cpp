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

const int SZ = 1005;
int a[SZ];
int n, m, k, x, y;

int solve() {
    int sum = 0;
    REP(i, n-1) sum += a[i+1];
    return min(m, a[0]+sum);
}


int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}