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

const int SZ = 55;
int a[SZ];
int n;

bool ok() {
    int sum = 0;
    REP(i, n) {
        sum += a[i];
        if (sum == 0)
            return false;
    }
    cout<<"YES\n";
    REP(i,n) cout << a[i]<<" ";
    cout<<"\n";
    return true;
}

void solve2() {
    sort(a, a+n);
    if (ok()) {
        return;
    }
    for (int i=0,j=n-1;i<j;i++,j--) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    if (ok()) {
        return;
    }
    cout << "NO\n";
    return;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>a[i];
        }
        solve2();
    }
    
    return 0;
}