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
#define K 120
const int BN=N/K+514;

int n,st[N],mx[N],re[N];

struct P {
    int t;
    LL v,d;
};

struct Block {
    int l,r,last,sre;
    bool zero;
    vector<P> vp,vpz;
    void build() {
        if ( zero && !vpz.empty() ) return;
        auto &vv=zero?vpz:vp;
        vector<PII> evt;
        REP1(i,l,r) if ( re[i]>0 ) {
            evt.PB(MP((mx[i]-st[i]+re[i]-1)/re[i],i));
        }
        sort(ALL(evt));
        vv.clear();
        int ne=SZ(evt);
        LL v=0,d=sre;
        REP1(i,l,r) v+=st[i];
        vv.PB(P{0,v,d});
        for ( int i=0,j; i<ne; i=j ) {
            int t=evt[i].first;
            v+=(t-(i>0?evt[i-1].first:0))*d;
            for ( j=i; j<ne && evt[j].first==t; j++ ) {
                int w=evt[j].second;
                d-=re[w];
                v-=re[w]-(mx[w]-(st[w]+(t-1)*re[w]));
            }
            vv.PB(P{t,v,d});
        }
    }
    LL get( int t ) {
        auto &v=zero?vpz:vp;
        t-=last;
        last+=t;
        int ll=0,rr=SZ(v)-1;
        while ( ll!=rr ) {
            int mm=(ll+rr+1)/2;
            if ( v[mm].t>t ) rr=mm-1;
            else ll=mm;
        }
        LL ret=v[ll].v+(t-v[ll].t)*v[ll].d;
        if ( !zero ) {
            zero=1;
            REP1(i,l,r) st[i]=0;
        }
        build();
        return ret;
    }
    void flat( int t ) {
        zero=0;
        t-=last;
        last+=t;
        REP1(i,l,r) st[i]=min((LL)mx[i],st[i]+(LL)t*re[i]);
    }
} blk[BN];

int main() {
    RI(n);
    REP1(i,1,n) RI(st[i],mx[i],re[i]);
    int bn=0;
    for ( int i=1; i<=n; i+=K ) {
        auto &b=blk[bn];
        b.l=i;
        b.r=min(n,i+K-1);
        b.sre=b.last=b.zero=0;
        REP1(j,b.l,b.r) b.sre+=re[j];
        bn++;
    }
    REP(i,bn) blk[i].build();
    int m;
    RI(m);
    while ( m-- ) {
        int t,l,r;
        RI(t,l,r);
        LL ans=0;
        REP(i,bn) {
            auto &b=blk[i];
            if ( r<b.l || b.r<l ) continue;
            if ( l<=b.l && b.r<=r ) {
                ans+=b.get(t);
            } else {
                b.flat(t);
                int lb=max(l,b.l);
                int rb=min(r,b.r);
                REP1(j,lb,rb) {
                    ans+=st[j];
                    st[j]=0;
                }
                b.build();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}