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

LL n, g, p;
string s;

LL solve() {
    LL ans = p;
    int from = 0, to = n - 1;
    while (from <= to) {
        ans += p + g;
        if (s[from] == '0') {
            from++;
        } else {
            break;
        }
    }
    if (from > to) return ans;
    while (from <= to) {
        ans += p + g;
        if (s[to] == '0') {
            to--;
        } else {
            ans -= p;
            break;
        }
    }

    while (from <= to) {
        if (s[from] == '1') {
            from++;
            ans += 2 * p + g;
            continue;
        }
        int k = 1;
        while (from + 1 < to && s[from + 1] == '0') {
            k++;
            from++;
        }
        if (k == 1) {
            ans += 2 * p + g;
        } else {
            ans += 2 * p + min(k*g+2*g+(k-1)*p, k*g+2*(k-1)*p);
        }
        from++;
    }

    return ans;
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>g>>p>>s;
        LL r = solve();
        cout<<r<<"\n";
    }    
    return 0;
}