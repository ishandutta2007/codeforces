#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
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

int n,k,a[1000010],pw[1000010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		pw[0]=1;
		for(int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*i%MOD;
		bool flag=true;
		for(int i=n-k+1;i<=n;i++){
			if(a[i]!=0&&a[i]!=-1){
				flag=false;break;
			}
		}
		if(a[1]!=0&&a[1]!=-1){
			flag=false;
		}
		if(!flag){
			cout<<0<<'\n';
			continue;
		}
		int cnt=k+1;
		for(int i=2;i<=n-k;i++) if(a[i]==0) cnt++;
		int now=pw[k+1];
		for(int i=1;i<=cnt-k-1;i++) now=1ll*now*(k+1)%MOD;
		for(int i=2;i<=n-k;i++) if(a[i]==-1){
			now=1ll*now*(k+1+i-1)%MOD;
		}
		cout<<now<<'\n';
	}
	return 0;
}