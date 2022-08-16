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

const int SZ = 105;
int a[SZ];
int n, m, k;

bool solve() {
    REP(i, n-1) {
        if (a[i] < a[i+1]-k) {
            m -= a[i+1]-k-a[i];
            if(m<0) return false;
        } else {
            m += a[i]-max(0, (a[i+1]-k));
        }
    }
    return true; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<(solve()?"YES":"NO")<<"\n";
    }
    
    return 0;
}