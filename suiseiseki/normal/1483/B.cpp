#include <cstdio>
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
const int Maxn=100000;
int n;
int a[Maxn+5];
struct DSU{
	int fa[Maxn+5];
	int find(int x){
		if(x==fa[x]){
			return x;
		}
		return fa[x]=find(fa[x]);
	}
	bool merge(int x,int y){
		int fa_x=find(x),fa_y=find(y);
		if(fa_x==fa_y){
			return 1;
		}
		fa[fa_y]=fa_x;
		return 0;
	}
	void init(){
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
	}
}del_dsu,nxt_dsu;
int find_nxt(int u){
	return del_dsu.find(u+1>n?1:u+1);
}
int lis[Maxn+5],lis_len;
void solve(){
	lis_len=0;
	scanf("%d",&n);
	del_dsu.init(),nxt_dsu.init();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;1;i=nxt_dsu.find(find_nxt(i))){
		int t=find_nxt(i);
		if(gcd(a[i],a[t])==1){
			del_dsu.merge(find_nxt(t),t);
			if(lis[lis_len]==t){
				break;
			}
			lis[++lis_len]=t;
		}
		else{
			if(nxt_dsu.merge(t,i)){
				break;
			}
		}
	}
	printf("%d ",lis_len);
	for(int i=1;i<=lis_len;i++){
		printf("%d ",lis[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}