#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
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

int a[200010],b[200010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		int k;cin>>k;
		for(int i=1;i<=k;i++) cin>>b[i];
		vector<pair<int,long long> > v1,v2;
		for(int i=1;i<=n;i++){
			int p=a[i];
			while(p%m==0) p/=m;
			pair<int,long long> now=make_pair(p,1ll*a[i]/p);
			if(!v1.empty()&&v1.back().first==now.first) v1.back().second+=1ll*a[i]/p;
			else v1.push_back(now);
		}
		for(int i=1;i<=k;i++){
			int p=b[i];
			while(p%m==0) p/=m;
			pair<int,long long> now=make_pair(p,1ll*b[i]/p);
			if(!v2.empty()&&v2.back().first==now.first) v2.back().second+=1ll*b[i]/p;
			else v2.push_back(now);
		}
		if(v1.size()!=v2.size()){
			cout<<"No\n";
		}
		else{
			bool flag=true;
			for(int i=0;i<v1.size();i++) if(v1[i].first!=v2[i].first||v1[i].second!=v2[i].second){
				flag=false;break;
			}
			if(flag) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}