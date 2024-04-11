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

int f[N][2];
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int n,m;
int dep[N];

void inse(int x,int y){
	e[++tot].x=y;
	e[tot].nxt=h[x];
	h[x]=tot;
}

void dfs(int x){
	bool bz=0;
	for(int p=h[x];p;p=e[p].nxt)
	if (!dep[e[p].x]){
		dep[e[p].x]=dep[x]+1;
		bz=1;
		dfs(e[p].x);
	}
	if (!bz){
		f[x][1]=f[x][0]=1;
		m++;
		return;
	}
	f[x][1]=n;
	for(int p=h[x];p;p=e[p].nxt)
	if (dep[e[p].x]==dep[x]+1){
		f[x][1]=min(f[x][1],f[e[p].x][0]);
		f[x][0]+=f[e[p].x][1];
	}
}

int main(){
	n=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y);
		inse(y,x);
	}
	dep[1]=1;
	dfs(1);
	printf("%d %d\n",m-f[1][1]+1,f[1][0]);
	return 0;
}