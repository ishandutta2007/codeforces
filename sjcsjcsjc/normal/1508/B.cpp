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

int f[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	f[0]=1;f[1]=1;
	for(int i=2;i<=100000;i++){
		if(f[i-1]==-1) f[i]=-1;
		else{
			f[i]=1ll*f[i-1]*2;
			if(f[i]>(int)1e18) f[i]=-1;
		}
	}
	while(t--){
		int n,k;cin>>n>>k;
		if(f[n]!=-1&&k>f[n]) cout<<-1<<'\n';
		else{
			for(int i=1;i<=n;i++){
				int len=n-i+1,now=f[len-1],val=i,cnt=1;
				while(now!=-1&&now<k){
					k-=now;len--;now=f[len-1];val++;cnt++;
				}
				for(int j=i;j<=i+cnt-1;j++) cout<<val-j+i<<" ";
				i=i+cnt-1;
			}
			cout<<'\n';
		}
	}
	return 0;
}