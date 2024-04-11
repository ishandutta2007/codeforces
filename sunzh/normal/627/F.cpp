#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
void Fail(){
	printf("-1\n");exit(0);
}
int n;
int a[200010],b[200010];
int dep[200010];
vector<int>vec[200010];
int s,t;
vector<int>to;
bool dfs(int x,int fa){
	to.pb(x);
	if(x==t){
		return 1;
	}
	for(int v:vec[x]){
		if(v!=fa&&dfs(v,x)) return 1;
	}
	to.pop_back();return 0;
}
bool vis[200010];
int deg[200010];
int up=-1;
vector<int>A,B;
vector<int>cir;
void getcircle(int x,int fa){
	dep[x]=dep[fa]+1;
	if(a[x]!=b[x]){
		if(up==-1||dep[up]>=dep[x]) up=fa;
		cir.pb(x);
		vis[x]=1;
	}
	for(int v:vec[x]){
		if(v!=fa) getcircle(v,x);
	}
}
void getseq(int x,int fa){
	if(x!=up){
		A.pb(a[x]);B.pb(b[x]);
	}
	for(int v:vec[x]){
		if(vis[v]&&v!=fa) getseq(v,x);
	}
}
int calc(vector<int>A,vector<int>B){
	int siz=A.size();
	int pos=0;
	for(int i=0;i<siz;++i){
		if(B[i]==A[0]){
			pos=i;break ;
		}
	}
	if(pos==0) return 0;
	for(int i=0;i<siz;++i){
		if(A[i]!=B[(i+pos)%siz]) return 0;
	}
	return pos;
}
int getdis(int x,int fa,int dis,int y){
	if(x==y) return dis;
	for(int v:vec[x]){
		if(v==fa) continue ;
		int d=getdis(v,x,dis+1,y);
		if(d) return d;
	}
	return 0;
}
int dis(int x,int y){
	return getdis(x,0,0,y);
}
int get(int u,int v){
	int c=calc(A,B);
	return dis(s,u)+(c-1)*(A.size()+1)+1+dis(v,t);
}
signed main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	for(int i=1;i<=n;++i) if(a[i]==0) s=i;
	for(int i=1;i<=n;++i) if(b[i]==0) t=i;
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v),vec[v].pb(u);
	}
	dfs(s,0);
	for(int i=0;i<to.size()-1;++i) swap(a[to[i]],a[to[i+1]]);
//	for(int i=1;i<=n;++i) printf("i:%d,%d %d\n",i,a[i],b[i]);
	bool ok=1;
	for(int i=1;i<=n;++i) ok=ok&(a[i]==b[i]);
	if(ok){
		printf("0 %d\n",to.size()-1);
		return 0;
	}
	getcircle(t,0);
	vis[up]=1;cir.pb(up);
//	printf("up:%d\n",up);
	vector<int>u;
	for(int x:cir){
		for(int v:vec[x]){
			if(vis[v]) ++deg[x];
		}
		if(deg[x]==1){
//			printf("d1:x:%d\n",x);
			u.pb(x);
		}
		else if(deg[x]!=2){
//			printf("x:%d\n",x);
			Fail();
		}
	}
	if(u.size()!=2){
//		printf("1\n");
		Fail();
	}
	if(u[0]>u[1]) swap(u[0],u[1]);
	getseq(u[0],0);
	if(!calc(A,B)){
//		printf("?\n");
//		for(int i:A) printf("%d ",i);printf("\n");
//		for(int i:B) printf("%d ",i);printf("\n");
		Fail();
	}
	printf("%d %d ",u[0],u[1]);
	int ans=get(u[0],u[1]);
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
	printf("%lld\n",min(ans,get(u[1],u[0])));
}