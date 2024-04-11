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

int n,v1[100010],v2[100010],v3[100010],v4[100010];
pair<int,int> a[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].first;
			v1[a[i].first]=v2[a[i].first]=v3[a[i].first]=v4[a[i].first]=0;
			a[i].second=i;
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i%2==0) v1[a[i].first]++;
			else v2[a[i].first]++;
			if(a[i].second%2==0) v3[a[i].first]++;
			else v4[a[i].first]++;
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(v1[a[i].first]!=v3[a[i].first]){
				flag=false;break;
			}
			if(v2[a[i].first]!=v4[a[i].first]){
				flag=false;break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}