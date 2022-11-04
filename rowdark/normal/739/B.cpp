#include<stdio.h>
#include<vector>
std::vector<long long> stack;
int n;
int a[200101];
int b[200101];
std::vector<std::pair<int,int>> c[200101];
int cnt[200101];
int d[200101];
int dfs(int x){
	b[x]=0;
	for(auto a:c[x]){
		stack.emplace_back(stack.back()+a.second);
		d[a.first]=d[x]+1;
		cnt[d[x]+1]=0;
		b[x]+=dfs(a.first);
		stack.pop_back();
	}
	++b[x];
	++cnt[lower_bound(stack.begin(),stack.end(),stack.back()-a[x])-stack.begin()];
	return b[x]-cnt[d[x]];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=2;i<=n;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		c[x].emplace_back(i,y);
	}
	stack.emplace_back(0);
	dfs(1);
	for(int i=1;i<=n;++i) printf("%d%c",b[i]-1,i==n?'\n':' ');
	return 0;
}