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

int n, m, k, x, y;
string s;

void solve() {
    string ans = s;
    int k = 1;
    REP(i, n-1) {
        string a = s.substr(0, i+1);
        if ((n-i-1)&1) reverse(a.begin(), a.end());
        string b = s.substr(i+1);
        string r = b + a;
        // cout << r << endl;
        if (ans.compare(r) > 0) {
            ans = r;
            k = i + 2;
        }
    }    
    cout << ans << "\n" << k << "\n";
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n;
        cin >> s;
        solve();
    }
    
    return 0;
}