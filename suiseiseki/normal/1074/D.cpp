#include <map>
#include <cstdio>
#include <algorithm>
const int Maxn=400000;
int n;
std::map<int,int> id_buc;
int id_tot;
int get_id(int x){
	if(id_buc.count(x)>0){
		return id_buc[x];
	}
	return id_buc[x]=++id_tot;
}
int fa[Maxn+5],fa_val[Maxn+5];
void init(){
	for(int i=1;i<=Maxn;i++){
		fa[i]=i,fa_val[i]=0;
	}
}
int find(int x){
	if(x==fa[x]){
		return x;
	}
	int t_fa=find(fa[x]);
	fa_val[x]^=fa_val[fa[x]];
	return fa[x]=t_fa;
}
void merge(int x,int y,int v){
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	fa[fa_y]=fa_x;
	fa_val[fa_y]=(fa_val[x]^fa_val[y]^v);
	find(y);
}
int main(){
	init();
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			l^=ans,r^=ans,x^=ans;
			if(l>r){
				std::swap(l,r);
			}
			r++;
			l=get_id(l),r=get_id(r);
			merge(l,r,x);
		}
		else{
			int l,r;
			scanf("%d%d",&l,&r);
			l^=ans,r^=ans;
			if(l>r){
				std::swap(l,r);
			}
			r++;
			l=get_id(l),r=get_id(r);
			if(find(l)!=find(r)){
				puts("-1");
				ans=1;
			}
			else{
				find(l),find(r);
				ans=fa_val[l]^fa_val[r];
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}