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

int a[200010],b[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,l,r;cin>>n>>l>>r;
		for(int i=1;i<=n;i++) a[i]=0;
		for(int i=1;i<=l;i++){
			int x;cin>>x;a[x]++;
		}
		for(int i=1;i<=n;i++) b[i]=0;
		for(int i=1;i<=r;i++){
			int x;cin>>x;b[x]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>b[i]){
				a[i]-=b[i];b[i]=0;
			}
			else{
				b[i]-=a[i];a[i]=0;
			}
		}
		int sum0=0,sum1=0;
		for(int i=1;i<=n;i++) sum0+=a[i];
		for(int i=1;i<=n;i++) sum1+=b[i];
		if(sum0<sum1){
			ans+=sum0;
			for(int i=1;i<=n;i++){
				a[i]=0;
			}
			for(int i=1;i<=n&&sum0;i++) if(b[i]%2==1){
				sum0--;b[i]--;
			}
			if(sum0){
				for(int i=1;i<=n&&sum0;i++){
					if(sum0>b[i]) sum0-=b[i],b[i]=0;
					else b[i]-=sum0,sum0=0;
				} 
			}
		}
		else{
			ans+=sum1;
			for(int i=1;i<=n;i++){
				b[i]=0;
			}
			for(int i=1;i<=n&&sum1;i++) if(a[i]%2==1){
				sum1--;a[i]--;
			}
			if(sum1){
				for(int i=1;i<=n&&sum1;i++){
					if(sum1>a[i]) sum1-=a[i],a[i]=0;
					else a[i]-=sum1,sum1=0;
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans+=a[i]/2;a[i]=a[i]%2;
			ans+=b[i]/2;b[i]=b[i]%2; 
		}
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			cnt0+=a[i];cnt1+=b[i];
		}
		ans+=cnt0;ans+=cnt1;
		cout<<ans<<'\n';
	}
	return 0;
}