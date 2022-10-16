#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define MOD 1000000007ll
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

int n,a[500010],cnt[100];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int sum=0ll;
		for(int j=0;j<=60;j++) cnt[j]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<60;j++) if(a[i]&(1ll<<j)) cnt[j]++;
		}
		for(int i=1;i<=n;i++){
			int sum1=0ll,sum2=0ll;
			for(int j=0;j<60;j++){
				if(a[i]&(1ll<<j)){
					add(sum1,(cnt[j]*((1ll<<j)%MOD))%MOD);
					add(sum2,(n*((1ll<<j)%MOD))%MOD);
				}
				else{
					add(sum2,(cnt[j]*((1ll<<j)%MOD))%MOD);
				}
			}
			add(sum,(sum1*sum2)%MOD);
		}
		cout<<sum<<'\n'; 
	}
	return 0;
}