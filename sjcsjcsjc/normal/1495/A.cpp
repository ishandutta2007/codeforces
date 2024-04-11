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
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> v1,v2;
		for(int i=1;i<=2*n;i++){
			int x,y;cin>>x>>y;
			if(y==0) v1.push_back(abs(x));
			if(x==0) v2.push_back(abs(y));
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		long double ans=0.0;
		for(int i=0;i<n;i++){
			long double val=(long double)v1[i]*(long double)v1[i]+(long double)v2[i]*(long double)v2[i];
			ans+=(long double)sqrt(val);
		}
		cout<<fixed<<setprecision(15)<<ans<<endl;
	}	
	return 0;
}