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

const int N = 1005;

int n;
db p[N][N];
db f[N],g[N];
int num[N];
db pre[N],now[N];

bool vis[N];

int main(){
	n=get();
	fo(i,1,n)fo(j,1,n){scanf("%lf",&p[i][j]);p[i][j]/=100;}
	f[n]=0;
	fo(i,1,n-1)f[i]=1e9;
	fo(i,1,n)pre[i]=1,now[i]=0;
	fo(tim,1,n){
		int key=0;
		db mv=1e9;
		fo(i,1,n)
		if (!vis[i]&&f[i]<mv){
			mv=f[i];
			key=i;
		}
		vis[key]=1;
		num[tim]=key;
		fo(i,1,n)
		if (!vis[i]){
			now[i]=now[i]+pre[i]*p[i][key]*f[key];
			pre[i]=pre[i]*(1.0-p[i][key]);
			db tmp=(now[i]+1)/(1.0-pre[i]);
			if (tmp<f[i])f[i]=tmp;
		}
	}
	printf("%.9lf\n",f[1]);
	return 0;
}