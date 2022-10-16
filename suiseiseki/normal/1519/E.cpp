#include <cstdio>
#include <algorithm>
template<typename Elem>
Elem gcd(Elem a,Elem b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
template<typename Elem>
Elem lcm(Elem a,Elem b){
	return a/gcd(a,b)*b;
}
typedef long long ll;
const int Maxn=200000;
struct Frac{
	ll a,b;
	Frac(ll _a=0,ll _b=1){
		a=_a,b=_b;
	}
	void to_small(){
		ll g=gcd(a,std::abs(b));
		a/=g,b/=g;
	}
	void read(){
		scanf("%lld%lld",&a,&b);
		to_small();
	}
	friend Frac operator *(Frac a,Frac b){
		Frac ans;
		ans.a=a.a*b.a;
		ans.b=a.b*b.b;
		ans.to_small();
		return ans;
	}
	friend Frac operator /(Frac a,Frac b){
		std::swap(b.a,b.b);
		return a*b;
	}
};
bool cmp_Frac_less(Frac a,Frac b){
	if(a.a==b.a){
		return a.b<b.b;
	}
	return a.a<b.a;
}
bool cmp_Frac_equal(Frac a,Frac b){
	return a.a==b.a&&a.b==b.b;
}
int n;
struct Node{
	Frac x,y;
	Frac seg_1,seg_2;
	int id_1,id_2;
}a[Maxn+5];
Frac d[Maxn<<1|5];
int d_len;
int head[Maxn<<1|5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],id[Maxn<<1|5],tot;
void add_edge(int from,int to,int d){
	arrive[++tot]=to;
	id[tot]=d;
	nxt[tot]=head[from];
	head[from]=tot;
}
bool vis_node[Maxn<<1|5],vis_edge[Maxn+5];
struct Answer{
	int x,y;
}ans[Maxn+5];
int ans_len;
void work_dfs(int u,int fa_id){
	vis_node[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(vis_node[v]){
			continue;
		}
		work_dfs(v,id[i]);
	}
	int lst=0;
	for(int i=head[u];i;i=nxt[i]){
		if(vis_edge[id[i]]||id[i]==fa_id){
			continue;
		}
		if(lst!=0){
			ans_len++;
			ans[ans_len].x=id[i];
			ans[ans_len].y=lst;
			vis_edge[id[i]]=vis_edge[lst]=1;
			lst=0;
		}
		else{
			lst=id[i];
		}
	}
	if(lst&&fa_id){
		ans_len++;
		ans[ans_len].x=lst;
		ans[ans_len].y=fa_id;
		vis_edge[lst]=vis_edge[fa_id]=1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i].x.read(),a[i].y.read();
		a[i].seg_1=a[i].y/Frac(a[i].x.a+a[i].x.b,a[i].x.b);
		a[i].seg_2=Frac(a[i].y.a+a[i].y.b,a[i].y.b)/a[i].x;
		d[++d_len]=a[i].seg_1,d[++d_len]=a[i].seg_2;
	}
	std::sort(d+1,d+1+d_len,cmp_Frac_less);
	d_len=std::unique(d+1,d+1+d_len,cmp_Frac_equal)-d-1;
	for(int i=1;i<=n;i++){
		a[i].id_1=std::lower_bound(d+1,d+1+d_len,a[i].seg_1,cmp_Frac_less)-d;
		a[i].id_2=std::lower_bound(d+1,d+1+d_len,a[i].seg_2,cmp_Frac_less)-d;
		add_edge(a[i].id_1,a[i].id_2,i),add_edge(a[i].id_2,a[i].id_1,i);
	}
	for(int i=1;i<=d_len;i++){
		if(!vis_node[i]){
			work_dfs(i,0);
		}
	}
	printf("%d\n",ans_len);
	for(int i=1;i<=ans_len;i++){
		printf("%d %d\n",ans[i].x,ans[i].y);
	}
	return 0;
}