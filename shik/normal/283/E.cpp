// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef long long LL;
#define N 400010
struct Seg {
    int sum[N],val[N];
    int get( int id, int l, int r ) {
        if ( val[id]==0 ) return sum[id];
        else return (r-l+1)-sum[id];
    }
    void push( int id ) {
        if ( !val[id] ) return;
        val[id]=0;
        val[id*2]^=1;
        val[id*2+1]^=1;
    }
    void pull( int id, int l, int r ) {
        int m=(l+r)/2;
        sum[id]=get(id*2,l,m)+get(id*2+1,m+1,r);
    }
    void init( int id, int l, int r ) {
        if ( l==r ) {
            sum[id]=0;
            val[id]=0;
            return;
        }
        int m=(l+r)/2;
        init(id*2,l,m);
        init(id*2+1,m+1,r);
        pull(id,l,r);
    }
    void rev( int id, int l, int r, int ql, int qr ) {
        if ( qr<l || r<ql ) return;
        if ( ql<=l && r<=qr ) {
            val[id]^=1;
            return;
        }
        push(id);
        int m=(l+r)/2;
        rev(id*2,l,m,ql,qr);
        rev(id*2+1,m+1,r,ql,qr);
        pull(id,l,r);
    }
    int ask( int id, int l, int r, int ql, int qr ) {
        if ( qr<l || r<ql ) return 0;
        if ( ql<=l && r<=qr ) return get(id,l,r);
        push(id);
        int m=(l+r)/2;
        int ret=ask(id*2,l,m,ql,qr)+ask(id*2+1,m+1,r,ql,qr);
        pull(id,l,r);
        return ret;
    }
} seg;
int s[N],a[N],b[N];
vector<int> in[N],out[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for ( int i=1; i<=n; i++ ) scanf("%d",s+i);
    sort(s+1,s+n+1);
    for ( int i=1; i<=m; i++ ) scanf("%d%d",a+i,b+i);
    for ( int i=1; i<=m; i++ ) a[i]=lower_bound(s+1,s+n+1,a[i])-s;
    for ( int i=1; i<=m; i++ ) b[i]=upper_bound(s+1,s+n+1,b[i])-s-1;
    for ( int i=1; i<=m; i++ ) {
        if ( a[i]<1 ) a[i]=1;
        if ( b[i]>n ) b[i]=n;
        if ( a[i]>b[i] ) continue;
        in[a[i]].push_back(i);
        out[b[i]].push_back(i);
    }
    LL ans=1LL*n*(n-1)*(n-2)/6;
    for ( int i=1; i<=n; i++ ) {
        FOR(it,in[i]) seg.rev(1,1,n,a[*it],b[*it]);
        LL lc=i-1-seg.ask(1,1,n,1,i-1);
        LL rc=seg.ask(1,1,n,i+1,n);
        ans-=lc*rc;
        ans-=lc*(lc-1)/2;
        ans-=rc*(rc-1)/2;
        FOR(it,out[i]) seg.rev(1,1,n,a[*it],b[*it]);
    }
    cout<<ans<<endl;
    return 0;
}