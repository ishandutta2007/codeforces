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

#define N 33
int n,m,s[N][N],t[N][N];

void print_sol( const vector<PII> &sol ) {
    printf("%d\n",SZ(sol)-1);
    FOR(it,sol) printf("%d %d\n",it->first,it->second);
}

bool test_lr( int nn, int ss[N], int tt[N], int l, int r ) {
    if ( l<r ) {
        REP1(i,l,r-1) swap(ss[i],ss[i+1]);
    } else {
        for ( int i=l; i>r; i-- ) swap(ss[i],ss[i-1]);
    }
    REP1(i,1,nn) if ( ss[i]!=tt[i] ) return 0;
    return 1;
}

bool test_n1( int l, int r ) {
    static int ss[N],tt[N];
    REP1(i,1,m) {
        ss[i]=s[1][i];
        tt[i]=t[1][i];
    }
    return test_lr(m,ss,tt,l,r);
}

bool test_m1( int l, int r ) {
    static int ss[N],tt[N];
    REP1(i,1,n) {
        ss[i]=s[i][1];
        tt[i]=t[i][1];
    }
    return test_lr(n,ss,tt,l,r);
}

void solve_n1() {
    REP1(i,1,m) REP1(j,1,m) if ( test_n1(i,j) ) {
        vector<PII> sol;
        if ( i<j ) {
            REP1(k,i,j) sol.PB(MP(1,k));
        } else {
            for ( int k=i; k>=j; k-- ) sol.PB(MP(1,k));
        }
        print_sol(sol);
        return;
    }
    puts("-1");
}

void solve_m1() {
    REP1(i,1,n) REP1(j,1,n) if ( test_m1(i,j) ) {
        vector<PII> sol;
        if ( i<j ) {
            REP1(k,i,j) sol.PB(MP(k,1));
        } else {
            for ( int k=i; k>=j; k-- ) sol.PB(MP(k,1));
        }
        print_sol(sol);
        return;
    }
    puts("-1");
}

int x,y;
vector<PII> sol;
bool fix[N][N];

int sg( int v ) { return (v>0)-(v<0); }

void go( int xx, int yy ) {
    //printf("go %d, %d\n",xx,yy);
    assert(max(abs(xx-x),abs(yy-y))==1);
    swap(s[x][y],s[xx][yy]);
    sol.PB(MP(xx,yy));
    x=xx; y=yy;
}

void move_to( int tx, int ty ) {
    //printf("move to: (%d,%d) => (%d,%d)\n",x,y,tx,ty);
    static int q[2*N*N],ql,qr,fx[N][N],fy[N][N],vis[N][N],vid;
    auto push=[&]( int xx, int yy ) {
        q[qr++]=xx;
        q[qr++]=yy;
        vis[xx][yy]=vid;
    };
    auto pop=[&]( int &xx, int &yy ) {
        xx=q[ql++];
        yy=q[ql++];
    };
    vid++;
    ql=qr=0;
    push(x,y);
    while ( ql!=qr && vis[tx][ty]!=vid ) {
        int xx,yy; pop(xx,yy);
        REP1(i,-1,+1) REP1(j,-1,+1) {
            int nx=xx+i;
            int ny=yy+j;
            if ( nx<1 || nx>n || ny<1 || ny>m ) continue;
            if ( fix[nx][ny] || vis[nx][ny]==vid ) continue;
            fx[nx][ny]=xx;
            fy[nx][ny]=yy;
            push(nx,ny);
        }
    }
    assert(vis[tx][ty]==vid);
    vector<PII> v;
    while ( tx!=x || ty!=y ) {
        v.PB(MP(tx,ty));
        int ntx=fx[tx][ty];
        int nty=fy[tx][ty];
        tx=ntx; ty=nty;
    }
    reverse(ALL(v));
    FOR(it,v) go(it->first,it->second);
}

void move_one( int x1, int y1, int x2, int y2 ) {
    //printf("move one (%d,%d) => (%d,%d)\n",x1,y1,x2,y2);
    while ( x1!=x2 || y1!=y2 ) {
        int dx=sg(x2-x1);
        int dy=sg(y2-y1);
        //printf("(%d, %d)\n",dx,dy);
        int nx1=x1,ny1=y1;
        if ( !fix[x1+dx][y1+dy] ) nx1=x1+dx,ny1=y1+dy;
        else if ( dx!=0 && !fix[x1+dx][y1] ) nx1=x1+dx;
        else if ( dy!=0 && !fix[x1][y1+dy] ) ny1=y1+dy;
        assert(x1!=nx1 || y1!=ny1);
        //printf("-- move one: %d,%d => %d,%d\n",x1,y1,nx1,ny1);
        fix[x1][y1]=1;
        move_to(nx1,ny1);
        fix[x1][y1]=0;
        go(x1,y1);
        x1=nx1; y1=ny1;
    }
}

void solve_one( int gx, int gy ) {
    int gz=t[gx][gy];
    //printf("solve_one (%d,%d,%d)\n",gx,gy,gz);
    REP1(i,1,n) REP1(j,1,m) if ( (i!=x || j!=y) && !fix[i][j] && s[i][j]==gz ) {
        move_one(i,j,gx,gy);
        i=j=N;
    }
    //REP1(i,1,n) REP1(j,1,m) printf("%d%c",s[i][j],j==m?'\n':' ');
    assert(s[gx][gy]==t[gx][gy]);
    fix[gx][gy]=1;
}

void solve() {
    REP1(i,1,n) REP1(j,1,m) if ( s[i][j]==t[n][m] ) {
        x=i; y=j;
        i=j=N;
    }
    assert(x && y);
    sol.PB(MP(x,y));
    REP1(i,1,n-2) REP1(j,1,m) solve_one(i,j);
    REP1(i,1,m-2) {
        solve_one(n-1,i);
        solve_one(n,i);
    }
    assert(n-1<=x && x<=n);
    assert(m-1<=y && y<=m);
    while ( 1 ) {
        bool done=1;
        //REP1(i,n-1,n) REP1(j,m-1,m) printf("(%d, %d) ",s[i][j],t[i][j]); puts("");
        REP1(i,n-1,n) REP1(j,m-1,m) if ( s[i][j]!=t[i][j] ) done=0;
        if ( done ) break;
        int nx=n-1+rand()%2;
        int ny=m-1+rand()%2;
        if ( x==nx && y==ny ) continue;
        go(nx,ny);
    }
    REP1(i,1,n) REP1(j,1,m) assert(s[i][j]==t[i][j]);
    print_sol(sol);
}

int main() {
    srand(time(0)^514514514^getpid());
    RI(n,m);
    REP1(i,1,n) REP1(j,1,m) RI(s[i][j]);
    REP1(i,1,n) REP1(j,1,m) RI(t[i][j]);
    int c[1000]={};
    REP1(i,1,n) REP1(j,1,m) c[s[i][j]]++;
    REP1(i,1,n) REP1(j,1,m) c[t[i][j]]--;
    REP(i,1000) if ( c[i]!=0 ) {
        puts("-1");
        return 0;
    }
    if ( n==1 ) solve_n1();
    else if ( m==1 ) solve_m1();
    else solve();
    //fprintf(stderr, "%d %d %d\n",n,m,SZ(sol));
    return 0;
}