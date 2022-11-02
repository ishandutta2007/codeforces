// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
#define N 300010
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
int n,m,a[N],p[N];
set<PII> s;
void s_ins( int l, int r ) {
    bit.ins(l,+1);
    s.insert(PII(l,r));
}
void s_del( set<PII>::const_iterator it ) {
    bit.ins(it->first,-1);
    s.erase(it);
}
void del( int x ) {
    auto it=s.upper_bound(PII(x,N));
    it--;
    int l=it->first;
    int r=it->second;
    s_del(it);
    if ( l<=x-1 ) s_ins(l,x-1);
    s_ins(x,x);
    if ( x+1<=r ) s_ins(x+1,r);
}
void ins( int x ) {
    {
        auto it=s.upper_bound(PII(x,N)); it--;
        if ( it!=s.begin() ) {
            auto jt=it; jt--;
            if ( p[jt->second] < p[it->first] ) {
                int l=jt->first;
                int r=it->second;
                s_del(it);
                s_del(jt);
                s_ins(l,r);
            }
        }
    }
    {
        auto it=s.upper_bound(PII(x,N));
        if ( it!=s.end() ) {
            auto jt=it; jt--;
            if ( p[jt->second] < p[it->first] ) {
                int l=jt->first;
                int r=it->second;
                s_del(it);
                s_del(jt);
                s_ins(l,r);
            }
        }

    }
}
int get_left( int x ) {
    auto it=s.upper_bound(PII(x,N));
    it--;
    return it->first;
}
int main()
{
    scanf("%d",&n);
    for ( int i=1; i<=n; i++ ) scanf("%d",a+i);
    for ( int i=1; i<=n; i++ ) p[a[i]]=i;
    for ( int i=1,j; i<=n; i=j ) {
        for ( j=i+1; j<=n && p[j]>=p[j-1]; j++ );
        s_ins(i,j-1);
    }
    scanf("%d",&m);
    while ( m-- ) {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if ( op==1 ) {
            int l=get_left(x);
            int r=get_left(y);
            printf("%d\n",bit.ask(r)-bit.ask(l-1));
        } else {
            del(a[x]);
            del(a[y]);
            swap(a[x],a[y]);
            swap(p[a[x]],p[a[y]]);
            ins(a[x]);
            ins(a[y]);
        }
        //for ( int i=1; i<=n; i++ ) printf("%d ",a[i]); puts("");
        //FOR(it,s) printf("(%d,%d)\n",it->first,it->second);
    }
    return 0;
}