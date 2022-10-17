#pragma optimize("Ofast")
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
#define Maxn 200000
#define ll long long
map<int,ll> mp[Maxn+5];
ll cnt[Maxn+5];
int a[Maxn+5];
inline int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
vector<int> edge[Maxn+5];
inline void dfs(int u,int fa){
	mp[u][a[u]]++;
	register map<int,ll>::iterator it_1,it_2;
	for(int i=0;i<(int)edge[u].size();i++){
		if(edge[u][i]==fa){
			continue;
		}
		dfs(edge[u][i],u);
		for(it_1=mp[edge[u][i]].begin();it_1!=mp[edge[u][i]].end();it_1++){
			for(it_2=mp[u].begin();it_2!=mp[u].end();it_2++){
				cnt[gcd(it_1->first,it_2->first)]+=(it_1->second)*(it_2->second);
			}
		}
		for(it_1=mp[edge[u][i]].begin();it_1!=mp[edge[u][i]].end();it_1++){
			mp[u][gcd(a[u],it_1->first)]+=it_1->second;
		}
		mp[edge[u][i]].clear();
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(register int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	register int u,v;
	for(register int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dfs(1,0);
	for(register int i=1;i<=Maxn;i++){
		if(cnt[i]){
			cout<<i<<" "<<cnt[i]<<endl;
		}
	}
	return 0;
}