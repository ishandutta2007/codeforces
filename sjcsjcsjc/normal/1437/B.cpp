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

int n,a[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			char c;cin>>c;
			a[i]=c-'0';
		}
		if(a[1]==1){
			int cnt=0;
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==0) cnt++;
			}
			cout<<n/2-cnt<<'\n';
		}
		else{
			int cnt=0;
			for(int i=1;i<n;i++){
				if(a[i]==0&&a[i+1]==1) cnt++; 
			}
			cout<<n/2-cnt<<'\n';
		}
	}	
	return 0;
}