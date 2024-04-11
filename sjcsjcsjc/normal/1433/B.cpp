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

int a[110];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=n;
		for(int i=1;i<=n;i++) if(a[i]==1){
			int pos1,pos2;
			for(int j=1;j<=i;j++) if(a[j]==1){
				pos1=j;break;
			}
			for(int j=n;j>=i;j--) if(a[j]==1){
				pos2=j;break;
			}
			int cnt1=0,cnt2=0;
			for(int j=1;j<=i;j++) cnt1+=a[j];
			for(int j=n;j>=i;j--) cnt2+=a[j];
			ans=min(ans,(i-pos1-cnt1+1)+(pos2-i-cnt2+1));
		}
		cout<<ans<<'\n';
	}
	return 0;
}