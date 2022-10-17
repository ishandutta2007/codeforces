#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200005
int head[N],arrive[N<<1],nxt[N<<1],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int dep[N];
int fir[N],sec[N];
int res;
pair<int,int> maxn;
pair<int,int> now;
void dfs(int root,int father,int depth){
	dep[root]=depth;
	int son=0;
	for(int i=head[root];i;i=nxt[i]){
		if(arrive[i]==father){
			continue;
		}
		son++;
		dfs(arrive[i],root,depth+1);
		if(dep[fir[arrive[i]]]>dep[fir[root]]){
			sec[root]=fir[root];
			fir[root]=fir[arrive[i]];
		}
		else if(dep[fir[arrive[i]]]>dep[sec[root]]){
			sec[root]=fir[arrive[i]];
		}
	}
	if(son==0){
		fir[root]=root;
	}
	if(son>1){
		now=make_pair(dep[root],dep[fir[root]]+dep[sec[root]]);
		if(now>maxn){
			maxn=now;
			res=root;
		}
	}
}
int main(){
	int n;
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	maxn=make_pair(0,0);
	dfs(1,0,1);
	int ans_1=fir[res],ans_2=sec[res];
	maxn=make_pair(0,0);
	memset(fir,0,sizeof fir);
	memset(sec,0,sizeof sec);
	dfs(res,0,1);
	int ans_3=fir[res],ans_4=sec[res];
	printf("%d %d\n%d %d\n",ans_1,ans_3,ans_2,ans_4);
	return 0;
}