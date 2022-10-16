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

int n,pw[200010],rev[200010],inv[200010],ans[200010],f[800010],g[800010],r[800010];

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
	if(x<0) x+=MOD;
}

inline void NTT(int *a,int x)
{
	if(x==1) return;
	int m=x/2;
	int a0[m],a1[m];
	for(int i=0;i<m;i++){
		a0[i]=a[i*2];
		a1[i]=a[i*2+1];
	}
	NTT(a0,m);NTT(a1,m);
	if(!r[x]) r[x]=my_pow(3,(MOD-1)/x);
	int w=r[x],now=1;
	for(int i=0;i<m;i++){
		a[i]=a0[i];add(a[i],1ll*now*a1[i]%MOD);
		a[i+m]=a0[i];add(a[i+m],-1ll*now*a1[i]%MOD);
		now=1ll*now*w%MOD;
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=1ll*pw[i-1]*i%MOD;
	rev[n]=my_pow(pw[n],MOD-2);
	for(int i=n-1;i>=0;i--) rev[i]=1ll*rev[i+1]*(i+1)%MOD;
	inv[0]=1;inv[1]=1;
	for(int i=2;i<=n;i++) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	for(int i=1;i<=n;i++) ans[i]=pw[n-1];
	int x=n-1-(n+1)/2+1;
	for(int i=(n+1)/2;i<=n-1;i++) f[i-(n+1)/2]=1ll*pw[n-1-i]*inv[i]%MOD;
	for(int i=0;i<x;i++) g[i]=rev[i];
	int k=1;
	while(k<2*x) k*=2;
	NTT(f,k);NTT(g,k);
	for(int i=0;i<k;i++) f[i]=1ll*f[i]*g[i]%MOD;
	NTT(f,k);reverse(f+1,f+k);
	int re=my_pow(k,MOD-2);
	for(int i=0;i<2*x-1;i++) f[i]=1ll*f[i]*re%MOD;
	for(int i=x-1;i>=0;i--) add(ans[x-i],-1ll*f[i]*pw[n-(x-i)]%MOD);
	for(int i=2;i<=n;i++){
		int val=1ll*pw[n-1]*rev[n-i]%MOD;
		if(i<=(n+1)/2) add(val,-1ll*pw[(n+1)/2-1]*rev[(n+1)/2-i]%MOD);
		add(ans[i],-1ll*pw[n-i]*val%MOD);
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}