//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=n;
pii a[1005][1005];
char s[1005][1005];
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
const char ds[]="DRUL";
signed main(){
	fz(i,1,n)	fz(j,1,m)	a[i][j].fi=read(),a[i][j].se=read();
	queue<pii> q;
	fz(i,1,n)	fz(j,1,m)	if(a[i][j].fi==i&&a[i][j].se==j)
		s[i][j]='X',q.push({i,j});
	while(!q.empty()){
		pii p=q.front();q.pop();
		int x=p.fi,y=p.se;
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m)	continue;
			if(s[xx][yy])	continue;
			if(a[xx][yy]==a[x][y]){
				s[xx][yy]=ds[(i+2)%4];
				q.push({xx,yy});
			}
		}
	}
	fz(i,1,n)	fz(j,1,m){
		if(a[i][j].fi!=-1&&!s[i][j]){
			giveup("INVALID\n");
		}
		if(a[i][j].fi==-1&&a[i][j].se==-1){
			bool flag=0;
			fz(k,0,3){
				int x=i+dx[k],y=j+dy[k];
				if(a[x][y].fi==-1){
					flag=1;
					s[i][j]=ds[k];
					break;
				}
			}
			if(!flag)	giveup("INVALID");
		}
	}
	puts("VALID");
	fz(i,1,n){
		fz(j,1,m)	cout<<s[i][j];puts("");
	}
	return 0;
}