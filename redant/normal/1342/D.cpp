#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PI;

#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define F first
#define S second
#define SET(v,x) memset(v,x,sizeof v)
#define FOR(i,a,b) for(int _n(b),i(a);i<_n;i++) 
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())

#define debug(x) cerr << #x << " = " << x << ", line = " << __LINE__ << endl

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int MX = 200005;
int n, k;
int m[MX], c[MX];
vector<VI> ans;
int f[MX];

void rearrange() {
    if (ans.size() <= 1)
        return;
    int k = ans.size();
    if (ans[k-1].size() <= ans[k-2].size())
        return;
    // swap(ans[0], ans[f[ans[1].size()]]);
    ans[k-1].swap(ans[k-1-f[ans[1].size()]]);
}

void printAns() {
    cout << SZ(ans) << "\n";
    for (auto &vv : ans) {
        cout << SZ(vv) << " ";
        for(auto &v : vv)
            cout << v << " ";
        cout << "\n";
    }
    // cout << "--------" << endl;
}

void solve() {
   sort(m, m + n);
   int p = 0;
   for (int i = n - 1; i >= 0; i--) {
    //    cout << "Processing " << m[i] << endl;
    //    cout << c[m[i]] << ", " << ans[0].size() << endl; 
        if (ans.empty()) {
            ans.push_back({m[i]});
        } else if (c[m[i]] > ans[p].size()) {
            ans[p].push_back(m[i]);
        } else {
            p--;
            if (p < 0) p = ans.size() - 1;
            if (ans[p].size() < c[m[i]])
                ans[p].push_back(m[i]);
            else {
                ans.push_back({m[i]});
                p = ans.size() - 1;
            }
        }
    //    printAns();
   }
}

int main() {
    setIO();
    cin>>n>>k;
    REP(i, n) {
        cin>>m[i];
    }
    REP(i, k) {
        cin>>c[i+1];
    }
    solve();
    printAns();    
    return 0;
}