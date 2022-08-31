#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 4003;
const int SZ = 1003;
int n, x;
int a[SZ];

int solve() {
    sort(a, a+n);
    int need = 0;
    bool eq = true;
    bool eq1 = false;
    REP(i, n) {
        need += x - a[i];
        if (a[i] != x) eq = false;
        else eq1 = true;
    }
    if (eq) return 0;
    if (need == 0 || eq1) return 1;
    return 2;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>x;
        REP(i, n) {
            cin>>a[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}