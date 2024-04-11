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

int a[110],sum1[110],sum2[110];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++){
			char c;cin>>c;
			a[i]=c-'0';
		}
		sum1[0]=0;
		for(int i=1;i<=n;i++) sum1[i]=sum1[i-1]+a[i];
		sum2[n+1]=0;
		for(int i=n;i>=1;i--) sum2[i]=sum2[i+1]+a[i];
		for(int i=1;i<=k;i++){
			int x,y;cin>>x>>y;
			bool flag=false;
			if(a[x]==0&&sum1[x-1]!=x-1) flag=true;
			if(a[x]==1&&sum1[x-1]!=0) flag=true;
			if(a[y]==0&&sum2[y+1]!=n-y) flag=true;
			if(a[y]==1&&sum2[y+1]!=0) flag=true;
			if(flag) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}
	return 0;
}