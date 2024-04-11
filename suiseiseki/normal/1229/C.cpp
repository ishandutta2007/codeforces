#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define Maxn 100000
vector<int> g[Maxn+5];
int n,m,q;
int sum[Maxn+5],out[Maxn+5];
ll work(int x){
	return 1ll*out[x]*(sum[x]-out[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	int a,b;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		sum[a]++,sum[b]++;
		if(a>b){
			swap(a,b);
		}
		g[a].push_back(b);
		out[a]++;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=work(i);
	}
	cout<<ans<<endl;
	scanf("%d",&q);
	int len;
	for(int i=1;i<=q;i++){
		scanf("%d",&a);
		len=(int)g[a].size();
		for(int j=1,u;j<=len;j++){
			u=g[a].back();
			g[a].pop_back();
			g[u].push_back(a);
			ans-=work(a)+work(u);
			out[a]--;
			out[u]++;
			ans+=work(a)+work(u);
		}
		cout<<ans<<endl;
	}
	return 0;
}