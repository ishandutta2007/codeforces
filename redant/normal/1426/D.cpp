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

const int SZ = 200005;
int a[SZ];
int n, m, k, x, y;

int solve() {
    int r = 0;
    set<LL> sums;
    sums.insert(0);
    LL sum = 0;
    REP(i, n) {
        sum += a[i];
        if (sums.count(sum)>0) {
            r++;
            sums.clear(); sums.insert(0);
            sum=a[i];
        }
        sums.insert(sum);
    }
    return r;
}

int main() {
    setIO();
    int t=1; // cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}