// TwT514 {{{
#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define FOR(i,c) for (__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define PER(i,n) for (int i=(int)(n)-1; i>=0; i--)
#define PER1(i,b,a) for (int i=(int)(b); i>=(int)(a); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define REP1(i,a,b) for (int i=(int)(a); i<=(int)(b); i++)
#define ALL(x) (x).begin(),(x).end()
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define MP make_pair
#define PB push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// }}}

#define N 1010
int n,m;
LL bit[2][2][N][N];
LL ask( LL b[N][N], int x, int y ) {
    LL s=0;
    for ( int i=x; i; i-=i&-i ) for ( int j=y; j; j-=j&-j ) s^=b[i][j];
    return s;
}
void ins( LL b[N][N], int x, int y, LL v ) {
    for ( int i=x; i<=n; i+=i&-i ) for ( int j=y; j<=n; j+=j&-j ) b[i][j]^=v;
}
LL ask( int x, int y ) {
    LL s=0;
    s^=ask(bit[0][0],x,y);
    if ( x&1 ) s^=ask(bit[1][0],n-x,y);
    if ( y&1 ) s^=ask(bit[0][1],x,n-y);
    if ( (x&1) && (y&1) ) s^=ask(bit[1][1],n-x,n-y);
    return s;
}
void ins( int x, int y, LL v ) {
    if ( (x&1) && (y&1) ) ins(bit[0][0],x,y,v);
    if ( (x&1) ) ins(bit[0][1],x,n-y+1,v);
    if ( (y&1) ) ins(bit[1][0],n-x+1,y,v);
    ins(bit[1][1],n-x+1,n-y+1,v);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    while ( m-- ) {
        int op,x1,y1,x2,y2;
        LL v;
        cin>>op;
        cin>>x1>>y1>>x2>>y2;
        if ( op==1 ) {
            LL s=0;
            s^=ask(x1-1,y1-1);
            s^=ask(x1-1,y2  );
            s^=ask(x2  ,y1-1);
            s^=ask(x2  ,y2  );
            cout << s << "\n";
        } else {
            cin>>v;
            ins(x1-1,y1-1,v);
            ins(x1-1,y2  ,v);
            ins(x2  ,y1-1,v);
            ins(x2  ,y2  ,v);
        }
        /*
        cout << "=================\n";
        REP1(i,1,n) {
            REP1(j,1,n) cout << ask(i,j);
            cout << "\n";
        }
        cout << "=================\n";
        */
    }
    return 0;
}