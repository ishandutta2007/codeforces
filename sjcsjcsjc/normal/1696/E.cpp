#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 1000000007
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

int a[400010],pw[400010],rev[400010];

inline int my_pow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline void add(int &x,int y)
{
	x+=y;
	if(x>=MOD) x-=MOD;
}

inline int calc(int x,int y)
{
	return 1ll*pw[x]*rev[y]%MOD*rev[x-y]%MOD;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	pw[0]=1;
	for(int i=1;i<=400000;i++) pw[i]=1ll*pw[i-1]*i%MOD;
	rev[400000]=my_pow(pw[400000],MOD-2);
	for(int i=399999;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
	for(int i=0;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=0;i<=n;i++){
		add(ans,calc(i+a[i],i+1));
	}
	cout<<ans<<'\n';
	return 0;
}