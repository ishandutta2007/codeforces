// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x),end(x)
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
// }}}

#define N 100010

inline void chkmin( int &a, int b ) { if ( b<a ) a=b; }

int n,m,w[N],scc[N],cid;
vector<int> e[N],f[N];

int vis[N];
vector<int> stk;
void dfs1( int p ) {
    vis[p]=1;
    FOR(it,e[p]) if ( vis[*it]==0 ) dfs1(*it);
    stk.PB(p);
}

void dfs2( int p ) {
    vis[p]=2;
    scc[p]=cid;
    FOR(it,f[p]) if ( vis[*it]==1 ) dfs2(*it);
}

int sml[N],cnt[N];
int main() {
    RI(n);
    REP(i,n) RI(w[i]);
    RI(m);
    REP(i,m) {
        int a,b;
        RI(a,b); a--; b--;
        e[a].PB(b);
        f[b].PB(a);
    }
    REP(i,n) if ( vis[i]==0 ) dfs1(i);
    reverse(ALL(stk));
    FOR(it,stk) if ( vis[*it]==1 ) {
        dfs2(*it);
        cid++;
    }
    REP(i,cid) sml[i]=2e9;
    REP(i,n) {
        int j=scc[i];
        if ( w[i]<sml[j] ) {
            cnt[j]=1;
            sml[j]=w[i];
        } else if ( w[i]==sml[j] ) cnt[j]++;
    }
    int MOD=1e9+7;
    LL a1=0,a2=1;
    REP(i,cid) {
        a1+=sml[i];
        a2=a2*cnt[i]%MOD;
    }
    cout<<a1<<" "<<a2<<endl;
    return 0;
}