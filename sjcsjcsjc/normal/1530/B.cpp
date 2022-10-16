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

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		if(n%2==1&&m%2==1){
			for(int i=1;i<=m;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
			}
			cout<<'\n';
			for(int i=2;i<=n-1;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
				for(int j=2;j<=m-1;j++) cout<<0;
				if(i%2==1) cout<<1;
				else cout<<0;
				cout<<'\n';
			}
			for(int i=1;i<=m;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
			}
			cout<<'\n';
		}
		else if(n%2==1&&m%2==0){
			for(int i=1;i<=m;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
			}
			cout<<'\n';
			for(int i=2;i<=n-1;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
				for(int j=2;j<=m-1;j++) cout<<0;
				if(i>=3&&i<=n-2&&i%2==1) cout<<1;
				else cout<<0;
				cout<<'\n';
			}
			for(int i=1;i<=m;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
			}
			cout<<'\n';
		}
		else if(n%2==0&&m%2==1){
			for(int i=1;i<=m;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
			}
			cout<<'\n';
			for(int i=2;i<=n-1;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
				for(int j=2;j<=m-1;j++) cout<<0;
				if(i%2==1) cout<<1;
				else cout<<0;
				cout<<'\n';
			}
			for(int i=1;i<=m;i++){
				if(i>=3&&i<=m-2&&i%2==1) cout<<1;
				else cout<<0;
			}
			cout<<'\n';
		}
		else{
			for(int i=1;i<=m;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
			}
			cout<<'\n';
			for(int i=2;i<=n-1;i++){
				if(i%2==1) cout<<1;
				else cout<<0;
				for(int j=2;j<=m-1;j++) cout<<0;
				if(i%2==1) cout<<1;
				else cout<<0;
				cout<<'\n';
			}
			for(int i=1;i<=m;i++){
				if(i>=3&&i<=m-2&&i%2==1) cout<<1;
				else cout<<0;
			}
			cout<<'\n';
		}
	}
	return 0;
}