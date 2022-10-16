#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=2000;
int x[Maxn+5],y[Maxn+5],a[Maxn+5];
int max_pos;
int n;
int id[Maxn+5],id_len;
bool vis[Maxn+5];
bool cmp(int p,int q){
	return 1ll*(x[p]-x[max_pos])*(y[q]-y[max_pos])-1ll*(x[q]-x[max_pos])*(y[p]-y[max_pos])<0;
}
int fa[Maxn+5];
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
	fa[fa_y]=fa_x;
}
std::vector<std::pair<int,int> > ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&y[i],&a[i]);
		fa[i]=i;
		if(a[i]!=i&&(max_pos==0||x[i]>x[max_pos])){
			max_pos=i;
		}
	}
	if(max_pos!=0){
		for(int i=1;i<=n;i++){
			if(a[i]!=i&&i!=max_pos){
				id[++id_len]=i;
			}
		}
		std::sort(id+1,id+1+id_len,cmp);
		for(int i=1;i<=n;i++){
			for(int j=i;!vis[j];j=a[j]){
				vis[j]=1;
				merge(j,a[j]);
			}
		}
		for(int i=1;i<id_len;i++){
			if(find(id[i])!=find(id[i+1])){
				ans.push_back(std::make_pair(id[i],id[i+1]));
				merge(id[i],id[i+1]);
				std::swap(a[id[i]],a[id[i+1]]);
			}
		}
	}
	while(a[max_pos]!=max_pos){
		ans.push_back(std::make_pair(a[max_pos],max_pos));
		std::swap(a[a[max_pos]],a[max_pos]);
	}
	printf("%u\n",ans.size());
	for(int i=0;i<(int)ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}