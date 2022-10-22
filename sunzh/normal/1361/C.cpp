#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define mp make_pair
#define fi first
#define se second
#define PII pair<int,int>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
inline void print(int x){
	if(x<0) x=-x,putchar('-');
	if(x>=10) print(x/10);
	putchar(x%10+48);
}
int n;
int col[500010][2];
vector<PII>vec[1<<21];
bool vis[1<<21];
int ps;
int ans[1000010];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<vec[x].size();++i) if(!vis[vec[x][i].fi]) dfs(vec[x][i].fi);
}
bool check(int x){
	for(int i=0;i<(1<<x);++i) vec[i].clear(),vis[i]=0;
	for(int i=1;i<=n;++i){
		int u=col[i][0]&((1<<x)-1);
		int v=col[i][1]&((1<<x)-1);
		vec[u].push_back(mp(v,(i<<1)-1));
		vec[v].push_back(mp(u,(i<<1)-2));
	}
	int cnt=0;
	for(int i=0;i<(1<<x);++i){
		if(vec[i].size()&1) return 0;
		if(!vis[i]&&vec[i].size()){
			++cnt; if(cnt>1) return 0;
			dfs(i);
		}
	}
	return cnt==1;
}
void getas(int x,int p){
	while(vec[x].size()){
		PII v=vec[x].back();
		vec[x].pop_back();
//		printf("xfi:%d,vse:%d\n",v.fi,v.se);
		if(vis[v.se>>1]) continue ;
		vis[v.se>>1]=1;
		getas(v.fi,v.se);
//		break ;
	}
	if(p!=-1) ans[++ps]=p,ans[++ps]=(p^1);
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) col[i][0]=read(),col[i][1]=read();
	int l=0,r=20,res=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;res=mid;
		}
		else r=mid-1;
	}
	check(res);
	printf("%d\n",res);
	memset(vis,0,sizeof(vis));
	for(int i=0;i<(1<<res);++i){
		if(vec[i].size()){
			getas(i,-1);
			break ;
		}
	}
//	printf("%d\n",ps);
	for(int i=1;i<=ps;++i)print(ans[i]+1),putchar(' ');
	return 0; 
}