#include <cstdio>
#include <vector>
const int Maxn=200000;
std::vector<int> lis_x[Maxn+5],lis_y[Maxn+5];
int n,m,q;
struct DSU{
	int fa[Maxn+5];
	int num;
	void init(int n){
		num=n;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
	}
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return;
		}
		num--;
		fa[fa_y]=fa_x;
	}
}dsu_x,dsu_y;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		lis_x[x].push_back(y),lis_y[y].push_back(x);
	}
	dsu_x.init(m),dsu_y.init(n);
	int num_x=0,num_y=0;
	for(int i=1;i<=n;i++){
		if(lis_x[i].empty()){
			num_x++;
			continue;
		}
		for(int j=0;j<(int)lis_x[i].size()-1;j++){
			dsu_x.merge(lis_x[i][j],lis_x[i][j+1]);
		}
	}
	for(int i=1;i<=m;i++){
		if(lis_y[i].empty()){
			num_y++;
			continue;
		}
		for(int j=0;j<(int)lis_y[i].size()-1;j++){
			dsu_y.merge(lis_y[i][j],lis_y[i][j+1]);
		}
	}
	int ans=std::min(num_x+dsu_x.num,num_y+dsu_y.num)-1;
	printf("%d\n",ans);
	return 0;
}