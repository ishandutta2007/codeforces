#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 2000000007
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

int l[100010],r[100010],c[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>l[i]>>r[i]>>c[i];
		int mn=INF,val1=INF,mx=-INF,val2=INF,val3=INF;
		for(int i=1;i<=n;i++){
			if(l[i]<mn){
				mn=l[i];val1=c[i];val3=INF;
			}
			else if(l[i]==mn) val1=min(val1,c[i]);
			if(r[i]>mx){
				mx=r[i];val2=c[i];val3=INF;
			}
			else if(r[i]==mx) val2=min(val2,c[i]);
			if(l[i]==mn&&r[i]==mx) val3=min(val3,c[i]);
			cout<<min(val1+val2,val3)<<'\n';
		}
	}
	return 0;
}