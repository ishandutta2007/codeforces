#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int n,m,p,tot,a[200010][70],vis[200010],ok[70],b[70];
cc_hash_table<long long,int,custom_hash> mp;
vector<pair<long long,int> > g;

signed main()
{
	srand((unsigned long long)new char);
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch=getchar();
			while(ch<'0'||ch>'9') ch=getchar();
			a[i][j]=ch-'0';
		}
	}
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int j=1;j<=n;j++) cnt+=a[j][i];
		if(cnt>=(n+1)/2) ok[i]=1;
	}
	for(int i=1;i<=n;i++){
		long long msk=0ll;
		for(int j=1;j<=m;j++) if(a[i][j]&&ok[j]){
			msk+=(1ll<<(j-1));
		}
		if(msk) mp[msk]++;
	}
	for(cc_hash_table<long long,int,custom_hash>::iterator it=mp.begin();it!=mp.end();it++){
		g.push_back(*it);
	}
	for(int i=1;i<=m;i++) if(ok[i]) b[++tot]=i;
	int res=0;long long ans=0ll;
	int val=0;
	while(clock()+val<2950){
		int aa=clock();
		random_shuffle(b+1,b+tot+1);
		for(int j=0;j<g.size();j++) vis[j]=1;
		int cur=0;long long now=0ll;
		for(int i=1;i<=tot;i++){
			int num=0;
			for(int j=0;j<g.size();j++) if(vis[j]&&(g[j].first&(1ll<<(b[i]-1)))){
				num+=g[j].second;
			}
			if(num>=(n+1)/2){
				cur++;now+=(1ll<<(b[i]-1));
				for(int j=0;j<g.size();j++) if(vis[j]&&(!(g[j].first&(1ll<<(b[i]-1))))){
					vis[j]=0;
				}
			}
		}
		if(cur>res){
			res=cur;ans=now;
		}
		val=clock()-aa;
	}
	for(int i=1;i<=m;i++){
		if(ans&(1ll<<(i-1))) putchar('1');
		else putchar('0');
	}
	puts("");
	return 0; 
}