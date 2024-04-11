#include <cstdio>
#include <algorithm>
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
const int Mod=998244353;
bool np[Maxn+5];
int p[Maxn+5],p_len;
int min_p[Maxn+5];
int inv[Maxn+5];
void init(){
	np[0]=np[1]=1;
	for(int i=2;i<=Maxn;i++){
		if(!np[i]){
			p[++p_len]=i;
			min_p[i]=p_len;
		}
		for(int j=1,x;(x=i*p[j])<=Maxn;j++){
			np[x]=1;
			min_p[x]=j;
			if(i%p[j]==0){
				break;
			}
		}
	}
	inv[1]=1;
	for(int i=2;i<=Maxn;i++){
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	}
}
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
std::pair<int,int> val[Maxn<<1|5];
void add_edge(int from,int to,std::pair<int,int> v){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=v;
	head[from]=tot;
}
int mx_val[Maxn+5];
int num[Maxn+5];
void init_dfs(int u,int fa){
	auto upd_val=[&](int v,int a){
		while(v>1){
			num[min_p[v]]+=a;
			mx_val[min_p[v]]=std::max(mx_val[min_p[v]],-num[min_p[v]]);
			v/=p[min_p[v]];
		}
	};
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		upd_val(val[i].second,1);
		upd_val(val[i].first,-1);
		init_dfs(v,u);
		upd_val(val[i].first,1);
		upd_val(val[i].second,-1);
	}
}
int ans;
void work_dfs(int u,int fa,int va){
	ans=(ans+va)%Mod;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		int nxt=1ll*va*inv[val[i].first]%Mod*val[i].second%Mod;
		work_dfs(v,u,nxt);
	}
}
void solve(){
	scanf("%d",&n);
	tot=0;
	for(int i=1;i<=p_len;i++){
		mx_val[i]=0;
	}
	for(int i=1;i<=n;i++){
		head[i]=0;
	}
	for(int i=1;i<n;i++){
		int u,v,x,y;
		scanf("%d%d%d%d",&u,&v,&x,&y);
		add_edge(u,v,std::make_pair(x,y));
		add_edge(v,u,std::make_pair(y,x));
	}
	init_dfs(1,0);
	int val=1;
	ans=0;
	for(int i=1;i<=p_len;i++){
		if(mx_val[i]==0){
			continue;
		}
		val=1ll*val*quick_power(p[i],mx_val[i],Mod)%Mod;
	}
	work_dfs(1,0,val);
	printf("%d\n",ans);
}
int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}