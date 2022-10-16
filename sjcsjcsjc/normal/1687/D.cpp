#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
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

int a[1000010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=-1;
	for(int i=1;i<=2000000;i++){
		if(1ll*i*(i+1)>=a[1]){
			int val=max(0ll,1ll*i*i-1ll*a[1]);
			int pos=1,now=i,val1=i,val2=0;
			while(true){
				int u=upper_bound(a+1,a+n+1,1ll*now*(now+1)-val)-a-1;
				if(a[u]>=1ll*now*now-val) val1=min(val1,1ll*now*(now+1)-val-a[u]);
				u++;
				if(u<=n&&a[u]<1ll*(now+1)*(now+1)-val) val2=max(val2,1ll*(now+1)*(now+1)-val-a[u]);
				if(a[n]<1ll*(now+1)*(now+1)-val) break;
				now++;
			}
			if(val1>=val2){
				ans=val+val2;
				break;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}