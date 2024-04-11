#include <cstdio>
const int Maxn=100000;
const int Maxk=20;
int n,k;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int a[Maxn+5];
int f[Maxn+5][Maxk+1][2];
void init_dfs_1(int u,int fa){
	f[u][0][0]=a[u];
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs_1(v,u);
		for(int j=0;j<k;j++){
			for(int l=0;l<2;l++){
				int tmp_j=j,tmp_l=l;
				tmp_j++;
				if(tmp_j>=k){
					tmp_j-=k;
					tmp_l^=1;
				}
				f[u][tmp_j][tmp_l]^=f[v][j][l];
			}
		}
	}
}
void init_dfs_2(int u,int fa){
	static int tmp[Maxk+1][2];
	if(fa){
		for(int j=0;j<k;j++){
			for(int l=0;l<2;l++){
				tmp[j][l]=f[fa][j][l];
			}
		}
		for(int j=0;j<k;j++){
			for(int l=0;l<2;l++){
				int tmp_j=j,tmp_l=l;
				tmp_j++;
				if(tmp_j>=k){
					tmp_j-=k;
					tmp_l^=1;
				}
				tmp[tmp_j][tmp_l]^=f[u][j][l];
			}
		}
		for(int j=0;j<k;j++){
			for(int l=0;l<2;l++){
				int tmp_j=j,tmp_l=l;
				tmp_j++;
				if(tmp_j>=k){
					tmp_j-=k;
					tmp_l^=1;
				}
				f[u][tmp_j][tmp_l]^=tmp[j][l];
			}
		}
	}
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs_2(v,u);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init_dfs_1(1,0);
	init_dfs_2(1,0);
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=0;j<k;j++){
			ans^=f[i][j][1];
		}
		if(ans==0){
			printf("0 ");
		}
		else{
			printf("1 ");
		}
	}
	puts("");
	return 0;
}