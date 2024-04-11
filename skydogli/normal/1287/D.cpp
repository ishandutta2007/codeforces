#include<bits/stdc++.h>
using namespace std;
#define MN 2005
int rk[MN],val[MN],siz[MN],cnt,n,fa[MN],id[MN];
vector<int>edge[MN],num;
void dfs(int x){
	siz[x]=1;
	for(int i=0;i<edge[x].size();++i){
		dfs(edge[x][i]);
		siz[x]+=siz[edge[x][i]];
	}
}
bool cmp(int a,int b){return val[a]<val[b];}
void getsub(int x){
	num.push_back(x);
	for(int i=0;i<edge[x].size();++i)getsub(edge[x][i]);
}
void build(int x){
	if(!edge[x].size()) {val[x]=++cnt;return;}
	for(int i=0;i<edge[x].size();++i){
		build(edge[x][i]);
	}
	num.clear();
	//getsub(x);
	for(int i=0;i<edge[x].size();++i)getsub(edge[x][i]);
	sort(num.begin(),num.end(),cmp);
	if(rk[x])val[x]=val[num[rk[x]-1]]+1;
	else val[x]=1;
	sort(id+1,id+1+n,cmp);
	cnt++;
	for(int i=1;i<=n;++i)
		if(val[id[i]]>=val[x]&&id[i]!=x)val[id[i]]=++cnt;
//	cerr<<"get: "<<x<<": "<<val[x]<<endl;
}
void getans(int x){
	num.clear();
	int cnt=0;
	for(int i=0;i<edge[x].size();++i){getsub(edge[x][i]);}
	for(int i=0;i<num.size();++i)
		if(val[num[i]]<val[x])cnt++;
		if(cnt!=rk[x]){puts("NO");exit(0);}
}
int main(){
	scanf("%d",&n);
	int rt=1;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&fa[i],&rk[i]);
		id[i]=i;
		if(fa[i]==0)rt=i;
		else edge[fa[i]].push_back(i);
	}
	dfs(rt);
	for(int i=1;i<=n;++i){if(rk[i]>=siz[i]){puts("NO");return 0;}} 
	build(rt);
	getans(rt);
	puts("YES");
	for(int i=1;i<=n;++i)printf("%d ",val[i]);
	return 0;
}