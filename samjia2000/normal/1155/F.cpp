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

const int N = 15;
const int L = (1<<14)+5;

int f[L][N][N],g[L][N];
int lf[L][N][N];
bool bz[N][N];
int n,m;
bool can[L][N];
bool ans[N][N];

void solve(int u,int x,int y){
	if (!u){
		ans[x][y]=ans[y][x]=1;
		return;
	}
	if (lf[u][x][y]<0){
		if (lf[u][x][y]==-n-1){
			ans[x][y]=ans[y][x]=1;
			int mi=1e9,w;
			fo(i,1,n)
			if ((u&(1<<(i-1)))==0){
				if (mi>f[u][x][i]){
					mi=f[u][x][i];
					w=i;
					//break;
				}
			}
			solve(u,x,w);
		}
		else{
			int z=-lf[u][x][y];
			ans[x][z]=ans[z][x]=1;
			solve(u^(1<<(z-1)),z,y);
		}
		return;
	}
	int v=lf[u][x][y]>>1;
	int mi1=1e9,mi2=1e9,w1,w2;
	fo(i,1,n)
	if ((u&(1<<(i-1)))==0){
		//mi1=min(mi1,f[u^v][x][i]),mi2=min(mi2,f[v][x][i]);
		if (mi1>f[u^v][x][i])w1=i,mi1=f[u^v][x][i];
		if (mi2>f[v][x][i])w2=i,mi2=f[v][x][i];
	}
	if (lf[u][x][y]%2==0){
		solve(u^v,x,y);
		solve(v,x,w2);
	}
	else{
		solve(u^v,x,w1);
		solve(v,x,y);
	}
}

int main(){
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get();
		bz[x][y]=bz[y][x]=1;
	}
	fo(u,0,(1<<n)-1)fo(x,1,n)fo(y,1,n)f[u][x][y]=1e9;
	fo(i,1,n)fo(j,1,n)if (bz[i][j])f[0][i][j]=1,lf[0][i][j]=-n-1;
	fo(u,1,(1<<n)-1)
		fo(x,1,n)
		if ((u&(1<<(x-1)))==0){
			fo(y,1,n)
			if (bz[x][y]&&(u&(1<<(y-1)))>0){
				fo(i,1,n)
				if ((u&(1<<(i-1)))==0&&(x!=i||lf[u^(1<<(y-1))][y][i]!=-n-1)){
					if (f[u][x][i]>f[u^(1<<(y-1))][y][i]+1){
						f[u][x][i]=f[u^(1<<(y-1))][y][i]+1;
						lf[u][x][i]=-y;
					}
				}
			}
			int r=((1<<n)-1)^u;
			for(int v=(r+1)&u;v<u;v=((v^r)+1)&u){
				int mi1=1e9,mi2=1e9;
				fo(i,1,n)
				if ((u&(1<<(i-1)))==0)mi1=min(mi1,f[u^v][x][i]),mi2=min(mi2,f[v][x][i]);
				fo(i,1,n)
				if ((u&(1<<(i-1)))==0){
					if (f[u][x][i]>f[u^v][x][i]+mi2){
						f[u][x][i]=f[u^v][x][i]+mi2;
						lf[u][x][i]=v*2;
					}
					if (f[u][x][i]>f[v][x][i]+mi1){
						f[u][x][i]=f[v][x][i]+mi1;
						lf[u][x][i]=v*2+1;
					}
				}
			}
			int mi=1e9;
			fo(i,1,n)
			if ((u&(1<<(i-1)))==0)mi=min(mi,f[u][x][i]);
			fo(i,1,n)
			if ((u&(1<<(i-1)))==0&&bz[x][i]){
				if (f[u][x][i]>mi+1){
					f[u][x][i]=mi+1;
					lf[u][x][i]=-n-1;
				}
			}
		}
	printf("%d\n",f[(1<<n)-2][1][1]);
	solve((1<<n)-2,1,1);
	fo(i,1,n)
		fo(j,i+1,n)
		if (ans[i][j])printf("%d %d\n",i,j);
	return 0;
}