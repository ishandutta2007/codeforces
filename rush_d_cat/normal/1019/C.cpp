#include <bits/stdc++.h>
using namespace std;
const int N=1000000+10;
int n,m,f[N];
vector<int> g[N],rg[N];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y; scanf("%d%d",&x,&y);
		g[x].push_back(y); rg[y].push_back(x);
	}
	vector<int> vec;
	for(int i=1;i<=n;i++){
		if(f[i])continue;
		vec.push_back(i);
		f[i]=1; for(auto j:g[i])f[j]=1;
	}
	reverse(vec.begin(),vec.end());
	memset(f,0,sizeof(f));
	vector<int> ans;
	for(auto x:vec){
		bool flag=0;
		for(auto y:g[x]) if(f[y]) flag=1;
		for(auto y:rg[x])if(f[y]) flag=1;
		if(flag==0)ans.push_back(x),f[x]=1; 
	}
	printf("%d\n", ans.size());
	for(auto x:ans){
		printf("%d ", x);
	}
}