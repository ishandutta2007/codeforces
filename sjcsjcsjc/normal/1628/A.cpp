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

int n,a[200010],val[200010],num[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int x=0;
		for(int i=n;i>=1;i--){
			num[a[i]]++;
			while(num[x]>0) x++;
			val[i]=x;
		}
		for(int i=1;i<=n;i++) num[a[i]]--;
		vector<int> v;
		x=0;int pre=1;
		for(int i=1;i<=n;i++){
			num[a[i]]++;
			while(num[x]>0) x++;
			if(x==val[pre]){
				v.push_back(x);
				for(int j=pre;j<=i;j++) num[a[j]]--;
				x=0;pre=i+1;
			}
		}
		cout<<v.size()<<'\n';
		for(int i=0;i<v.size();i++) cout<<v[i]<<' ';
		cout<<'\n';
	}
	return 0;
}