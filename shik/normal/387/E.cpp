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

struct P {
    int val,pos;
};

#define N 1000010

struct BIT {
    int dat[N];
    void ins( int x ) {
        for ( int i=x; i<N; i+=i&-i ) dat[i]++;
    }
    int ask( int x ) {
        int s=0;
        for ( int i=x; i; i-=i&-i ) s+=dat[i];
        return s;
    }
    int ask( int l, int r ) {
        if ( l>r ) return 0;
        int s=ask(r);
        if ( l>0 ) s-=ask(l-1);
        return s;
    }
} bit;

int n,m,a[N],b[N];
bool rem[N];
int main() {
    RI(n,m);
    REP1(i,1,n) RI(a[i]);
    REP1(i,1,m) RI(b[i]);
    REP1(i,1,m) rem[b[i]]=1;
    vector<P> v;
    REP1(i,1,n) v.PB(P{a[i],i});
    sort(v.begin(),v.end(),[](P x, P y) { return x.val<y.val; });
    set<int> app;
    app.insert(0);
    app.insert(n+1);
    LL ans=0;
    for (auto p : v) {
        if ( rem[p.val] ) {
            app.insert(p.pos);
        } else {
            auto it=--app.lower_bound(p.pos);
            auto jt=app.upper_bound(p.pos);
            ans+=*jt-*it-1;
            ans-=bit.ask(*it+1,*jt-1);
            bit.ins(p.pos);
        }
    }
    cout<<ans<<endl;
    return 0;
}