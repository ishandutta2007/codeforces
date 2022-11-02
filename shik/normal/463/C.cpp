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

#define N 2010
int n,a[N][N];
LL s1[N][N],s2[N][N],s3[N][N],s4[N][N];
int main() {
    RI(n);
    REP1(i,1,n) REP1(j,1,n) RI(a[i][j]);
    REP1(i,1,n) REP1(j,1,n) {
        s1[i][j]=s1[i-1][j-1]+a[i][j];
        s2[i][j]=s2[i-1][j+1]+a[i][j];
    }
    for ( int i=n; i>=1; i-- ) REP1(j,1,n) {
        s3[i][j]=s3[i+1][j-1]+a[i][j];
        s4[i][j]=s4[i+1][j+1]+a[i][j];
    }
    LL mx[2]={-1,-1};
    int x[2]={},y[2]={};
    REP1(i,1,n) REP1(j,1,n) {
        int k=(i+j)&1;
        LL v=s1[i][j]+s2[i][j]+s3[i][j]+s4[i][j]-3LL*a[i][j];
        if ( v>mx[k] ) {
            mx[k]=v;
            x[k]=i;
            y[k]=j;
        }
    }
    cout<<mx[0]+mx[1]<<endl;
    printf("%d %d %d %d\n",x[0],y[0],x[1],y[1]);
    return 0;
}