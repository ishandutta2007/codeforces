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

const int MX = 202;
bool vis[MX];
int a[MX][2];
int n, k;

int inter(int i, int j) {
    if (a[i][0] > a[i][1])
        swap(a[i][0], a[i][1]);
    int r0 = a[i][0] < a[j][0] && a[j][0] < a[i][1];
    int r1 = a[i][0] < a[j][1] && a[j][1] < a[i][1];
    return r0 ^ r1;
}

int solve() {
    memset(vis, 0, sizeof vis);
    REP(i, k) {
        vis[a[i][0]] = true;
        vis[a[i][1]] = true;
    }
    VI p;
    REP(i, 2*n) if (!vis[i]) p.PB(i);
    int t = SZ(p) / 2;
    REP(i, t) {
        a[k][0] = p[i];
        a[k++][1] = p[t+i];
    }
    int r = 0;
    REP(i, n)
        REP(j, i)
            r += inter(i, j);
    return r; 
}

int main() {
    setIO();
    int t; cin>>t;
    while(t--) {
        cin>>n>>k;
        REP(i, k) {
            cin>>a[i][0]>>a[i][1];
            --a[i][0]; --a[i][1];
        }
        cout<<solve()<<"\n";
    }
    
    return 0;
}