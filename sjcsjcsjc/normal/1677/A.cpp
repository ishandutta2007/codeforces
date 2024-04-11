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

int n,a[5010],val1[5010][5010],val2[5010][5010]; 

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long ans=0ll;
		for(int i=1;i<=n;i++) val1[0][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) val1[i][j]=val1[i-1][j];
			for(int j=a[i];j<=n;j++) val1[i][j]++;
		}
		for(int i=1;i<=n;i++) val2[n+1][i]=0;
		for(int i=n;i>=1;i--){
			for(int j=1;j<=n;j++) val2[i][j]=val2[i+1][j];
			for(int j=a[i];j<=n;j++) val2[i][j]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=1ll*val1[i-1][a[j]-1]*val2[j+1][a[i]-1];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}