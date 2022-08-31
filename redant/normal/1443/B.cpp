#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> PI;
typedef vector<int> VI;
typedef vector<PI> VPI;

template<class T> bool tmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool tmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SZ(x) (int)(x).size()
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define TRAV(a,x) for (auto& a : x)

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int inf = (int) 1e9;
const int MX = 100005;
int dp[MX][2];
int n, a, b;
string s;

int solve() {
    n = s.length();
    if (s[0] == '1') {
        dp[0][1] = a;
        dp[0][0] = inf;
    } else {
        dp[0][0] = 0;
        dp[0][1] = a + b;
    }

    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            dp[i][1] = min(dp[i-1][0] + a, dp[i-1][1]);
            dp[i][0] = inf;
        } else {
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = min(dp[i-1][0] + a + b, dp[i-1][1] + b);
        }
    }
    return dp[n-1][s[n-1]-'0'];
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>a>>b>>s;
        cout<<solve()<<"\n";
    }
    
    return 0;
}