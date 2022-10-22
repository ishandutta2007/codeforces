#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9') { if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9') { x=(x<<3)+(x<<1)+(c^48); c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) x=~x+1,putchar('-');
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int head[100010],nxt[200010],to[200010];
int siz[100010],res[100010];
int ans1,ans2;
int minn=0x3f3f3f3f;
void dfs(int x,int fa){
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		int v=to[i];
		if(v==fa) continue ;
		dfs(v,x);
		siz[x]+=siz[v];
		res[x]=max(res[x],siz[v]);
	}
	res[x]=max(res[x],n-siz[x]);
	minn=min(minn,res[x]);
}
int tot;
void add(int x,int y){
	nxt[++tot]=head[x],head[x]=tot,to[tot]=y;
}
int T;
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) head[i]=siz[i]=res[i]=0;
		minn=0x3f3f3f3f;
		for(int i=1;i<n;++i){
			int u=read(),v=read();
			add(u,v);add(v,u);
		}
		dfs(1,0);
//		printf("minn:%d\n",minn);
ans1=ans2=0;
		for(int i=1;i<=n;++i) if(res[i]==minn){
//			printf("i:%d\n",i);
			if(ans1) ans2=i;
			else ans1=i;
		} 
		if(ans1&&ans2){
			int v=-1;
			for(int i=head[ans1];i;i=nxt[i]){
				v=to[i];
				if(v==ans2) continue ;
				break ;
			}
			printf("%d %d\n%d %d\n",ans1,v,ans2,v);
		}
		else{
			int v=-1;
			for(int i=head[1];i;i=nxt[i]){
				v=to[i];break ;
			}
			printf("%d %d\n%d %d\n",1,v,1,v);
		}
	}
}