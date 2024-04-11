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

const int N = 2e5+5;

struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int d[N];
struct EDGE{
	int x,y;
}ed[N];
int n,m,k;
int ans[N];
int cnt;
bool bz[N];
bool er[N];

int update(int &now){
	for(;now&&er[now/2];now=e[now].nxt);
	return now;
}

void del(int x){
	if (bz[x])return;
	bz[x]=1;
	cnt--;
	for(;update(h[x]);){
		int p=h[x];
		d[x]--,d[e[p].x]--;
		er[p/2]=1;
		if (d[e[p].x]<k)del(e[p].x);
	}
}

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int main(){
	n=get();m=get();k=get();
	tot=1;
	fo(i,1,m){
		ed[i].x=get();ed[i].y=get();
		inse(ed[i].x,ed[i].y);
		inse(ed[i].y,ed[i].x);
		d[ed[i].x]++,d[ed[i].y]++;
	}
	cnt=n;
	fo(i,1,n)if (d[i]<k)del(i);
	fd(i,m,1){
		int x=ed[i].x,y=ed[i].y;
		ans[i]=cnt;
		if (er[i]);
		else{
			er[i]=1;
			d[x]--,d[y]--;
			if (d[x]<k)del(x);
			if (d[y]<k)del(y);
		}
	}
	fo(i,1,m)printf("%d\n",ans[i]);
	return 0;
}