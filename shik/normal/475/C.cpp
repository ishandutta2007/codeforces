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

#define N 1010
#define INF 514514514

int n,m;
char s[N][N];
int ss[N][N];

bool empty( int x1, int y1, int x2, int y2 ) {
    if ( x2>=n || y2>=m ) return 0;
    int v=ss[x2+1][y2+1]-ss[x2+1][y1]-ss[x1][y2+1]+ss[x1][y1];
    //printf("(%d,%d) - (%d,%d) = %d\n",x1,y1,x2,y2,v);
    return v==0;
}

void mirror() {
    static char t[N][N];
    REP(i,n) REP(j,m) t[j][i]=s[i][j];
    swap(n,m);
    memset(s,0,sizeof(s));
    REP(i,n) REP(j,m) s[i][j]=t[i][j];
}

bool mark[N][N];
int sm[N][N];

bool check( int w, int h ) {
    //printf("chk %d,%d\n",w,h);
    //REP(i,n) REP(j,m) if ( mark[i][j] ) printf("== %d,%d\n",i,j);
    memset(sm,0,sizeof(sm));
    REP(i,n) REP(j,m) sm[i+1][j+1]=sm[i+1][j]+sm[i][j+1]-sm[i][j]+mark[i][j];
    REP(i,n) REP(j,m) if ( s[i][j]=='X' ) {
        int x1=max(0,i-h+1);
        int y1=max(0,j-w+1);
        int x2=i;
        int y2=j;
        int v=sm[x2+1][y2+1]-sm[x2+1][y1]-sm[x1][y2+1]+sm[x1][y1];
        //if ( v==0 ) printf("%d,%d\n",i,j);
        if ( v==0 ) return 0;
    }
    return 1;
}

int solve() {
    memset(ss,0,sizeof(ss));
    REP(i,n) REP(j,m) ss[i+1][j+1]=ss[i+1][j]+ss[i][j+1]-ss[i][j]+(s[i][j]=='.');
    memset(mark,0,sizeof(mark));
    int x=-1,y=-1;
    REP(i,n) REP(j,m) if ( s[i][j]=='X' ) {
        x=i;
        y=j;
        i=j=N;
    }
    assert(x!=-1);
    int w=0;
    while ( s[x][y+w]=='X' ) w++;
    //printf("w = %d\n",w);
    while ( x<n && empty(x,y,x,y+w-1) && s[x][y+w]!='X' ) {
        mark[x][y]=1;
        x++;
    }
    //printf("x = %d, %d\n",x,!!empty(x,y,x,y+w-1));
    if ( x==n || !empty(x,y,x,y+w-1) ) {
        if ( !check(w,1) ) return INF;
        else return w;
    }
    int h=0;
    while ( empty(x,y,x+h,y+w-1) ) h++;
    //printf("h = %d\n",h);
    while ( 1 ) {
        //printf("(%d,%d)\n",x,y);
        mark[x][y]=1;
        if ( empty(x+1,y,x+h,y+w-1) ) x++;
        else if ( empty(x,y+1,x+h-1,y+w) ) y++;
        else break;
    }
    if ( !check(w,h) ) return INF;
    else return w*h;
}

int main() {
    RI(n,m);
    REP(i,n) scanf("%s",s[i]);
    //REP(i,n) puts(s[i]);
    int a1=solve();
    mirror();
    //REP(i,n) puts(s[i]);
    int a2=solve();
    int ans=min(a1,a2);
    if ( ans==INF ) ans=-1;
    printf("%d\n",ans);
    return 0;
}