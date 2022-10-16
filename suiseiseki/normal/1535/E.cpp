#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=300000;
int q;
int a[Maxn+5],c[Maxn+5];
int fa[20][Maxn+5];
int find_none_empty(int u){
	for(int i=19;i>=0;i--){
		if(fa[i][u]==0||a[fa[i][u]]==0){
			continue;
		}
		u=fa[i][u];
	}
	return u;
}
int main(){
	scanf("%d",&q);
	scanf("%d%d",&a[1],&c[1]);
	for(int u=2;u<=q+1;u++){
		int op;
		scanf("%d",&op);
		if(op==1){
			int p;
			scanf("%d%d%d",&p,&a[u],&c[u]);
			p++;
			fa[0][u]=p;
			for(int i=1;fa[i-1][fa[i-1][u]];i++){
				fa[i][u]=fa[i-1][fa[i-1][u]];
			}
		}
		else{
			int v,w;
			scanf("%d%d",&v,&w);
			v++;
			int ans_w=0;
			ll ans_v=0;
			while(w>0&&a[v]>0){
				int u=find_none_empty(v);
				int tmp_w=std::min(w,a[u]);
				w-=tmp_w;
				a[u]-=tmp_w;
				ans_w+=tmp_w;
				ans_v+=1ll*tmp_w*c[u];
			}
			printf("%d %lld\n",ans_w,ans_v);
			fflush(stdout);
		}
	}
	return 0;
}