#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=998244353;
const int N=1000000+10;
int n,m;
vector<int> g[N],g2[N];
LL solve(){
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end()); g2[i]=g[i];
	}
	sort(g2+1,g2+1+n);
	LL ans=0;
	for(int i=1,j=1;i<=n;i=j){
		while(j<=n && g2[j]==g2[i]) j++;
		int len=j-i;
		ans=ans+1LL*len*(len-1)/2;
	}
	return ans;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v); 
		g[u].push_back(v); g[v].push_back(u);
	}
	LL ans=solve();
	for(int i=1;i<=n;i++) g[i].push_back(i);
	ans+=solve();
	cout<<ans<<endl;
}