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

vector<int> cards;

int solve(int n) {
    auto it = upper_bound(ALL(cards), n);
    if (it == cards.begin()) return 0;
    --it;
    n -= *it;
    return 1 + solve(n);
}

void runme() {
    int k = 0;
    for (int i = 1; ; i++) {
        k += 2 * i + i - 1;
        if (k < 0 || k > 1e9) break;
        cards.PB(k);
    }
}

int main() {
    setIO();
    runme();
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        cout<<solve(n)<<"\n";
    }
    
    return 0;
}