#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n;
int a[Maxn+5],b[Maxn+5];
int max_a[Maxn+5],max_b[Maxn+5];
int id_a[Maxn+5],id_b[Maxn+5];
bool vis[Maxn+5];
bool ans[Maxn+5];
int qu[Maxn+5],qu_f,qu_t;
void solve(){
	scanf("%d",&n);
	int all_max_a=0,all_max_b=0;
	for(int i=1;i<=n;i++){
		vis[i]=0;
		ans[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		all_max_a=std::max(all_max_a,a[i]);
		max_a[i]=a[i];
		id_a[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		all_max_b=std::max(all_max_b,b[i]);
		max_b[i]=b[i];
		id_b[i]=i;
	}
	std::sort(id_a+1,id_a+1+n,[&](int p,int q){return a[p]<a[q];});
	std::sort(id_b+1,id_b+1+n,[&](int p,int q){return b[p]<b[q];});
	qu_f=1,qu_t=0;
	qu[++qu_t]=id_a[n];
	vis[id_a[n]]=1;
	if(id_a[n]!=id_b[n]){
		qu[++qu_t]=id_b[n];
		vis[id_b[n]]=1;
	}
	int pos_1=n-1,pos_2=n-1;
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		ans[u]=1;
		while(pos_1>0&&a[id_a[pos_1]]>a[u]){
			if(!vis[id_a[pos_1]]){
				qu[++qu_t]=id_a[pos_1];
				vis[id_a[pos_1]]=1;
			}
			pos_1--;
		}
		while(pos_2>0&&b[id_b[pos_2]]>b[u]){
			if(!vis[id_b[pos_2]]){
				qu[++qu_t]=id_b[pos_2];
				vis[id_b[pos_2]]=1;
			}
			pos_2--;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",(int)ans[i]);
	}
	putchar('\n');
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}