#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn=500000;
const int Mod=998244353;
int n,k,m;
vector<pair<int,int> > qu[Maxn+5];
int d[Maxn+5];
int f[Maxn+5];
int rnk[Maxn+5];
int solve(int id){
	memset(d,0,sizeof d);
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)qu[i].size();j++){
			if((qu[i][j].second>>id)&1){
				d[qu[i][j].first]++;
				d[i+1]--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		d[i]+=d[i-1];
	}
	int tot=0,now=0;
	int all=1,ans=0;
	f[0]=1;
	for(int i=1;i<=n;i++){
		if(d[i]==0){
			rnk[i]=++tot;
		}
		else{
			rnk[i]=tot;
		}
		if(d[i]==0){
			f[tot]=(all-ans+Mod)%Mod;
			all=(all+f[tot])%Mod;
		}
		for(int j=0;j<(int)qu[i].size();j++){
			if(!((qu[i][j].second>>id)&1)){
				if(d[i]&&d[qu[i][j].first]&&rnk[i]==rnk[qu[i][j].first]){
					return 0;
				}
				int tmp_l=(d[qu[i][j].first]?rnk[qu[i][j].first]+1:rnk[qu[i][j].first]);
				while(now<tmp_l){
					ans=(ans+f[now])%Mod;
					now++;
				}
			}
		}
	}
	ans=0;
	for(int i=now;i<=tot;i++){
		ans=(ans+f[i])%Mod;
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;i++){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		qu[r].push_back(make_pair(l,x));
	}
	int ans=1;
	for(int i=0;i<k;i++){
		ans=1ll*ans*solve(i)%Mod;
	}
	printf("%d\n",ans);
	return 0;
}