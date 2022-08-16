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
string s[SZ];
int n;

int solve() {
    int r[3] = {0, 0, 0};
    REP(i, n) {
        int a[2] = {0, 0};
        for (char c : s[i]) {
            int k = c - '0';
            a[k] = (a[k] + 1) % 2;
        }
        if (a[0] && a[1])
            r[2]++;
        else if (a[0])
            r[0]++;
        else if (a[1])
            r[1]++;
    }
    r[2]%=2;
    if (r[2] > r[0] + r[1])
        return n - 1;
    return n;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        REP(i, n) {
            cin>>s[i];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}