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

int n,m,pw[410],pw2[410],rev[410],dp[2][410][410];

inline void add(int &x,int y)
{
	x+=y;
	if(x>=m) x-=m; 
}

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%m;
	else return 1ll*res*res%m*x%m;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	pw[0]=1;pw2[0]=1;rev[0]=1;
	for(int i=1;i<=n;i++){
		pw[i]=1ll*pw[i-1]*i%m;
		pw2[i]=1ll*pw2[i-1]*2%m;
		rev[i]=my_pow(pw[i],m-2);
	}
	dp[1][0][0]=1;dp[1][1][1]=1ll*rev[1]*pw2[0]%m;
	for(int i=2;i<=n-2;i++){
		memset(dp[i&1],0,sizeof(dp[i&1])); 
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i-1;k++){
				add(dp[i&1][j][k],dp[(i-1)&1][j][k]);
				if(j>0&&k<i-1){
					if(k==0) add(dp[i&1][j][i],1ll*dp[(i-1)&1][j-1][k]*rev[i]%m*pw2[i-1]%m);
					else add(dp[i&1][j][i],1ll*dp[(i-1)&1][j-1][k]*rev[i-k-1]%m*pw2[i-k-2]%m);
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n-2;i++){
		for(int j=0;j<=n-2;j++){
			if(j==0) add(ans,1ll*dp[(n-2)&1][i][j]*rev[n]%m*pw2[n-1]%m*pw[n-i]%m);
			else add(ans,1ll*dp[(n-2)&1][i][j]*rev[n-j-1]%m*pw2[n-j-2]%m*pw[n-i]%m);
		}
	}
	cout<<ans<<endl;
	return 0;
}