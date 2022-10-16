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

int a[200010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int pos=0;
		for(int i=1;i<=n;i++) if(a[i]!=0){
			pos=i;break;
		}
		if(pos==0){
			cout<<0<<'\n';
			continue;
		}
		int cnt=1,ans=0;
		for(int i=pos;i<=n;i++){
			if(a[i]==0){
				ans++;
				while(i<=n&&a[i]==0) i++;
				i--;
			}
		}
		if(a[n]!=0) ans++;
		cout<<min(ans,2)<<'\n';
	}
	return 0;
}