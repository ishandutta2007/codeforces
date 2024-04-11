#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 2333,inf=0x3f3f3f3f;
int n,m,R,C,x,y,a[N][N],b[N][N],res;char s[N][N];
Pii q[N*N*4];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void bfs(){
	memset(a,inf,sizeof(a));memset(b,inf,sizeof(b));
	int f=N*N+5,r=f;
	q[r++]=Pii(R,C);a[R][C]=0;b[R][C]=0;
	while(f!=r){
		int u=q[f].fi,v=q[f].se;f++;if(a[u][v]<=x&&b[u][v]<=y)res++;
		rep(i,0,3){
			int nx=u+dx[i],ny=v+dy[i];//(u,v)-->(nx,ny)
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]==inf&&s[nx][ny]!='*'){
				a[nx][ny]=a[u][v]+(i==1);b[nx][ny]=b[u][v]+(i==0);
				if(a[nx][ny]<=x&&b[nx][ny]<=y){
					if(a[nx][ny]+b[nx][ny]==b[u][v]+a[u][v])q[--f]=Pii(nx,ny);
					else q[r++]=Pii(nx,ny);
				}
			}
		}
	}
}
int main() {
	read(n);read(m);
	read(R);read(C);
	read(x);read(y);
	rep(i,1,n)scanf("%s",s[i]+1);
	bfs();cout<<res;
	return 0;
}