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

#define N 500010

LL lasai( int n, int a[] ) {
    static int vis[N],vid,per[N];
    LL ans=0;
    REP(i,n-2) per[i]=i+2;
    do {
        vid++;
        LL now=0;
        REP(ii,n-2) {
            int i=per[ii];
            vis[i]=vid;
            int l=i,r=i;
            while ( vis[l]==vid ) l--;
            while ( vis[r]==vid ) r++;
            now+=min(a[l],a[r]);
        }
        ans=max(ans,now);
    } while ( next_permutation(per,per+n-2) );
    return ans;
}

int n,a[N],pre[N],nxt[N];
bool vis[N];

int main() {
    RI(n);
    REP1(i,1,n) RI(a[i]);
    REP1(i,0,n) nxt[i]=i+1;
    REP1(i,1,n+1) pre[i]=i-1;
    priority_queue<PII> pq;
    auto val=[&]( int i ) { return a[pre[i]]>=a[i] && a[i]<=a[nxt[i]] ? 1000000000 : min(a[pre[i]],a[nxt[i]]); };
    auto push=[&]( int i ) { pq.push(MP(val(i),i)); };
    REP1(i,2,n-1) push(i);
    LL ans=0;
    while ( !pq.empty() ) {
        int i=pq.top().second;
        int v=pq.top().first;
        pq.pop();
        if ( vis[i] || val(i)!=v ) continue;
        //printf("%d,%d\n",i,min(a[pre[i]],a[nxt[i]]));
        vis[i]=1;
        ans+=min(a[pre[i]],a[nxt[i]]); 
        nxt[pre[i]]=nxt[i];
        pre[nxt[i]]=pre[i];
        if ( pre[i]>1 ) push(pre[i]);
        if ( nxt[i]<n ) push(nxt[i]);
    }
    cout<<ans<<endl;
    return 0;
}