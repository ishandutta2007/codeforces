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

string s;

void solve() {
    VI even, odd;
    for (char c : s) {
        int k = c - '0';
        if (k&1) odd.PB(k);
        else even.PB(k);
    }
    int i = 0, j = 0;
    while (i < odd.size() && j < even.size()) {
        if (odd[i] > even[j])
            cout << even[j++];
        else
            cout << odd[i++];
    }
    while (i < odd.size()) cout << odd[i++];
    while (j < even.size()) cout << even[j++];
    cout << endl;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>s;
        solve();
    }    
    return 0;
}