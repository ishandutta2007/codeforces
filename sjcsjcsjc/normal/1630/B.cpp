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

int a[200010],cnt[200010],cur[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++;
		int x=1,y=n,now=0,val=-n;
		for(int i=1;i<=n;i++){
			val-=2*cnt[i-1];
			while(now<n&&val<k){
				now++;val+=2*cnt[now];
			}
			if(val>=k){
				if(now-i<y-x){
					x=i;y=now;
				}
			}
		}
		cout<<x<<' '<<y<<'\n';
		for(int i=1;i<=n;i++){
			cur[i]=cur[i-1];
			if(a[i]>=x&&a[i]<=y) cur[i]++;
			else cur[i]--;
		}
		int z=1;
		vector<int> v;
		for(int i=1;i<=n;i++){
			if(z<k&&cur[i]==z){
				v.push_back(i);z++;
			}
		}
		v.push_back(n);
		int pre=0;
		for(int i=0;i<v.size();i++){
			cout<<pre+1<<' '<<v[i]<<'\n';
			pre=v[i];
		}
	}
	return 0;
}