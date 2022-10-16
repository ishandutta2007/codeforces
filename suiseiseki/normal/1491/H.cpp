#include <cstdio>
#include <algorithm>
const int Maxb=300;
const int Maxn=100000;
const int Maxv=(Maxn-1)/Maxb+1;
int n,q;
int num[Maxv+5],lazy[Maxv+5];
int fa[Maxn+5],out[Maxn+5];
int find_belong(int x){
	return (x-1)/Maxb+1;
}
int find_bel_l(int x){
	return (x-1)*Maxb+1;
}
int find_bel_r(int x){
	return std::min(n,x*Maxb);
}
void build(int x){
	for(int i=find_bel_l(x);i<=find_bel_r(x);i++){
		fa[i]=std::max(1,fa[i]-lazy[x]);
	}
	lazy[x]=0;
	for(int i=find_bel_l(x);i<=find_bel_r(x);i++){
		if(fa[i]<find_bel_l(x)){
			out[i]=fa[i];
		}
		else{
			out[i]=out[fa[i]];
		}
	}
}
int find_out(int x){
	return std::max(1,out[x]-lazy[find_belong(x)]);
}
int find_fa(int x){
	return std::max(1,fa[x]-lazy[find_belong(x)]);
}
void update(int l,int r,int x){
	int bel_l=find_belong(l),bel_r=find_belong(r);
	if(bel_l==bel_r){
		for(int i=l;i<=r;i++){
			fa[i]=std::max(1,fa[i]-x);
		}
		build(bel_l);
		return;
	}
	for(int i=l;i<=find_bel_r(bel_l);i++){
		fa[i]=std::max(1,fa[i]-x);
	}
	build(bel_l);
	for(int i=find_bel_l(bel_r);i<=r;i++){
		fa[i]=std::max(1,fa[i]-x);
	}
	build(bel_r);
	for(int i=bel_l+1;i<bel_r;i++){
		num[i]++;
		lazy[i]=std::min(n,lazy[i]+x);
		if(num[i]<=Maxb){
			build(i);
		}
	}
}
int query(int u,int v){
	while(u!=v){
		if(find_belong(u)<find_belong(v)){
			std::swap(u,v);
		}
		if(find_belong(u)>find_belong(v)){
			u=find_out(u);
		}
		else{
			if(find_out(u)!=find_out(v)){
				u=find_out(u);
				v=find_out(v);
			}
			else{
				while(u!=v){
					if(u<v){
						std::swap(u,v);
					}
					u=find_fa(u);
				}
			}
		}
	}
	return u;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
	}
	for(int i=1;i<=find_belong(n);i++){
		build(i);
	}
	for(int i=1;i<=q;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			update(l,r,x);
		}
		else{
			int u,v;
			scanf("%d%d",&u,&v);
			printf("%d\n",query(u,v));
		}
	}
	return 0;
}