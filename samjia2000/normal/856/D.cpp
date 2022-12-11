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

const int N = 200010;

int fa[N][20];
int dep[N];
int n,m;
int f[N],son[N];
int Fa[N],val[N];
struct info{
	int id,x,y,v;
	friend bool operator < (info a,info b){return a.id<b.id;}
}e[N];

int lca(int x,int y){
	if (dep[x]<dep[y])swap(x,y);
	fd(i,17,0)
	if (dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if (x==y)return x;
	fd(i,17,0)
	if (fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

int getv(int x,int y){
	if (x==y)return 0;
	if (Fa[x]!=y){
		val[x]=val[x]+getv(Fa[x],y);
		Fa[x]=y;
	}
	return val[x];
}

int main(){
	n=get();m=get();
	dep[1]=1;
	fo(i,2,n){
		int x=get();
		Fa[i]=x;
		dep[i]=dep[fa[i][0]=x]+1;
		fo(t,1,17)fa[i][t]=fa[fa[i][t-1]][t-1];
	}
	fo(i,1,m){
		int x=get(),y=get(),v=get();
		e[i].id=lca(x,y);e[i].x=x;e[i].y=y;e[i].v=v;
	}
	sort(e+1,e+1+m);
	int w=m;
	fd(i,n,1){
		f[i]=son[i];
		for(;w&&e[w].id==i;w--)f[i]=max(f[i],getv(e[w].x,i)+getv(e[w].y,i)+e[w].v+son[i]);
		if (fa[i][0]){son[fa[i][0]]+=f[i];}
		val[i]=son[i]-f[i];
	}
	int ans=0;
	fo(i,1,n)ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}