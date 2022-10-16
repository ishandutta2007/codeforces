#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define MOD 998244353
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

int a[100010],pw[100010],rev[100010];

inline int my_pow(int x,int y)
{
	if(y==1) return x;
	int res=my_pow(x,y/2);
	if(y%2==0) return 1ll*res*res%MOD;
	else return 1ll*res*res%MOD*x%MOD;
}

inline int calc(int x,int y)
{
	return 1ll*pw[x]*rev[y]%MOD*rev[x-y]%MOD; 
}

signed main()
{
	ios::sync_with_stdio(false);
	pw[0]=1;
	for(int i=1;i<=100000;i++) pw[i]=1ll*pw[i-1]*i%MOD;
	rev[100000]=my_pow(pw[100000],MOD-2);
	for(int i=99999;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			char ch;cin>>ch;
			if(ch=='0') a[i]=0,cnt0++;
			else{
				a[i]=1,cnt1++;
			}
		}
		int tot=cnt1,r=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1) r++;
			else{
				if(r%2) tot--;
				r=0;
			}
		}
		if(r%2) tot--;
		cout<<calc(tot/2+cnt0,cnt0)<<'\n';
	}
	return 0;
}