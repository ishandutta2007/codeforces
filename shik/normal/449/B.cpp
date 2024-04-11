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

struct Edge {
    int to,len;
};

int n,m,k,ts[N],ty[N];
vector<Edge> e[N];
void input() {
    RI(n,m,k);
    REP(i,m) {
        int a,b,c;
        RI(a,b,c);
        e[a].PB(Edge{b,c});
        e[b].PB(Edge{a,c});
    }
    REP(i,k) RI(ts[i],ty[i]);
}

int pre_ans;
void reduce() {
    vector<PII> v;
    REP(i,k) v.PB(MP(ts[i],ty[i]));
    sort(ALL(v));
    vector<PII> nv;
    REP(i,k) if ( i==0 || v[i].first!=v[i-1].first ) nv.PB(v[i]);
    pre_ans=SZ(v)-SZ(nv);
    k=SZ(nv);
    REP(i,k) tie(ts[i],ty[i])=nv[i];
}

LL dis[N];
int cnt[N];
void build() {
    priority_queue<pair<LL,int>> pq;
    auto push=[&]( int p, LL d ) {
        if ( d>dis[p] ) return;
        if ( d==dis[p] ) {
            cnt[p]++;
            return;
        }
        dis[p]=d;
        cnt[p]=1;
        pq.push(MP(-d,p));
    };
    REP1(i,1,n) dis[i]=1e18;
    push(1,0);
    REP(i,k) push(ts[i],ty[i]);
    while ( !pq.empty() ) {
        int p=pq.top().second;
        LL d=-pq.top().first;
        pq.pop();
        if ( dis[p]!=d ) continue;
        FOR(it,e[p]) push(it->to,dis[p]+it->len);
    }
}


void solve() {
    int ans=pre_ans;
    REP(i,k) if ( ty[i]>dis[ts[i]] || (cnt[ts[i]]>1 && ty[i]==dis[ts[i]]) ) ans++;
    printf("%d\n",ans);
}

int main() {
    input();
    reduce();
    build();
    solve();
    return 0;
}