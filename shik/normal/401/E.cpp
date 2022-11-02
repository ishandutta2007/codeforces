// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for (auto it=begin(c); it!=end(c); it++)
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long LL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
/// }}}

#define N 150010

VI fac[N];
int cnt[N];
void predo() {
    for ( int i=2; i<N; i++ ) for ( int j=i; j<N; j+=i ) fac[j].PB(i);
    for ( int i=2; i<N; i++ ) if ( SZ(fac[i])==1 ) for ( int j=i; j<N; j+=i ) cnt[j]++;
    for ( int i=2; i<N; i++ ) cnt[i]=(cnt[i]%2==1 ? -1 : +1);
    for ( int i=2; i*i<N; i++ ) if ( SZ(fac[i])==1 ) for ( int j=i*i; j<N; j+=i*i ) cnt[j]=0;
}

LL p;

LL shik( LL l, LL r ) {
    return (r+l)*(r-l+1)/2%p;
}

LL shik( LL l, LL r, LL d ) {
    return (r+l)*((r-l)/d+1)/2%p;
}

int main() {
    predo();
    LL n,m,l,r;
    cin>>n>>m>>l>>r>>p;
    LL ans=0;
    for ( LL dx=1; dx<=n && dx*dx<=r*r; dx++ ) {
        LL ly=dx>=l ? 0 : sqrt(l*l-dx*dx);
        LL ry=sqrt(r*r-dx*dx);
        while ( ly==0 || dx*dx+ly*ly<l*l ) ly++;
        while ( dx*dx+ry*ry>r*r ) ry--;
        if ( ry>m ) ry=m;
        if ( ly>ry ) continue;
        ans+=(n+1-dx)*shik(m+1-ry,m+1-ly)%p;
        for (auto f : fac[dx]) {
            LL lly=(ly+f-1)/f;
            LL rry=ry/f;
            if ( lly>rry ) continue;
            LL now=cnt[f]*(n+1-dx)*shik(m+1-f*rry,m+1-f*lly,f)%p;
            ans+=now;
        }
    }
    ans*=2;
    if ( l==1 ) {
        ans+=(n+1)*m%p;
        ans+=n*(m+1)%p;
    }
    ans%=p;
    if ( ans<0 ) ans+=p;
    cout<<ans<<endl;
    return 0;
}