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
const int MAXN=5050;
#define find findzyb
bool flag=0;
struct flow{
	int x,y,d;
	inline flow(int a=0,int b=0,int c=0){
		x=a;y=b;d=c;
	}
};
int now[MAXN],goal[MAXN];
vector<int>p[MAXN];
int n,v,m;
vector<flow>ans;
int fa[MAXN];
int get(int x){
	if(x==fa[x])return x;
	fa[x]=get(fa[x]);
	return fa[x];
}
int q[MAXN];bool vis[MAXN];bool zuo[MAXN];

bool find[MAXN];
int step;
inline void Flow(int x,int y,int z){
	ans.pb(flow(x,y,z));
	now[x]-=z;now[y]+=z;
}
void come(int x,int y){
	find[x]=1;
	rep(i,0,p[x].size()-1)if(p[x][i]!=y&&!zuo[p[x][i]]&&!find[p[x][i]]){
		come(p[x][i],x);
		step=1;
		if(v-now[x]<=now[p[x][i]]){
			Flow(p[x][i],x,v-now[x]);
			return;
		}
		else Flow(p[x][i],x,now[p[x][i]]);
	}
}
void out(int x,int y){
	find[x]=1;
	rep(i,0,p[x].size()-1)if(p[x][i]!=y&&!zuo[p[x][i]]&&!find[p[x][i]]){
		out(p[x][i],x);
		step=2;
		if(now[x]<=v-now[p[x][i]]){
			Flow(x,p[x][i],now[x]);
			return;
		}
		else Flow(x,p[x][i],v-now[p[x][i]]);
	}
}
inline void work(int st){
	q[q[0]=1]=st;vis[st]=1;
	rep(i,1,q[0]){
		int x=q[i];
		rep(j,0,p[x].size()-1){
			int y=p[x][j];
			if(vis[y])continue;
			vis[y]=1;
			q[++q[0]]=y;
		}
	}
	LL tmp=0;
	rep(i,1,q[0])tmp+=1ll*(goal[q[i]]-now[q[i]]);
	if(tmp!=0){
		printf("NO");
		exit(0);
	}
	per(i,q[0],1){
		memset(find,0,sizeof find);
		int x=q[i];find[x]=1;
		if(goal[x]>now[x]){
			rep(j,0,p[x].size()-1)if(!zuo[p[x][j]]){
				come(p[x][j],x);
				step=3;
				if(now[x]+now[p[x][j]]>=goal[x]){
					Flow(p[x][j],x,goal[x]-now[x]);
					goto pyc;
				}
				else Flow(p[x][j],x,now[p[x][j]]);
			}
		}
		else{
			rep(j,0,p[x].size()-1)if(!zuo[p[x][j]]){
				out(p[x][j],x);
				step=4;
				if(v-now[p[x][j]]>=now[x]-goal[x]){
					Flow(x,p[x][j],now[x]-goal[x]);
					goto pyc;
				}
				else {
					step=5;
					Flow(x,p[x][j],v-now[p[x][j]]);
				}
			}
		}
		pyc:;
		zuo[x]=1;
	}
}
int main(){
	scanf("%d%d%d",&n,&v,&m);
	rep(i,1,n){
		fa[i]=i;
		scanf("%d",&now[i]);
	}
	rep(i,1,n)scanf("%d",&goal[i]);
	rep(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		fa[get(x)]=get(y);
		p[x].pb(y);
		p[y].pb(x);
	}
	rep(i,1,n)if(get(i)==i){
		work(i);
	}
	printf("%d\n",ans.size());
	rep(i,0,ans.size()-1)printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].d);
	return 0;
}