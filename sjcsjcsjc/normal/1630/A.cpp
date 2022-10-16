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

int a[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		if(n==4){
			if(k==0){
				cout<<0<<' '<<3<<'\n';
				cout<<1<<' '<<2<<'\n';
			}
			else if(k==1){
				cout<<0<<' '<<2<<'\n';
				cout<<1<<' '<<3<<'\n';
			}
			else if(k==2){
				cout<<0<<' '<<1<<'\n';
				cout<<2<<' '<<3<<'\n'; 
			}
			else cout<<-1<<'\n';
		}
		else{
			for(int i=0;i<n;i++) a[i]=n-1-i;
			int x=-1,p=n;
			while(p!=0){
				x++;p/=2;
			}
			for(int i=0;i<x;i++) if(k&(1<<i)){
				int u=a[0];
				a[1<<i]=u;
				a[0]=n-1-(1<<i);
				a[n-1-(1<<i)]=0;
				a[u]=(1<<i);
			}
			for(int i=0;i<n;i++) if(i<a[i]){
				cout<<i<<' '<<a[i]<<'\n';
			}
		}
	}
	return 0;
}