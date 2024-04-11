// TwT514 {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define REP(i,n) for (int i=0; i<(int)(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x,n) memset((x),0,(n)*sizeof(*x))
#define MS1(x,n) memset((x),-1,(n)*sizeof(*x))
#define MP make_pair
#define PB push_back
#define RI(a) scanf("%d",&(a))
#define RII(a,b) scanf("%d%d",&(a),&(b))
#define RIII(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
// }}}

struct E {
    int to,l,r;
    E() {}
    E( int _to, int _l, int _r ):to(_to),l(_l),r(_r) {}
};

#define N 1010
vector<E> e[N];

int shik( int n, int l ) {
    priority_queue<PII> q;
    int dis[N]={};
    dis[1]=1e7;
    q.push(PII(dis[1],1));
    while ( !q.empty() ) {
        int d=q.top().first;
        int p=q.top().second;
        q.pop();
        if ( dis[p]!=d ) continue;
        FOR(it,e[p]) if ( it->l<=l && l<=it->r && min(d,it->r)>dis[it->to] ) {
            dis[it->to]=min(d,it->r);
            q.push(PII(dis[it->to],it->to));
        }
    }
    return dis[n];
}

int ls[3010];
int main() {
    int n,m;
    RII(n,m);
    REP(i,m) {
        int a,b,l,r;
        RII(a,b);
        RII(l,r);
        e[a].PB(E(b,l,r));
        e[b].PB(E(a,l,r));
        ls[i]=l;
    }
    int ans=0;
    REP(i,m) {
        int r=shik(n,ls[i]);
        ans=max(ans,r-ls[i]+1);
    }
    if ( ans==0 ) puts("Nice work, Dima!");
    else printf("%d\n",ans);
    return 0;
}