#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;
typedef unsigned long long ull;
typedef unsigned int ui;

ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}
ull getr(){
	ull ret=0;
	fo(i,1,5)ret=ret*1000000+getrand();
	return ret;
}

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

const int N = 3e5+5;
const int INF = 1e9;

int n,m;
int dis[N],que[N];
ull key[N],val[N];
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;
int lst[N];

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

void bfs(){
	int he=0,ta=1;
	fo(i,1,n)dis[i]=INF;
	dis[1]=0;
	que[1]=1;
	for(;he<ta;){
		int x=que[++he];
		for(int p=h[x];p;p=e[p].nxt)
		if (dis[e[p].x]==INF){
			dis[e[p].x]=dis[x]+1;
			que[++ta]=e[p].x;
			lst[e[p].x]=x;
		}
	}
}

int ans[N],len;
int cnt[N];

int main(){
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get();
		inse(x,y);
		inse(y,x);
	}
	bfs();
	len=dis[n];
	if (dis[n]!=INF){
		len=0;
		for(int x=n;x;x=lst[x])ans[++len]=x;
		reverse(ans+1,ans+1+len);
	}
	seed=20010419;
	fo(i,1,n){
		bool pd=(dis[i]==1);
		for(int p=h[i];p;p=e[p].nxt)pd&=(e[p].x!=n);
		if (pd)key[i]=getr();
	}
	if (dis[n]!=1){
		if (len>5)
		fo(i,1,n)
		if (dis[i]==2){
			len=5;
			ans[1]=ans[4]=1;
			ans[5]=n;
			ans[2]=lst[i];
			ans[3]=i;
			break;
		}
	}
	if (len>6){
		fo(i,1,n)
			for(int p=h[i];p;p=e[p].nxt)val[i]^=key[e[p].x];
		fo(i,1,n)
		if (dis[i]==1){
			for(int p=h[i];p;p=e[p].nxt)
			if (dis[e[p].x]==1&&(val[i]^key[e[p].x])!=(val[e[p].x]^key[i])){
				for(int v=h[i];v;v=e[v].nxt)
				if (e[v].x!=e[p].x&&key[e[v].x])cnt[e[v].x]++;
				for(int v=h[e[p].x];v;v=e[v].nxt)
				if (e[v].x!=i&&key[e[v].x])cnt[e[v].x]|=2;
				fo(x,1,n)
				if (cnt[x]!=0&&cnt[x]!=3){
					if (cnt[x]==1){
						int a=x,b=i,c=e[p].x;
						len=6;
						ans[1]=1;ans[2]=a;ans[3]=b;ans[4]=c;ans[5]=a;ans[6]=n;
					}
					else{
						int a=x,b=e[p].x,c=i;
						len=6;
						ans[1]=1;ans[2]=a;ans[3]=b;ans[4]=c;ans[5]=a;ans[6]=n;
					}
					break;
				}
				if (len==6)break;
			}
			if (len==6)break;
		}
	}
	if (len==INF)printf("-1\n");
	else{
		printf("%d\n",len-1);
		fo(i,1,len)printf("%d ",ans[i]);
	}
	return 0;
}