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

inline int bit( int x, int i ) { return (x>>i)&1; }

#define N 100010
LL sum[N];
void predo() {
    REP1(i,1,N-1) sum[i]=sum[i-1]+i;
}

int n,m,a[N];
void input() {
    RI(n,m);
    REP1(i,1,n) RI(a[i]);
}

int b[17][N];
LL now;
set<PII> s[17];
void build() {
    REP1(i,0,16) REP1(j,1,n) b[i][j]=bit(a[j],i);
    REP1(i,0,16) {
        for ( int j=1,k; j<=n; j=k ) {
            if ( b[i][j]==0 ) k=j+1;
            else {
                for ( k=j; k<=n && b[i][k]==1; k++ );
                now+=sum[k-j]*(1<<i);
                s[i].insert(MP(j,k-1));
            }
        }
    }
    REP1(i,0,16) s[i].insert(MP(-N,-N));
    REP1(i,0,16) s[i].insert(MP(+N,+N));
}

void del( set<PII> &ss, int l, int r, int base ) {
    if ( l>r ) return;
    now-=sum[r-l+1]*base;
    ss.erase(MP(l,r));
}

void ins( set<PII> &ss, int l, int r, int base ) {
    if ( l>r ) return;
    now+=sum[r-l+1]*base;
    ss.insert(MP(l,r));
}

void solve( int base, int pos, int val, set<PII> &ss, int bb[N] ) {
    if ( bb[pos]==val ) return;
    if ( bb[pos]==0 ) {
        int l=pos,r=pos;
        auto rit=ss.upper_bound(MP(pos,N));
        auto lit=rit; lit--;
        if ( lit->second==pos-1 ) {
            l=lit->first;
            del(ss,lit->first,lit->second,base);
        }
        if ( rit->first==pos+1 ) {
            r=rit->second;
            del(ss,rit->first,rit->second,base);
        }
        ins(ss,l,r,base);
    } else {
        auto it=--ss.upper_bound(MP(pos,N));
        int l=it->first;
        int r=it->second;
        del(ss,l,r,base);
        ins(ss,l,pos-1,base);
        ins(ss,pos+1,r,base);
    }
    bb[pos]=val;
}

void solve() {
    while ( m-- ) {
        int p,v;
        RI(p,v);
        REP1(i,0,16) solve(1<<i,p,bit(v,i),s[i],b[i]);
        cout<<now<<endl;
    }
}

int main() {
    predo();
    input();
    build();
    solve();
    return 0;
}