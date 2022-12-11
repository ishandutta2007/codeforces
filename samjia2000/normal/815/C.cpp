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

const int N = 5010;
const int INF = 1E+9+10;

int n,b;
struct edge{
	int x,nxt;
}e[N];
int h[N],tot;
int siz[N];
struct good{
	int c,d;
}a[N];
int f[2][N][N];

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

int k;
int w[N];

bool cmp(int x,int y){
	return siz[x]<siz[y];
}

void dfs(int x){
	siz[x]=1;
	for(int p=h[x];p;p=e[p].nxt)dfs(e[p].x);
	k=0;
	for(int p=h[x];p;p=e[p].nxt)w[++k]=e[p].x;
	sort(w+1,w+1+k,cmp);
	f[0][x][0]=0;
	f[0][x][1]=a[x].c;
	f[1][x][1]=a[x].c-a[x].d;
	fo(i,1,k){
		fd(a,siz[x],0)
			fo(b,0,siz[w[i]]){
				f[0][x][a+b]=min(f[0][x][a+b],f[0][x][a]+f[0][w[i]][b]);
				f[1][x][a+b]=min(f[1][x][a+b],f[1][x][a]+min(f[0][w[i]][b],f[1][w[i]][b]));
			}
		siz[x]+=siz[w[i]];
	}
}

int main(){
	n=get();b=get();
	fo(i,1,n){
		a[i].c=get();a[i].d=get();
		if (i>1){
			int x=get();
			inse(x,i);
		}
	}
	fo(i,1,n)fo(j,0,n)f[0][i][j]=f[1][i][j]=INF;
	dfs(1);
	fd(i,n,0)
	if (min(f[0][1][i],f[1][1][i])<=b){printf("%d\n",i);break;}
	return 0;
}