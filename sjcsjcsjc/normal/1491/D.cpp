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

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int x,y;cin>>x>>y;
		if(x>y){
			cout<<"NO\n";continue;
		}
		int cnt1=__builtin_popcount(x),cnt2=__builtin_popcount(y);
		if(cnt1<cnt2){
			cout<<"NO\n";continue;
		}
		int val=cnt1-cnt2;
		vector<int> v1,v2;
		for(int i=0;i<30;i++) if(x&(1<<i)) v1.push_back(i);
		for(int i=0;i<30;i++) if(y&(1<<i)) v2.push_back(i);
		reverse(v1.begin(),v1.end());reverse(v2.begin(),v2.end());
		int pos=-1;
		for(int i=0;i<v2.size();i++){
			if(v2[i]>v1[i]){
				pos=i;break;
			}
		}
		if(pos==-1){
			cout<<"YES\n";continue;
		}
		bool flag=true;
		for(int i=pos+1;i<v2.size();i++){
			if(v2[i]<v1[v1.size()-(v2.size()-i)]){
				flag=false;break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}