#include <cstdio>
const int Maxn=200000;
int n;
int a[Maxn+5];
int b[Maxn+5];
int num[Maxn+5];
int head[Maxn+5],arrive[Maxn+5],nxt[Maxn+5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int qu[Maxn+5],qu_f,qu_t;
int deg[Maxn+5];
void solve(){
	scanf("%d",&n);
	tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0;
		num[i]=0;
		deg[i]=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	int mx_val=0;
	for(int i=1;i<=n;i++){
		if(num[i]>num[mx_val]){
			mx_val=i;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if(a[i]==mx_val||b[i]==mx_val){
			continue;
		}
		add_edge(a[i],b[i]);
		deg[b[i]]++;
	}
	qu_f=1,qu_t=0;
	for(int i=1;i<=n;i++){
		if(deg[i]==0){
			qu[++qu_t]=i;
		}
	}
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			deg[v]--;
			if(deg[v]==0){
				qu[++qu_t]=v;
			}
		}
	}
	if(qu_t<n){
		puts("WA");
	}
	else{
		puts("AC");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}