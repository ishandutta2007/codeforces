#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,m;
vector<int>vec[1010];
int a[1010],b[1010];
int vis[1010];
bool usd[1010];
int chs[1010];
int arr[1010];
int cnt,oper[8010];
vector<int>A1,A2;
int a1,a2;
bool fl=0;
void dfs(int x,long long nv,int cc,int fa){
	arr[x]=cnt;vis[x]++;if(cc==0) usd[x]=1;
	// printf("x:%d,used:%d\n",x,usd[x]);
	// printf("cc:%d\n",cc);
	// printf("x:%d,nv:%lld,cnt:%d\n",x,nv,cnt);
	// for(int i:ar) printf("%d ",i);printf("\n");
	if(fl) return ;
	for(int v:vec[x]){
		if(a[v]>=nv) continue ;
		if(v==fa) continue ;
		if(fl) return ;
		// printf("x:%d,v:%d,vis:%d\n",x,v,vis[v]);
		if(vis[v]==0){
			if(fl) return ;
			oper[++cnt]=v;
			// printf("cnt:%d\n",cnt);
			dfs(v,nv+(chs[v]?0:b[v]),cc+(!chs[v]),x);
			oper[++cnt]=-1;
		}
		else if(vis[v]==1){
			if(usd[v]&&(!cc)) continue ;
			if(fl) return ;
			// printf("x:%d,v:%d\n",x,v);
			// for(int i:arr[v]) printf("%d ",i);printf("\n");
			// for(int i:ar) printf("%d ",i);printf("\n");
			a1=arr[v];a2=cnt;fl=1;
			// printf("%d %d\n",a1,a2);
			return ;
		}
	}
}
bool check(int v){
	for(int i=1;i<=n;++i) vis[i]=chs[i]=0;
	queue<int>Q;Q.push(1);chs[1]=1;
	long long nowv=v;
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		// printf("u:%d\n",u);
		for(int i=1;i<=n;++i) vis[i]=usd[i]=0;
		// for(int i=1;i<=n;++i) printf("%d ",chs[i]);printf("\n");
		A1.clear(),A2.clear();
		fl=0;cnt=0;
		vector<int>a;
		dfs(u,nowv,0,0);
		if(fl){
			// printf("a1:%d,a2:%d\n",a1,a2);
			for(int i=1;i<=cnt;++i){
				if(oper[i]==-1) a.pop_back();
				else a.push_back(oper[i]);
				if(a1==i) A1=a;if(a2==i) A2=a;
			}
			// for(int i:A1) printf("%d ",i);printf("\n");
			// for(int i:A2) printf("%d ",i);printf("\n");
			for(int i:A1) if(!chs[i]){
				Q.push(i),chs[i]=1,nowv+=b[i];
			}
			for(int i:A2) if(!chs[i]){
				Q.push(i),chs[i]=1,nowv+=b[i];
			}
		}
	}
	for(int i=1;i<=n;++i) if(!chs[i]) return 0;return 1;
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=2;i<=n;++i) a[i]=read(),vec[i].clear();
		for(int i=2;i<=n;++i) b[i]=read();
		vec[1].clear();
		for(int i=1;i<=m;++i){
			int u=read(),v=read();
			vec[u].pb(v);vec[v].pb(u);
		}
		int l=1,r=1e9,res=1e9+1;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)){
				res=mid;r=mid-1;
			}
			else l=mid+1;
		}
		printf("%d\n",res);
	}
}