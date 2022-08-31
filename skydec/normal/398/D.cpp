#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int next[410000],ed[410000];
int head[50005],ans[50005];int n,m,q;int co[50005];int size[50005],du[50005];
int u[410000],v[410000];int tot;
inline void link(int x,int y){
	tot++;ed[tot]=y;next[tot]=head[x];head[x]=tot;
	ans[y]+=co[x];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	int nn;scanf("%d",&nn);
	rep(i,1,nn){
		int v;scanf("%d",&v);co[v]=1;
	}
	rep(i,1,m){scanf("%d%d",&u[i],&v[i]);du[u[i]]++;du[v[i]]++;}
	rep(i,1,m){if(du[u[i]]>du[v[i]])swap(u[i],v[i]);link(u[i],v[i]);}
	rep(jb,1,q){
		char w[3];scanf("%s",w+1);
		if(w[1]=='O'){
			int x;scanf("%d",&x);co[x]=1;
			for(int i=head[x];i;i=next[i])ans[ed[i]]++;
		}
		else if(w[1]=='F'){
			int x;scanf("%d",&x);co[x]=0;
			for(int i=head[x];i;i=next[i])ans[ed[i]]--;
		}
		else if(w[1]=='A'){
			int x,y;scanf("%d%d",&x,&y);
			du[x]++;du[y]++;
			if(du[x]>du[y])swap(x,y);link(x,y);
		}
		else if(w[1]=='D'){
			int x,y;scanf("%d%d",&x,&y);
			du[x]--;du[y]--;
			for(int pre=0,i=head[x];i;pre=i,i=next[i])if(ed[i]==y){
				if(pre)next[pre]=next[i];else head[x]=next[i];
				if(co[x])ans[y]--;
				break;
			}
			for(int pre=0,i=head[y];i;pre=i,i=next[i])if(ed[i]==x){
				if(pre)next[pre]=next[i];else head[y]=next[i];
				if(co[y])ans[x]--;
				break;
			}
		}
		else
		{
			int x;scanf("%d",&x);
			int res=ans[x];
			for(int i=head[x];i;i=next[i])if(co[ed[i]])res++;
			printf("%d\n",res);
		}
	}
	return 0;
}