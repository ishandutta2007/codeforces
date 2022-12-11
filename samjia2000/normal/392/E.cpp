#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

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

const int N = 410;
const int INF = 1e+9;

int f[N][N],g[2][N][N];
int n;
int v[N],w[N];
int nxt[N];
map<int,int>mp;
int t[N][2];
int F[N];

int main(){
	n=get();
	fo(i,1,n)v[i]=get();
	fo(i,1,n)w[i]=get();
	fo(i,1,n){
		fo(j,i+1,n)f[i][j]=-INF;
		f[i][i]=v[1];
	}
	fd(i,n,1){
		nxt[i]=mp[w[i]];
		t[i][0]=mp[w[i]-1];
		t[i][1]=mp[w[i]+1];
		mp[w[i]]=i;
	}
	fd(i,n,1){
		fo(x,i,n)
			fo(y,1,x-i+1)g[0][x][y]=g[1][x][y]=-INF;
		g[0][i][1]=g[1][i][1]=v[1];
		fo(j,i,n){
				fo(k,1,j-i+1){
					if (g[0][j][k]==-INF)continue;
					for(int y=t[j][0];y;y=nxt[y])
						g[0][y][k+1]=max(g[0][y][k+1],g[0][j][k]-v[k]+v[k+1]+f[j+1][y-1]);
				}
				fo(k,1,j-i+1){
					if (g[1][j][k]==-INF)continue;
					for(int y=t[j][1];y;y=nxt[y])
						g[1][y][k+1]=max(g[1][y][k+1],g[1][j][k]-v[k]+v[k+1]+f[j+1][y-1]);
					for(int y=t[j][0];y;y=nxt[y])
						g[0][y][k+1]=max(g[0][y][k+1],g[1][j][k]-v[k]+v[k+1]+f[j+1][y-1]);
				}
		}
		f[i][i]=v[1];
		fo(j,i+1,n){
			fo(k,1,j-i+1)
				f[i][j]=max(max(f[i][j],f[i][j-k]+f[j-k+1][j]),max(g[1][j][k],g[0][j][k]));
		}
	}
	fo(i,1,n)F[i]=-INF;
	fo(i,0,n-1){
		fo(j,i+1,n)
		F[j]=max(F[j],F[i]+f[i+1][j]);
		F[i+1]=max(F[i+1],F[i]);
	}
	printf("%d\n",F[n]);
	return 0;
}