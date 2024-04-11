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

const int N = 2e5+5;

int n,m;
bool any[N];
char s[N];
int be[N],u;
int dfn[N],f[N],k;
struct edge{
	int x,nxt;
}e[N*2];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

bool pd[N];
int sta[N],top;
int cnt[N];
bool ans;

void tarjan(int x){
	dfn[x]=f[x]=++k;
	pd[sta[++top]=x]=1;
	for(int p=h[x];p;p=e[p].nxt){
		int y=e[p].x;
		if (!dfn[y]){
			tarjan(y);
			f[x]=min(f[x],f[y]);
		}
		else if (pd[e[p].x])f[x]=min(f[x],dfn[e[p].x]);
	}
	if (f[x]==dfn[x]){
		u++;
		cnt[u]=0;
		int pt=top;
		int mx=-1e9,mi=1e9;
		while(sta[top+1]!=x){
			int y=sta[top--];
			be[y]=u;
			if (any[y/2])cnt[u]++,mx=max(mx,y/2);
			else mi=min(mi,y/2);
			pd[y]=0;
		}
		if (mx>mi||cnt[u]>1){ans=0;return;}
		bool son=0;
		fo(i,top+1,pt){
			int y=sta[i];
			for(int p=h[y];p;p=e[p].nxt)
			if (be[e[p].x]&&be[e[p].x]!=be[y])son|=cnt[be[e[p].x]];
		}
		if (cnt[u]&&son){ans=0;return;}
		cnt[u]|=son;
	}
}

bool solve(){
	n=get();m=get();
	scanf("%s",s+1);
	fo(i,1,n)any[i]=(s[i]=='A');
	fo(i,1,n*2+1)h[i]=dfn[i]=f[i]=be[i]=cnt[i]=sta[i]=0;
	tot=u=k=0;
	fo(i,1,m){
		int x=get(),y=get();
		if (x<0)x=-x*2+1;else x<<=1;
		if (y<0)y=-y*2+1;else y<<=1;
		inse(x^1,y);
		inse(y^1,x);
	}
	ans=1;
	fo(i,2,n*2+1)
	if (!dfn[i])tarjan(i);
	fo(i,1,n)ans&=(be[i*2+1]!=be[i*2]);
	return ans;
}

int main(){
	for(int _=get();_;_--)printf("%s\n",solve()?"TRUE":"FALSE");
	return 0;
}