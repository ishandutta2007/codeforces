#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(i=(j);i<=(k);i++)
#define per(i,j,k) for(i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
#define MAXN 410000
int n,m,k;int s,t,i,j;
bool is[MAXN];
int head[MAXN],next[MAXN],p[MAXN];int tot=0;
int q[MAXN*50];int dis[MAXN];bool inq[MAXN];
void L(int a,int b){tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;}
bool spfa(int step){
	q[q[0]=1]=s;memset(dis,-1,sizeof dis);
	dis[s]=0;memset(inq,0,sizeof inq);inq[s]=1;
	rep(i,1,q[0]){
		int x=q[i];
		for(int u=head[x];u;u=next[u])
		if(dis[p[u]]==-1||dis[x]+1<dis[p[u]]){
			dis[p[u]]=dis[x]+1;
			if(is[p[u]])dis[p[u]]=0;
			if(p[u]==t)return 1;
			if(dis[p[u]]==step){dis[p[u]]=-1;continue;}
			if(!inq[p[u]]){
				q[++q[0]]=p[u];
				inq[p[u]]=1;
			}
		}
		inq[x]=0;
	}
	return dis[t]>=0;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,k){
		int v;scanf("%d",&v);
		is[v]=1;
	}
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		L(a,b);L(b,a);
	}
	scanf("%d%d",&s,&t);
	int l,r,res;l=1;r=n;res=-1;
	while(l<r){
		int mid=(l+r)>>1;
		if(spfa(mid)){
			res=mid;
			r=mid;
		}
		else l=mid+1;
	}
	if(spfa(l))res=l;
	printf("%d\n",res);
	return 0;
}