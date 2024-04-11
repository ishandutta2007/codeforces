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

int n,a[400010],b[400010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		a[0]=0;a[n+1]=0;
		for(int i=0;i<=n+1;i++) b[i]=a[i];
		long long ans=0ll;
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1]&&a[i]>a[i+1]){
				b[i]=max(a[i-1],a[i+1]);
				ans+=1ll*(a[i]-b[i]);
			}
		}
		for(int i=0;i<=n;i++) ans+=1ll*abs(b[i]-b[i+1]);
		cout<<ans<<'\n';
	}
	return 0;
}