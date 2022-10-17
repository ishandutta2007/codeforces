#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define Maxn 300000
#define Mod 998244353
vector<int> edge[Maxn+5];
int add(int a,int b){
	a+=b;
	if(a>=Mod){
		a-=Mod;
	}
	if(a<0){
		a+=Mod;
	}
	return a;
}
int mul(int a,int b){
	return (int)((long long)a*b%Mod);
}
int fa[Maxn+5][30];
int dep[Maxn+5];
int a[Maxn+5];
int n,k;
int l[Maxn+5];
void dfs_1(int root){
	dep[root]=dep[fa[root][0]]+1;
	for(int i=1;fa[fa[root][i-1]][i-1]!=0;i++){
		fa[root][i]=fa[fa[root][i-1]][i-1];
	}
	for(int i=0;i<(int)edge[root].size();i++){
		if(edge[root][i]==fa[root][0]){
			continue;
		}
		fa[edge[root][i]][0]=root;
		dfs_1(edge[root][i]);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]){
		swap(x,y);
	}
	for(int i=29;i>=0;i--){
		if(dep[fa[x][i]]>=dep[y]){
			x=fa[x][i];
		}
	}
	if(x==y){
		return x;
	}
	for(int i=29;i>=0;i--){
		if(fa[x][i]==fa[y][i]){
			continue;
		}
		x=fa[x][i];
		y=fa[y][i];
	}
	return fa[x][0];
}
int f[Maxn+5][2];
int dfs(int root){
	vector<int> now_c,now_t,val;
	int c;
	for(int i=0;i<(int)edge[root].size();i++){
		if(edge[root][i]==fa[root][0]){
			continue;
		}
		c=dfs(edge[root][i]);
		if(c!=0){
			now_c.push_back(c);
			now_t.push_back(edge[root][i]);
			if(c>0){
				val.push_back(c);
			}
		}
	}
	sort(val.begin(),val.end());
	val.resize(unique(val.begin(),val.end())-val.begin());
	if((int)val.size()>1){
		puts("0");
		exit(0);
	}
	if(a[root]!=0&&!val.empty()&&a[root]!=val[0]){
		puts("0");
		exit(0);
	}
	if(a[root]==0&&now_c.empty()){
		return 0;
	}
	if(a[root]==0&&val.empty()){
		vector<int> pre,bac;
		pre.push_back(1);
		bac.push_back(1);
		for(int i=0;i<(int)now_c.size();i++){
			pre.push_back(mul(pre.back(),add(f[now_t[i]][0],f[now_t[i]][1])));
		}
		for(int i=(int)now_c.size()-1;i>=0;i--){
			bac.push_back(mul(bac.back(),add(f[now_t[i]][0],f[now_t[i]][1])));
		}
		reverse(bac.begin(),bac.end());
		f[root][1]=0;
		for(int i=0;i<(int)now_c.size();i++){
			f[root][1]=add(f[root][1],mul(mul(pre[i],bac[i+1]),f[now_t[i]][1]));
		}
		f[root][0]=add(f[root][0],pre[(int)now_c.size()]);
		return -1;
	}
	f[root][1]=1;
	for(int i=0;i<(int)now_c.size();i++){
		if(now_c[i]==-1){
			f[root][1]=mul(f[root][1],add(f[now_t[i]][0],f[now_t[i]][1]));
		}
		else{
			f[root][1]=mul(f[root][1],f[now_t[i]][1]);
		}
	}
	if(a[root]==0){
		return val[0];
	}
	if(l[a[root]]==root){
		return -1;
	}
	return a[root];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int u,v;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs_1(1);
	memset(l,-1,sizeof l);
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			continue;
		}
		if(l[a[i]]==-1){
			l[a[i]]=i;
		}
		else{
			l[a[i]]=lca(l[a[i]],i);
		}
	}
	for(int i=1;i<=k;i++){
		if(a[l[i]]==0||a[l[i]]==i){
			a[l[i]]=i;
			continue;
		}
		puts("0");
		return 0;
	}
	dfs(1);
	printf("%d\n",f[1][1]);
	return 0;
}