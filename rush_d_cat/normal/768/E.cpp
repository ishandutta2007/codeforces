#include <bits/stdc++.h>
using namespace std;
int sg[61] = {0,1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};
typedef long long LL;
int n,C;
map< pair<LL,LL>, int > mp;
int dfs(int now,LL ban) {
	if(mp.count(make_pair(now, ban))) return mp[make_pair(now,ban)]; 
	bool vis[102] = {0};
	for(int i=1;i<=now;i++){
		if(ban>>i&1)continue;
		ban^=1LL<<i;
		vis[dfs(now-i,ban)] = 1;
		ban^=1LL<<i;
	}
	for(int i=0;;i++)if(vis[i]==0)return mp[make_pair(now,ban)] = i;
}
int main() {
	int n,ans=0; scanf("%d",&n); 
	for(int i=1;i<=n;i++){
		int x; scanf("%d",&x); ans^=sg[x];
	}
	printf("%s\n", ans?"NO":"YES");
}