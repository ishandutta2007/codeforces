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

char a[50][50];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		int tot=(n+1)/2;
		if(k>tot) cout<<-1<<'\n';
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					a[i][j]='.';
				}
			}
			for(int i=1;i<=k;i++) a[2*i-1][2*i-1]='R';
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++) cout<<a[i][j];
				cout<<'\n';
			}
		}
	}
	return 0;
}