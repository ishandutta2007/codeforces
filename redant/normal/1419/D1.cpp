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

const int SZ = 100005;
int n;
int a[SZ];

void solve() {
    if (n < 3) {
        cout<<"0\n";
        REP(i, n) cout<<a[i]<<" ";
        cout<<"\n";
        return;
    }
    sort(a, a+n);
    VI ans;
    ans.push_back(a[n-1]);
    int r = 0;
    int p = n - 2;
    while (p > 0) {
        ans.push_back(a[p-1]);
        ans.push_back(a[p]);
        p -= 2;
        r++;
    }
    if (p == 0) ans.push_back(a[0]);

    cout << r << "\n";
    REP(i, n) cout<<ans[i]<<" ";
    cout<<"\n";
}

int main() {
    setIO();
    cin>>n;
    REP(i, n) {
        cin>>a[i];
    }
    solve();    
    return 0;
}