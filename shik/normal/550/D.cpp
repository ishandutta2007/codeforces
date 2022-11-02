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

#define N 1000
int d[N],sd[N];
bool e[N][N];
bool cmp( int a, int b ) {
    return d[a]<d[b];
}
int main() {
    int k;
    RI(k);
    if ( k==1 ) {
        puts("YES");
        puts("2 1");
        puts("1 2");
        return 0;
    }
    if ( k%2==0 ) return puts("NO"),0;
    int n=499;
    REP1(i,1,n) d[i]=k;
    d[1]--;
    while ( 1 ) {
        REP1(i,1,n) sd[i]=i;
        sort(sd+1,sd+n+1,cmp);
        int u=sd[n];
        if ( d[u]==0 ) break;
        for ( int i=n-1; i>=1 && d[u]; i-- ) {
            int v=sd[i];
            if ( d[v] && !e[u][v] ) {
                e[u][v]=e[v][u]=1;
                d[u]--;
                d[v]--;
            }
        }
        assert(d[u]==0);
    }
    puts("YES");
    printf("%d %d\n",n*2,n*k);
    REP1(i,1,n) REP1(j,i+1,n) if ( e[i][j] ) printf("%d %d\n",i,j);
    printf("%d %d\n",1,n+1);
    REP1(i,1,n) REP1(j,i+1,n) if ( e[i][j] ) printf("%d %d\n",n+i,n+j);
    return 0;
}