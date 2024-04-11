// {{{ by shik
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define REP(i,n) for ( int i=0; i<int(n); i++ )
#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
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
int n,m;
VI e[N],ord;

int dep[N];
bool vis[N];
void dfs( int p, int lv ) {
    vis[p]=1;
    dep[p]=lv;
    FOR(it,e[p]) if ( !vis[*it] ) dfs(*it,lv+1);
    ord.PB(p);
}

int main() {
    RI(n,m);
    REP(i,m) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
    if ( m%2==1 ) {
        puts("No solution");
        return 0;
    }
    dfs(1,1);
    set<PII> used;
    REP(ii,n) {
        int i=ord[ii];
        sort(e[i].begin(),e[i].end(),[&](int a, int b) { return dep[a]<dep[b]; });
        VI v;
        FOR(it,e[i]) if ( !used.count(MP(i,*it)) ) v.PB(*it);
        while ( SZ(v)>=2 ) {
            int a=v.back(); v.pop_back();
            int b=v.back(); v.pop_back();
            used.insert(MP(a,i));
            used.insert(MP(i,a));
            used.insert(MP(b,i));
            used.insert(MP(i,b));
            printf("%d %d %d\n",a,i,b);
        }
    }
    return 0;
}