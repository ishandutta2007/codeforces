#include <list>
#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=100000;
int n;
ll k;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],tot;
void add_edge(int from,int to){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	head[from]=tot;
}
int sz[Maxn+5];
int val[Maxn+5];
void init_dfs(int u,int fa){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		init_dfs(v,u);
		sz[u]+=sz[v];
	}
}
list<int> work_dfs(int u,int fa){
	list<int> all;
	all.push_back(u);
	for(int i=head[u];i;i=nxt[i]){
		int v=arrive[i];
		if(v==fa){
			continue;
		}
		all.splice(all.end(),work_dfs(v,u));
	}
	int cnt=((int)all.size()-val[u])>>1;
	vector<pair<int,int> > pairs(cnt);
	for(int i=0;i<cnt;i++){
		pairs[i].first=all.front();
		pairs[cnt-i-1].second=all.back();
		all.pop_front();
		all.pop_back();
	}
	for(int i=0;i<cnt;i++){
		printf("%d %d\n",pairs[i].first,pairs[i].second);
	}
	return all;
}
int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	init_dfs(1,0);
	ll minn=0,maxn=0;
	for(int i=2;i<=n;i++){
		val[i]=min(sz[i],n-sz[i]);
		minn+=(val[i]&1);
		maxn+=val[i];
	}
	if(k<minn||k>maxn||(k&1)!=(minn&1)){
		puts("NO");
		return 0;
	}
	puts("YES");
	int left=0,right=(n>>1);
	ll cost=-1;
	while(left<=right){
		int mid=(left+right)>>1;
		ll ans=0;
		for(int i=2;i<=n;i++){
			if(val[i]<=mid){
				ans+=val[i];
			}
			else{
				ans+=mid-((val[i]&1)!=(mid&1));
			}
		}
		if(ans>=k){
			right=mid-1;
			cost=ans;
		}
		else{
			left=mid+1;
		}
	}
	for(int i=2;i<=n;i++){
		if(val[i]>left){
			val[i]=left-((val[i]&1)!=(left&1));
		}
		if(val[i]==left&&cost>k){
			val[i]-=2;
			cost-=2;
		}
	}
	work_dfs(1,0);
	return 0;
}