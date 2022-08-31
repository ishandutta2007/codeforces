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

int buns, a, b;
int ac, bc;

int solve() {
    if (ac < bc) { swap(a, b); swap(ac, bc); }
    int k = min(a, buns/2);
    int ans = ac * k;
    buns -= k * 2;
    k = min(b, buns/2);
    ans += bc * k;
    return ans;
}


int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>buns>>a>>b;
        cin>>ac>>bc;
        cout<<solve()<<"\n";
    }
    
    return 0;
}