#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
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

int c[100010];
char a[100010],b[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++) if(a[i]=='1') cnt0++;
		for(int i=1;i<=n;i++) if(b[i]=='1') cnt1++;
		int ans=INF;
		if(cnt0==cnt1){
			int tot=0;
			for(int i=1;i<=n;i++) if(a[i]!=b[i]) tot++;
			ans=min(ans,tot);
		}
		if(cnt0==n+1-cnt1){
			int x=0;
			for(int i=1;i<=n;i++) if(a[i]=='1'&&b[i]=='1'){
				x=i;break;
			}
			for(int i=1;i<=n;i++){
				if(i!=x){
					if(a[i]=='0') a[i]='1';
					else a[i]='0';
				}
			}
			int tot=0;
			for(int i=1;i<=n;i++) if(a[i]!=b[i]) tot++;
			ans=min(ans,tot+1);
		}
		if(ans==INF) ans=-1;
		cout<<ans<<'\n';
	}
	return 0;
}