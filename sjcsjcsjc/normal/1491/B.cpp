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

int a[110];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,u,v;cin>>n>>u>>v;
		for(int i=1;i<=n;i++) cin>>a[i];
		bool ok=true;
		for(int i=2;i<=n;i++){
			if(abs(a[i]-a[i-1])>=2){
				ok=false;
				cout<<0<<'\n';
				break;
			}
		}
		if(!ok) continue;
		bool flag=true;
		for(int i=2;i<=n;i++) if(a[i]!=a[1]){
			flag=false;break;
		}
		if(flag) cout<<min(u+v,v+v)<<'\n';
		else cout<<min(u,v)<<'\n';
	}	
	return 0;
}