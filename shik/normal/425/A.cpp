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

#define N 210
int n,k,a[N];
int solve( int l, int r ) {
    int b[N],c[N];
    int nb=r-l+1;
    int nc=0;
    REP(i,nb) b[i]=a[l+i];
    REP1(i,1,l-1) c[nc++]=a[i];
    REP1(i,r+1,n) c[nc++]=a[i];
    int kk=min(k,min(nb,nc));
    partial_sort(b,b+kk,b+nb);
    partial_sort(c,c+kk,c+nc,greater<int>());
    int ret=0;
    REP(i,kk) {
        if ( b[i]>=c[i] ) break;
        swap(b[i],c[i]);
    }
    REP(i,nb) ret+=b[i];
    return ret;
}
int main() {
    RI(n,k);
    REP1(i,1,n) RI(a[i]);
    int ans=-1e9;
    REP1(i,1,n) REP1(j,i,n) ans=max(ans,solve(i,j));
    printf("%d\n",ans);
    return 0;
}