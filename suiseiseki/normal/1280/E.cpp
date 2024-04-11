#include <vector>
#include <cstdio>
typedef long long ll;
const int Maxn=1000000;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int R;
std::vector<int> son[Maxn+5];
ll ans[Maxn+5];
ll f[Maxn+5];
int op[Maxn+5];
int st[Maxn+5],st_top;
int len;
void init_dfs(int u){
	if(op[u]==0){
		f[u]=1;
		return;
	}
	if(op[u]==1){
		f[u]=Inf_ll;
	}
	else{
		f[u]=0;
	}
	for(int v:son[u]){
		init_dfs(v);
		if(op[u]==1){
			f[u]=std::min(f[u],f[v]);
		}
		else{
			f[u]+=f[v];
		}
	}
}
void work_dfs(int u){
	if(op[u]==0){
		ans[u]=1ll*f[1]*R;
		return;
	}
	if(op[u]==1){
		for(int v:son[u]){
			if(f[v]==f[u]){
				work_dfs(v);
				break;
			}
		}
	}
	else{
		for(int v:son[u]){
			work_dfs(v);
		}
	}
}
void solve(){
	scanf("%d",&R);
	char c=getchar();
	st_top=len=0;
	while(c!='\n'){
		if(c=='('){
			if(st_top){
				son[st[st_top]].push_back(len+1);
			}
			st[++st_top]=++len;
			ans[len]=0;
			son[len].clear();
		}
		if(c==')'){
			st_top--;
		}
		if(c=='S'){
			op[st[st_top]]=1;
		}
		if(c=='P'){
			op[st[st_top]]=2;
		}
		if(c=='*'){
			op[++len]=0;
			ans[len]=0;
			son[st[st_top]].push_back(len);
			son[len].clear();
		}
		c=getchar();
	}
	init_dfs(1);
	work_dfs(1);
	printf("REVOLTING ");
	for(int i=1;i<=len;i++){
		if(op[i]==0){
			printf("%lld ",ans[i]);
		}
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