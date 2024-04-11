#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
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

int pw[30],c[30][30];

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*i;
	for(int i=0;i<=n;i++) c[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	cout<<c[n][n/2]*pw[n/2-1]*pw[n/2-1]/2<<endl;
	return 0;
}