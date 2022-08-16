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

int solve() {
    VI cs;
    REP(i, n) {
        int k = 1;
        while (i + 1 < n && s[i+1] == s[i]) {
            ++k;
            ++i;
        }
        cs.PB(k);
    }
    int r = 0;
    int i = 0, j = 1;
    while (i < (int) cs.size()) {
        if (cs[i] == 1) {
            j = max(i+1, j);
            while (j < (int) cs.size() && cs[j] == 1)
                ++j;
            if (j < (int) cs.size())
                --cs[j];
            else
                ++i;            
        }
        ++r;
        ++i;
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