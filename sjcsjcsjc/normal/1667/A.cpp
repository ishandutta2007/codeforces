#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000000000000007ll
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

int n,a[5010]; 

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	long long ans=INF;
	for(int i=1;i<=n;i++){
		long long val=0ll;
		long long now=0;
		for(int j=i-1;j>=1;j--){
			long long num=(now+1)/a[j]+((now+1)%a[j]!=0);
			val+=num;now=num*a[j];
		}
		now=0;
		for(int j=i+1;j<=n;j++){
			long long num=(now+1)/a[j]+((now+1)%a[j]!=0);
			val+=num;now=num*a[j];
		}
		ans=min(ans,val);
	}
	cout<<ans<<'\n';
	return 0;
}