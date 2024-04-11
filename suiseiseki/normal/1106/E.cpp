#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 100000
#define ll long long
struct Node{
	int d,w,t;
	friend bool operator <(Node p,Node q){
		if(p.w==q.w){
			return p.d>q.d;
		}
		return p.w>q.w;
	}
	friend bool operator ==(Node p,Node q){
		return p.d==q.d&&p.w==q.w;
	}
};
vector<Node> ti[Maxn+5];
map<Node,int> mp;
Node a[Maxn+5];
void work(Node x){
	mp[x]+=x.t;
	if(mp[x]==0){
		mp.erase(x);
	}
}
ll f[2][Maxn+5];
ll mn(ll a,ll b){
	return a<b?a:b;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int s,t,d,w;
	for(int i=1;i<=k;i++){
		scanf("%d%d%d%d",&s,&t,&d,&w);
		ti[s].push_back(Node{d,w,1});
		ti[t+1].push_back(Node{d,w,-1});
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)ti[i].size();j++){
			work(ti[i][j]);
		}
		if(mp.empty()){
			a[i]=Node{i,0,0};
		}
		else{
			a[i]=(mp.begin()->first);
		}
	}
	memset(f,0x3f,sizeof f);
	ll ans=(1ll<<62);
	f[0][1]=0;
	for(int j=0;j<=m;j++){
		memset(f[(j+1)&1],0x3f,sizeof f[(j+1)&1]);
		for(int i=1;i<=n;i++){
			f[(j+1)&1][i+1]=mn(f[(j+1)&1][i+1],f[j&1][i]);
			f[j&1][a[i].d+1]=mn(f[j&1][a[i].d+1],f[j&1][i]+a[i].w);
		}
		ans=mn(ans,f[j&1][n+1]);
	}
	cout<<ans<<endl;
	return 0;
}