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

#define N 3000010

struct BIT {
    int dat[N];
    void ins( int x, int v ) {
        for ( int i=x; i<N; i+=i&-i ) dat[i]+=v;
    }
    int ask( int x ) {
        int s=0;
        for ( int i=x; i; i-=i&-i ) s+=dat[i];
        return s;
    }
} bit;

struct P {
    int x,v;
};

map<int,int> mp;
int main() {
    int n;
    RI(n);
    REP(i,n) {
        int a,b;
        RI(a,b);
        if ( !mp.count(a) ) mp[a]=a;
        if ( !mp.count(b) ) mp[b]=b;
        swap(mp[a],mp[b]);
    }
    vector<P> v;
    int last=0;
    FOR(it,mp) {
        if ( it->first>last+1 ) v.PB(P{last+1,it->first-last-1});
        v.PB(P{it->second,1});
        last=it->first;
    }
    VI xs;
    FOR(it,v) xs.PB(it->x);
    sort(ALL(xs));
    FOR(it,v) it->x=lower_bound(ALL(xs),it->x)-xs.begin()+1;
    LL ans=0,tot=0;
    FOR(it,v) {
        ans+=1LL*it->v*(tot-bit.ask(it->x));
        bit.ins(it->x,it->v);
        tot+=it->v;
    }
    cout<<ans<<endl;
    return 0;
}