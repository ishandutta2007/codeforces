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

const int MX = 1010;
int n;

void solve() {
    for (int a = 0; a * 3 < MX; a++) {
        for (int b = 0; 3 * a + b * 5 < MX; b++) {
            for (int c = 0; 3 * a + 5 * b + 7 * c < MX; c++) 
                if (3 * a + 5 * b + 7 * c == n) {
                    cout << a << " " << b << " " << c << "\n";
                    return;
                }
        }
    }
    cout << "-1\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        solve();
    }
    
    return 0;
}