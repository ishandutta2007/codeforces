#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
const int Maxk=18;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
struct Node{
	int num,w,v,id;
	friend bool operator <(Node a,Node b){
		if(a.v==b.v){
			return a.w<b.w;
		}
		return a.v>b.v;
	}
}a[Maxn+5];
int n,q;
int pos[Maxn+5];
ll num[Maxn+5];
struct Segment_Node{
	ll v[Maxk+1],w[Maxk+1],c[Maxk+5];
}seg[Maxn<<2|5];
void get_val(Segment_Node &val,int id){
	for(int i=1;i<=Maxk;i++){
		val.v[i]=val.w[i]=0;
		val.c[i]=Inf;
		if(a[id].w<(1<<(i-1))){
			val.v[i]=1ll*num[id]*a[id].v;
			val.w[i]=1ll*num[id]*a[id].w;
		}
		else if(a[id].w<(1<<i)&&num[id]>0){
			val.c[i]=a[id].w;
		}
	}
}
void push_up(int root){
	for(int i=1;i<=Maxk;i++){
		seg[root].v[i]=seg[root<<1].v[i]+seg[root<<1|1].v[i];
		seg[root].w[i]=seg[root<<1].w[i]+seg[root<<1|1].w[i];
		seg[root].c[i]=std::min(seg[root<<1].c[i],seg[root<<1].w[i]+seg[root<<1|1].c[i]);
	}
}
void build(int root=1,int left=1,int right=n){
	if(left==right){
		get_val(seg[root],left);
		return;
	}
	int mid=(left+right)>>1;
	build(root<<1,left,mid);
	build(root<<1|1,mid+1,right);
	push_up(root);
}
void update(int x,int a,int root=1,int left=1,int right=n){
	if(left==right){
		num[left]+=a;
		get_val(seg[root],left);
		return;
	}
	int mid=(left+right)>>1;
	if(x<=mid){
		update(x,a,root<<1,left,mid);
	}
	else{
		update(x,a,root<<1|1,mid+1,right);
	}
	push_up(root);
}
void get_cur_dep(ll v,int &dep){
	while(dep>1&&(1<<(dep-2))>v){
		dep--;
	}
}
ll query(ll &v,int &dep,int root=1,int left=1,int right=n){
	if(left==right){
		ll tmp=std::min(num[left],v/a[left].w);
		v-=tmp*a[left].w;
		get_cur_dep(v,dep);
		return tmp*a[left].v;
	}
	if(seg[root].w[dep]<=v){
		ll ans=seg[root].v[dep];
		v-=seg[root].w[dep];
		get_cur_dep(v,dep);
		return ans;
	}
	if(seg[root].w[dep-1]<=v&&v<seg[root].c[dep-1]){
		ll ans=seg[root].v[dep-1];
		v-=seg[root].w[dep-1];
		get_cur_dep(v,dep);
		return ans;
	}
	int mid=(left+right)>>1;
	return query(v,dep,root<<1,left,mid)+query(v,dep,root<<1|1,mid+1,right);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].num,&a[i].w,&a[i].v);
		a[i].id=i;
	}
	std::sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pos[a[i].id]=i;
		num[i]=a[i].num;
	}
	build();
	for(int t=1;t<=q;t++){
		int op;
		scanf("%d",&op);
		if(op==1||op==2){
			op=(op==1?1:-1);
			int x,v;
			scanf("%d%d",&v,&x);
			update(pos[x],op*v);
		}
		else{
			ll w;
			scanf("%lld",&w);
			int dep=18;
			get_cur_dep(w,dep);
			printf("%lld\n",query(w,dep));
		}
	}
	return 0;
}