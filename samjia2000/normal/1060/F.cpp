#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 55;

db f[N][N];
db f1[N],g1[N];
int siz[N];
int fa[N];
int e[N][N];
int s[N];
int n;
bool vis[N];
db c[N][N];

void dfs(int x){
	vis[x]=1;
	siz[x]=0;
	fo(t,1,s[x]){
		int y=e[x][t];
		if (!vis[y]){
			fa[y]=x;
			dfs(y);
			siz[x]+=siz[y]+1;
		}
	}
	fo(i,0,n)f[x][i]=0;
	int pre=0;
	f[x][0]=1;
	fo(t,1,s[x]){
		int y=e[x][t];
		if (fa[y]==x){
			fo(i,0,pre+siz[y]+1)f1[i]=0;
			fo(px,1,pre)
				fo(py,1,siz[y]+1){
					fo(w,px,siz[y]+1+px)
					if (py-1+px-1>=w-1)f1[w]=f1[w]+f[x][px]*f[y][py]*c[w-1][px-1]*c[pre+siz[y]+1-w][pre-px];
					fo(w,py,pre+py)
					if (py-1+px-1>=w-1)f1[w]=f1[w]+f[x][px]*f[y][py]*c[w-1][py-1]*c[pre+siz[y]+1-w][siz[y]+1-py];
				}
			f1[0]=f[x][0]*f[y][0]*c[pre+siz[y]+1][pre];
			fo(px,1,pre)
				fo(w,px,siz[y]+1+px)
				f1[w]=f1[w]+f[x][px]*f[y][0]*c[w-1][px-1]*c[pre+siz[y]+1-w][pre-px];
			fo(py,1,siz[y]+1)
				fo(w,py,pre+py)
				f1[w]=f1[w]+f[x][0]*f[y][py]*c[w-1][py-1]*c[pre+siz[y]+1-w][siz[y]+1-py];
			fo(i,0,pre+siz[y]+1)f[x][i]=f1[i];
			pre+=siz[y]+1;
		}
	}
	fo(i,0,pre+1)f1[i]=0;
	fo(px,1,pre){
		f1[px+1]=f1[px+1]+f[x][px]*px;
		fo(w,1,px)f1[w]=f1[w]-f[x][px]*(0.5);
	}
	f1[0]=f1[0]+f[x][0]*(pre+1);
	fo(w,1,pre+1)f1[w]=f1[w]-f[x][0]*(0.5);
	fo(i,0,pre+1)f[x][i]=f1[i];
}

int main(){
	n=get();
	c[0][0]=1;
	fo(i,1,n){
		c[i][0]=1;
		fo(j,1,i)c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	fo(i,2,n){
		int x=get(),y=get();
		e[x][++s[x]]=y;
		e[y][++s[y]]=x;
	}
	fo(st,1,n){
		fo(i,1,n)vis[i]=0,fa[i]=0;
		dfs(st);
		db ans=1;
		fo(t,1,s[st]){
			int x=e[st][t];
			db tmp=0;
			fo(i,0,siz[x]+1)tmp=tmp+f[x][i];
			fo(i,1,siz[x]+1)tmp=tmp/i;
			ans=ans*tmp;
		}
		printf("%.9lf\n",ans);
	}
	return 0;
}