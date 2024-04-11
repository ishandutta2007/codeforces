#include<bits/stdc++.h>
using namespace std;
#define MN 1000005
int read(){
	int a=0,fh=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a*fh;
}
vector<int>ans,edge[MN];
bool flag;
int T,n,a[MN];
bool vis[MN],inq[MN];
int N,st[MN];
void dfs(int x){
	vis[x]=1;
	inq[x]=1;
	st[++N]=x;
	for(int i=0;i<edge[x].size()&&!flag;++i){
		int v=edge[x][i];
		if(inq[v]){
			int t=N;
			while(st[t]!=v){
				assert(t);
				ans.push_back(st[t--]);
			}
			ans.push_back(v);
			flag=1;
		}
		else if(!vis[v])dfs(v);
	}
	N--;
	inq[x]=0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		ans.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			edge[i].clear();
			vis[i]=inq[i]=0;
		}
		N=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);a[i]=i-a[i];
			edge[a[i]].push_back(i);
//			cerr<<"edg: "<<a[i]<<" "<<i<<endl;
		}
		flag=0;
		ans.clear();
		for(int i=1;i<=n;++i)
			if(!vis[i])dfs(i);
		printf("%d\n",(int)ans.size());
		for(int i=0;i<ans.size();++i)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}