#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
const int Maxn=200000;
const int Mod=1000000007;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n;
bool np[Maxn+5];
int p[Maxn+5],p_len;
int phi[Maxn+5],mu[Maxn+5];
void init_phi(){
	np[0]=np[1]=1;
	phi[1]=1;
	mu[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			phi[i]=i-1;
			mu[i]=-1;
		}
		for(int j=1,x;(x=i*p[j])<=Maxn;j++){
			np[x]=1;
			if(i%p[j]==0){
				phi[x]=phi[i]*p[j];
				mu[x]=0;
				break;
			}
			phi[x]=phi[i]*(p[j]-1);
			mu[x]=-mu[i];
		}
	}
	for(int i=1;i<=Maxn;i++){
		if(mu[i]<0){
			mu[i]+=Mod;
		}
	}
}
int pos[Maxn+5];
int a[Maxn+5];
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int dfn[Maxn+5],out[Maxn+5],rnk[Maxn<<1|5],dfn_tot;
int lis[20][Maxn<<1|5];
int log_2[Maxn<<1|5];
int dep[Maxn+5];
void init_dfs(int u,int fa){
	dfn[u]=++dfn_tot;
	rnk[dfn_tot]=u;
	lis[0][dfn_tot]=dfn[u];
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		dep[v]=dep[u]+1;
		init_dfs(v,u);
		lis[0][++dfn_tot]=dfn[u];
	}
	out[u]=dfn_tot;
}
void init_tree(){
	init_dfs(1,0);
	for(int i=1;(1<<i)<=dfn_tot;i++){
		for(int j=1;j+(1<<i)-1<=dfn_tot;j++){
			lis[i][j]=min(lis[i-1][j],lis[i-1][j+(1<<(i-1))]);
		}
	}
	for(int i=2;i<=dfn_tot;i++){
		log_2[i]=log_2[i>>1]+1;
	}
}
int query_min(int l,int r){
	int k=log_2[r-l+1];
	return min(lis[k][l],lis[k][r-(1<<k)+1]);
}
int find_lca(int u,int v){
	int l=dfn[u],r=dfn[v];
	if(l>r){
		swap(l,r);
	}
	return rnk[query_min(l,r)];
}
int v_fa[Maxn+5],v_f[Maxn+5];
int v_sum[Maxn+5];
int top,st[Maxn+5];
int solve(vector<int> node){
	int ans=0;
	int sum_1=0;
	int all_sum=0;
	for(int i=0;i<(int)node.size();i++){
		v_sum[node[i]]=phi[a[node[i]]];
		v_f[node[i]]=1ll*v_sum[node[i]]*v_sum[node[i]]%Mod;
		all_sum=(all_sum+v_sum[node[i]])%Mod;
		sum_1++;
	}
	for(int i=0;i<(int)node.size();i++){
		ans=(ans+1ll*all_sum*v_sum[node[i]]%Mod*dep[node[i]])%Mod;
	}
	ans=(ans<<1)%Mod;
	sort(node.begin(),node.end(),[&](int u,int v){
		return dfn[u]<dfn[v];
	});
	for(int i=1;i<sum_1;i++){
		node.push_back(find_lca(node[i-1],node[i]));
	}
	sort(node.begin(),node.end(),[&](int u,int v){
		return dfn[u]<dfn[v];
	});
	node.erase(unique(node.begin(),node.end()),node.end());
	top=0;
	for(int i=0;i<(int)node.size();i++){
		while(top>0&&dfn[node[i]]>out[st[top]]){
			top--;
		}
		if(top){
			v_fa[node[i]]=st[top];
		}
		else{
			v_fa[node[i]]=0;
		}
		st[++top]=node[i];
	}
	for(int i=(int)node.size()-1;i>=0;i--){
		if(v_fa[node[i]]){
			v_f[v_fa[node[i]]]=(v_f[v_fa[node[i]]]+2ll*v_sum[v_fa[node[i]]]*v_sum[node[i]])%Mod;
			v_sum[v_fa[node[i]]]=(v_sum[v_fa[node[i]]]+v_sum[node[i]])%Mod;
		}
	}
	for(int i=0;i<(int)node.size();i++){
		ans=(ans-2ll*dep[node[i]]*v_f[node[i]]%Mod+Mod)%Mod;
		v_fa[node[i]]=v_f[node[i]]=v_sum[node[i]]=0;
	}
	return ans;
}
vector<int> node;
int f[Maxn+5],g[Maxn+5];
int main(){
	init_phi();
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_tree();
	for(int i=1;i<=n;i++){
		node.clear();
		for(int j=i;j<=n;j+=i){
			node.push_back(pos[j]);
		}
		f[i]=solve(node);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			g[i]=(g[i]+1ll*mu[j/i]*f[j])%Mod;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		g[i]=1ll*g[i]*i%Mod*find_inv(phi[i])%Mod;
		ans=(ans+g[i])%Mod;
	}
	ans=1ll*ans*find_inv(1ll*n*(n-1)%Mod)%Mod;
	printf("%d\n",ans);
	return 0;
}