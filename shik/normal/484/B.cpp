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

#define M 2000010
int c[M],l[M];
int main() {
    int n;
    RI(n);
    REP(i,n) {
        int x;
        RI(x);
        c[x]=1;
    }
    REP1(i,1,M-1) l[i]=c[i]?i:l[i-1];
    int ans=0;
    REP1(i,1,M-1) if ( c[i] ) {
        for ( int j=i; j<M; j+=i ) if ( l[j-1]>=i ) ans=max(ans,l[j-1]%i);
    }
    printf("%d\n",ans);
    return 0;
}