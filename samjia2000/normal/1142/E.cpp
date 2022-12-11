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

const int N = 1e5+5;

int n,m;
struct edge{
	int x,nxt;
}e[N];
int h[N],tot;

void inse(int x,int y){e[++tot].x=y;e[tot].nxt=h[x];h[x]=tot;}

int dfn[N],f[N],k;
int sta[N],top;
bool pd[N];
int be[N],u;
int siz[N];
int deg[N];
vector<int>s[N];

void tarjan(int x){
	dfn[x]=f[x]=++k;
	pd[sta[++top]=x]=1;
	for(int p=h[x];p;p=e[p].nxt)
		if (!dfn[e[p].x]){
			int y=e[p].x;
			tarjan(y);
			f[x]=min(f[x],f[y]);
		}
		else if(pd[e[p].x])f[x]=min(f[x],dfn[e[p].x]);
	if (f[x]==dfn[x]){
		u++;
		for(;sta[top+1]!=x;){
			int y=sta[top--];
			pd[y]=0;
			siz[u]++;
			be[y]=u;
			s[u].push_back(y);
		}
	}
}

int que[N],he,ta;
set<int>key;

int main(){
	//freopen("data.in","r",stdin);
	n=get();m=get();
	fo(i,1,m){
		int x=get(),y=get();
		inse(x,y);
	}
	fo(i,1,n)
	if (!dfn[i])tarjan(i);
	fo(x,1,n)
		for(int p=h[x];p;p=e[p].nxt)
			if (be[e[p].x]!=be[x])deg[be[e[p].x]]++;
	fo(i,1,u)if (!deg[i])key.insert(i);
	int st=s[*key.begin()].back();
	for(;key.size()>1;){
		set<int>::iterator t=key.begin();
		if (be[st]==(*t))t++;
		int u=*t;
		int x=s[u].back();
		printf("? %d %d\n",st,x);fflush(stdout);
		int q=get();
		if (q){
			s[u].pop_back();
			if (s[u].size()==0)key.erase(u);
			for(int p=h[x];p;p=e[p].nxt)
				if (be[e[p].x]!=be[x]){
					deg[be[e[p].x]]--;
					if (!deg[be[e[p].x]])key.insert(be[e[p].x]);
				}
		}
		else{
			s[be[st]].pop_back();
			if (s[be[st]].size()==0)key.erase(be[st]);
			for(int p=h[st];p;p=e[p].nxt)
				if (be[e[p].x]!=be[st]){
					deg[be[e[p].x]]--;
					if (!deg[be[e[p].x]])key.insert(be[e[p].x]);
				}
			st=x;
		}
	}
	printf("! %d\n",st);fflush(stdout);
	return 0;
}