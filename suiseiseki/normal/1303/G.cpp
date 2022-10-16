#include <cstdio>
#include <cstring>
#include <algorithm>
namespace IO{
	const int SIZE=(1<<21)+1;
	char ibuf[SIZE],*iS,*iT;
	#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SIZE,stdin),(iS==iT?EOF:*(iS++))):*(iS++))
	void read(int &a){
		a=0;
		char c=gc();
		while(c<'0'||c>'9'){
			c=gc();
		}
		while(c>='0'&&c<='9'){
			a=a*10+c-'0';
			c=gc();
		}
	}
}
using IO::read;
typedef long long ll;
const int Maxn=150000;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
int a[Maxn+5];
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool vis[Maxn+5];
int sz[Maxn+5];
void sz_dfs(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa||vis[v]){
			continue;
		}
		sz_dfs(v,u);
		sz[u]+=sz[v];
	}
}
void weight_dfs(int u,int fa,int &root,int &weight,int &n){
	int max_sz=n-sz[u];
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa||vis[v]){
			continue;
		}
		max_sz=std::max(max_sz,sz[v]);
		weight_dfs(v,u,root,weight,n);
	}
	if(max_sz<weight){
		weight=max_sz;
		root=u;
	}
}
int find_weight(int u){
	sz_dfs(u,0);
	int n=sz[u];
	int root=u,weight=n;
	weight_dfs(u,0,root,weight,n);
	return root;
}
int dep_dfs(int u,int fa){
	int ans=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa||vis[v]){
			continue;
		}
		ans=std::max(ans,dep_dfs(v,u));
	}
	return ans+1;
}
namespace Segment_Tree{
	int n;
	struct Segment_Node{
		ll k,b;
	}seg[Maxn<<2|5];
	void build(int root=1,int left=1,int right=n){
		seg[root].k=seg[root].b=-1;
		if(left==right){
			return;
		}
		int mid=(left+right)>>1;
		build(root<<1,left,mid);
		build(root<<1|1,mid+1,right);
	}
	void init(int _n){
		n=_n;
		build();
	}
	void update(ll k,ll b,int root=1,int left=1,int right=n){
		if(seg[root].k==-1&&seg[root].b==-1){
			seg[root].k=k,seg[root].b=b;
			return;
		}
		if(left*k+b<=left*seg[root].k+seg[root].b&&right*k+b<=right*seg[root].k+seg[root].b){
			return;
		}
		int mid=(left+right)>>1;
		if(mid*k+b>mid*seg[root].k+seg[root].b){
			std::swap(seg[root].k,k);
			std::swap(seg[root].b,b);
		}
		if(left*k+b>left*seg[root].k+b){
			update(k,b,root<<1,left,mid);
		}
		if(right*k+b>right*seg[root].k+b){
			update(k,b,root<<1|1,mid+1,right);
		}
	}
	ll query(int x,int root=1,int left=1,int right=n){
		if(left==right){
			return (seg[root].k==-1?-1:seg[root].k*x+seg[root].b);
		}
		int mid=(left+right)>>1;
		if(x<=mid){
			return std::max(query(x,root<<1,left,mid),(seg[root].k==-1?-1:seg[root].k*x+seg[root].b));
		}
		else{
			return std::max(query(x,root<<1|1,mid+1,right),(seg[root].k==-1?-1:seg[root].k*x+seg[root].b));
		}
	}
}
ll val_1[Maxn+5][2],val_2[Maxn+5];
int val_1_len;
int work_dfs(int u,int fa,ll s_1,int d_2,ll s_2,ll v_1,ll v_2){
	s_1+=a[u];
	s_2+=a[u];
	v_1+=s_1;
	v_2+=1ll*d_2*a[u];
	int mx_dep=d_2;
	bool flag=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa||vis[v]){
			continue;
		}
		flag=0;
		mx_dep=std::max(mx_dep,work_dfs(v,u,s_1,d_2+1,s_2,v_1,v_2));
	}
	if(flag){
		val_1_len++;
		val_1[val_1_len][0]=v_2;
		val_1[val_1_len][1]=s_2;
		val_2[d_2+1]=std::max(val_2[d_2+1],v_1);
	}
	return mx_dep;
}
ll ans;
int son_lis[Maxn+5],son_len;
void calc(int u){
	u=find_weight(u);
	int mx_dep=dep_dfs(u,0);
	Segment_Tree::init(mx_dep);
	son_len=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(vis[v]){
			continue;
		}
		son_lis[++son_len]=v;
		val_1_len=0;
		int cur_mx_dep=work_dfs(v,u,a[u],1,0,a[u],0);
		cur_mx_dep++;
		for(int j=2;j<=cur_mx_dep;j++){
			if(val_2[j]<0){
				continue;
			}
			ans=std::max(ans,val_2[j]);
			ll cur_val=Segment_Tree::query(j);
			ans=std::max(ans,val_2[j]+cur_val);
			val_2[j]=-Inf_ll;
		}
		for(int j=1;j<=val_1_len;j++){
			Segment_Tree::update(val_1[j][1],val_1[j][0]);
		}
	}
	Segment_Tree::init(mx_dep);
	for(int i=son_len;i>0;i--){
		int v=son_lis[i];
		val_1_len=0;
		int cur_mx_dep=work_dfs(v,u,a[u],1,0,a[u],0);
		cur_mx_dep++;
		for(int j=2;j<=cur_mx_dep;j++){
			if(val_2[j]<0){
				continue;
			}
			ans=std::max(ans,val_2[j]);
			ll cur_val=Segment_Tree::query(j);
			ans=std::max(ans,val_2[j]+cur_val);
			val_2[j]=-Inf_ll;
		}
		for(int j=1;j<=val_1_len;j++){
			Segment_Tree::update(val_1[j][1],val_1[j][0]);
		}
	}
	ans=std::max(ans,1ll*a[u]);
	ll cur_val=Segment_Tree::query(1);
	ans=std::max(ans,cur_val+a[u]);
	vis[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(vis[v]){
			continue;
		}
		calc(v);
	}
}
int main(){
	read(n);
	for(int i=1;i<n;i++){
		int u,v;
		read(u),read(v);
		add_edge(u,v),add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		read(a[i]);
	}
	memset(val_2,-0x3f,sizeof val_2);
	calc(1);
	printf("%lld\n",ans);
	return 0;
}