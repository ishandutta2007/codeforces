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

const int N = 1e5+5;
const int INF = 1e9;

int n,m,k,s;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int dis[N][105];
int que[N];
int a[N];
int val[N];

int main(){
	n=get();m=get();k=get();s=get();
	fo(i,1,n)a[i]=get();
	fo(i,1,m){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
	}
	fo(u,1,k){
		int he=0,ta=0;
		fo(i,1,n)
		if (a[i]==u)que[++ta]=i;
		else dis[i][u]=INF;
		for(;he<ta;){
			int x=que[++he];
			for(int p=h[x];p;p=e[p].nxt)
			if (dis[e[p].x][u]==INF){
				dis[e[p].x][u]=dis[x][u]+1;
				que[++ta]=e[p].x;
			}
		}
	}
	fo(i,1,n){
		fo(x,1,k)val[x]=dis[i][x];
		sort(val+1,val+1+k);
		int ans=0;
		fo(x,1,s)ans=ans+val[x];
		printf("%d ",ans);
	}
	return 0;
}