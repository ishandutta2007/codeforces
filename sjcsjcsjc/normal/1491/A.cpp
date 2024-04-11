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

int a[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int n,q,cnt0=0,cnt1=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==0) cnt0++;
		else cnt1++;
	}
	for(int i=1;i<=q;i++){
		int flag;cin>>flag;
		if(flag==1){
			int x;cin>>x;
			if(a[x]==0) cnt0--,cnt1++;
			else cnt0++,cnt1--;
			a[x]^=1;
		}
		else{
			int k;cin>>k;
			if(k<=cnt1) cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}
	return 0;
}