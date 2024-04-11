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

int n;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int d[N];
int st;
bool vis[N];
int ans[N];

int getpoint(int x){
	int ret=x;
	vis[x]=1;
	for(int p=h[x];p;p=e[p].nxt)
	if (!vis[e[p].x])ret=getpoint(e[p].x);
	return ret;
}

void getans(int x){
	st=x;
	for(int p=h[x];p;p=e[p].nxt)d[e[p].x]--;
	bool pd=1;
	for(int p=h[x];p;p=e[p].nxt)pd&=(d[e[p].x]<2);
	int m=0;
	d[x]=0;
	fo(i,1,n)pd&=(d[i]<=2);
	if (!pd){
		printf("No\n");
		return;
	}
	vis[x]=1;
	printf("Yes\n");
	for(int p=h[x];p;p=e[p].nxt)ans[++m]=getpoint(e[p].x);
	printf("%d\n",m);
	fo(i,1,m)printf("%d %d\n",x,ans[i]);
}

int main(){
	n=get();
	fo(i,2,n){
		int x=get(),y=get();
		inse(x,y),inse(y,x);
		d[x]++,d[y]++;
	}
	bool line=1;
	fo(i,1,n)line&=(d[i]<=2);
	if (line){
		int x=0,y=0;
		fo(i,1,n)
		if (d[i]==1){x=i;break;}
		fo(i,x+1,n)
		if (d[i]==1){y=i;break;}
		printf("Yes\n1\n%d %d\n",x,y);
		return 0;
	}
	int x=0;
	fo(i,1,n)
	if (d[i]>2){x=i;break;}
	getans(x);
	return 0;
}