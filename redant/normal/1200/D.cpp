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
#define REP(i,n) FOR(i,1,n+1)
#define ALL(v) (v).begin(),(v).end()

void setIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

const int SZ = 2005;
int a[SZ][SZ];
int rs[SZ][SZ], cs[SZ][SZ];
int frs[SZ], fcs[SZ];
int rans[SZ][SZ], cans[SZ][SZ];
int n, k;

int gr(int i, int j) {
    return (rs[i][n] - rs[i][j+k-1] + rs[i][j-1]) == n-k;
}

int gfr(int i) {
    return frs[i] - frs[i-1];
}

int gc(int i, int j) {
    return (cs[n][j] - cs[i+k-1][j] + cs[i-1][j]) == n-k;
}

int gfc(int i) {
    return fcs[i] - fcs[i-1];
}

int solve() {
    REP(i, n) {
        REP(j, n)
            rs[i][j]=a[i][j]+rs[i][j-1];
        frs[i]=frs[i-1]+(rs[i][n]==n);
        REP(j, n)
            cs[j][i]=a[j][i]+cs[j-1][i];
        fcs[i]=fcs[i-1]+(cs[n][i]==n);
    }

    // rans
    REP(j, n-k+1) {
        int ans = frs[n]-frs[k-1]+(n==k);
        REP(i, k-1) ans += gr(i, j);
        int l = 0, r = k-1;
        while (r+1 <= n) {
            ans+=gfr(l)-gfr(r+1)+gr(r+1,j)-gr(l,j);
            ++l; ++r;
            rans[l][j] = ans;
            // cout << l << ", " << j << " = " << ans << endl;
        }
    }

    // cout << "---------------------" << endl;

    // cans
    REP(i, n-k+1) {
        int ans = fcs[n]-fcs[k-1]+(n==k);
        REP(j, k-1) ans += gc(i, j);
        int l = 0, r = k-1;
        while (r+1 <= n) {
            ans+=gfc(l)-gfc(r+1)+gc(i, r+1)-gc(i, l);
            ++l; ++r;
            cans[i][l] = ans;
            // cout << i << ", " << l << " = " << ans << endl;
        }
    }

    int r = 0;
    REP(i, n-k+1) REP(j, n-k+1) r = max(r, rans[i][j] + cans[i][j]);
    return r;
}

int main() {
    setIO();
    cin>>n>>k;
    REP(i, n) {
        string s; cin>>s;
        REP(j, n) a[i][j] = s[j-1]=='B'?0:1;
    }
    cout<<solve()<<"\n";    
    return 0;
}