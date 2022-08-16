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

const int MX = 200005;
LL a[MX];
int n;
vector<VI> g;
bool vis[MX];

class Node {
    public:
    int m;
    LL mx, sum;

    Node() {m=0; mx=0; sum=0;}
    Node(int _m, LL _mx, LL _s) {
        m=_m; mx=_mx; sum=_s;
    }
    void add(Node &b) {
        m+=b.m;
        tmax(mx,b.mx);
        sum+=b.sum;
    }
};

Node h[MX];

void dfs(int u, int pu) {
    Node accum;
    TRAV(v,g[u]) {
        if(v==pu) continue;
        dfs(v, u);
        accum.add(h[v]);
    }

    if(accum.m==0) {
        h[u]=Node(1, a[u], a[u]);
    } else {
        int mm = accum.m;
        LL mmx = accum.mx;
        LL msum = accum.sum + a[u];
        if(mmx * mm < msum) {
            LL k = msum - mmx * mm;
            mmx += (k+mm-1)/mm;
        }        
        h[u]=Node(mm,mmx,msum);
    }
}

LL solve() {
    dfs(1, -1);
    return h[1].mx;
}

int main() {
    setIO();
    cin>>n;
    g.resize(n+1);
    REP(i, n-1) {
        int p; cin>>p;
        g[p].PB(i+2);
    }
    REP(i, n) cin>>a[i+1];
    cout<<solve()<<"\n";    
    return 0;
}