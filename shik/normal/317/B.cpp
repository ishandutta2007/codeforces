// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
#define N 200
int buf[N][N],buf2[N][N],ql,qr;
char que[30000000];
#define f(x,y) buf[x+N/2][y+N/2]
#define in(x,y) buf2[x+N/2][y+N/2]
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    f(0,0)=n;
    que[qr++]=0;
    que[qr++]=0;
    while ( ql!=qr ) {
        int x=que[ql++];
        int y=que[ql++];
        in(x,y)=0;
        int c=f(x,y)/4;
        f(x,y)%=4;
        for ( int i=0; i<4; i++ ) {
            int nx=x+dx[i];
            int ny=y+dy[i];
            f(nx,ny)+=c;
            if ( !in(nx,ny) && f(nx,ny)>=4 ) {
                in(nx,ny)=1;
                que[qr++]=nx;
                que[qr++]=ny;
            }
        }
    }
    while ( m-- ) {
        int x,y;
        scanf("%d%d",&x,&y);
        if ( x<-80 || y<-80 || x>80 || y>80 ) puts("0");
        else printf("%d\n",f(x,y));
    }
    return 0;
}