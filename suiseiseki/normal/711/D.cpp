#include <cstdio>
#define Maxn 200000
#define Mod 1000000007
int a[Maxn+5];
int len;
bool vis[Maxn+5];
int t[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		a=1ll*a*a%Mod;
		b>>=1;
	}
	return ans;
}
int n;
void dfs(int u){
	vis[u]=1;
	len++;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(vis[v]){
			continue;
		}
		dfs(v);
	}
}
int find(int u){
	int now=0;
	int i;
	for(i=u;!t[i];i=a[i]){
		t[i]=++now;
	}
	return now-t[i]+1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add_edge(i,a[i]);
		add_edge(a[i],i);
	}
	int ans=1;
	int now;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			len=0;
			dfs(i);
			now=find(i);
			ans=1ll*ans*ksm(2,len-now)%Mod*((ksm(2,now)-2+Mod)%Mod)%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}