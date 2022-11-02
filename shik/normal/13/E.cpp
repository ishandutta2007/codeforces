// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100010
using namespace std;
struct LCT {
	int fa[N],fb[N],ch[N][2],sz[N],nv;
	void pull( int x ) {
		sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	}
	void join( int x, int y, int d ) {
		if ( d<2 ) ch[y][d]=x;
		fa[x]=y;
		fb[x]=d;
	}
	void rotate( int x ) {
		int y=fa[x],d=fb[x];
		join(ch[x][!d],y,d);
		join(x,fa[y],fb[y]);
		join(y,x,!d);
		pull(y); pull(x);
	}
	void splay( int x, int f=0 ) {
		while ( fb[x]!=2 && fa[x]!=f ) rotate(x);
	}
	void access( int y, int x=0 ) {
		do {
			splay(y);
			fb[ch[y][1]]=2;
			join(x,y,1);
			x=y;
			y=fa[y];
		} while ( y );
	}
	int get_root( int x ) {
		access(x);
		splay(x);
		while ( ch[x][0] ) x=ch[x][0];
		splay(x);
		return x;
	}
	void cut( int x ) {
		access(x);
		splay(x);
		join(ch[x][0],0,2);
		ch[x][0]=0;
	}
	void link( int x, int y ) {
		access(x);
		join(x,y,2);
		access(x);
	}
	void init( int n ) {
		nv=n;
		for ( int i=1; i<=n; i++ ) {
			fa[i]=ch[i][0]=ch[i][1]=0;
			fb[i]=2;
			sz[i]=1;
		}
	}
	int get_dep( int x ) {
		access(x);
		splay(x);
		return sz[ch[x][0]]+1;
	}
	void debug( int n ) {
		puts("================ debug ================");
		for ( int i=0; i<=n; i++ ) printf("%d: fa=%d, fb=%d, lch=%d, rch=%d, sz=%d\n",i,fa[i],fb[i],ch[i][0],ch[i][1],sz[i]);
	}
} lct;
int main()
{
	int n,m,op,a,b;
	scanf("%d%d",&n,&m);
	lct.init(n);
	for ( int i=1; i<=n; i++ ) {
		scanf("%d",&a);
		if ( i+a<=n ) lct.link(i,i+a);
	}
	while ( m-- ) {
		scanf("%d",&op);
		if ( op==0 ) {
			scanf("%d%d",&a,&b);
			lct.cut(a);
			lct.link(a,a+b>n?0:a+b);
		} else if ( op==1 ) {
			scanf("%d",&a);
			printf("%d %d\n",lct.get_root(a),lct.get_dep(a));
		}
	}
	return 0;
}