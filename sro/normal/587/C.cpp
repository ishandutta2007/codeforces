#include <bits/stdc++.h>
using namespace std;

int n,m,q;
vector<int> nei[100005];
int fa[20][100005];
vector<int> ts[20][100005];
vector<int> hv[100005];
int ceng[100005];

void dfs(int now=1,int lst=0){
	fa[0][now]=lst;
	ts[0][now]=hv[now];
	ceng[now]=ceng[lst]+1;
	for(int i=0;i<nei[now].size();i++){
		if(nei[now][i]==lst){
			continue;
		}
		dfs(nei[now][i],now);
	}
}

vector<int> merge(vector<int> a,vector<int> b){
	int na,nb;
	vector<int> ans;
	for(na=nb=0;(na<a.size()||nb<b.size())&&ans.size()<10;){
		if(nb==b.size()||(na<a.size()&&a[na]<b[nb])){
			ans.push_back(a[na]);
			na++;
		}else{
			ans.push_back(b[nb]);
			nb++;
		}
	}
	return ans;
}

int lca(int a,int b){
	if(ceng[a]>ceng[b]){
		swap(a,b);
	}
	int xx=ceng[b]-ceng[a];
	for(int i=0;xx;i++,xx>>=1){
		if(xx&1){
			b=fa[i][b];
		}
	}
	if(a==b){
		return a;
	}
	for(int i=19;~i;i--){
		if(fa[i][a]!=fa[i][b]){
			a=fa[i][a];
			b=fa[i][b];
		}
	}
	return fa[0][a];
}

vector<int> getans(int a,int b){
	int xx=ceng[a]-ceng[b];
	vector<int> ans;
	for(int i=0;xx;i++,xx>>=1){
		if(xx&1){
			ans=merge(ans,ts[i][a]);
			a=fa[i][a];
		}
	}
	return ans;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		nei[a].push_back(b);
		nei[b].push_back(a);
	}
	for(int i=1;i<=m;i++){
		int ci;
		scanf("%d",&ci);
		if(hv[ci].size()<10){
			hv[ci].push_back(i);
		}
	}
	dfs();
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			fa[i][j]=fa[i-1][fa[i-1][j]];
			ts[i][j]=merge(ts[i-1][j],ts[i-1][fa[i-1][j]]);
		}
	}
	while(q--){
		int u,v,a;
		scanf("%d%d%d",&u,&v,&a);
		int jj=lca(u,v);
		vector<int> ans=merge(merge(getans(u,jj),getans(v,jj)),hv[jj]);
		printf("%d",min(a,(int)ans.size()));
		for(int i=0;i<min(a,(int)ans.size());i++){
			printf(" %d",ans[i]);
		}
		puts("");
	}
	return 0;
}