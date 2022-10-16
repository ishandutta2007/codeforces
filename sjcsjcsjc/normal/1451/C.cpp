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

int a[30],b[30];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<=26;i++){
			a[i]=b[i]=0;
		}
		for(int i=1;i<=n;i++){
			char c;cin>>c;a[c-'a'+1]++; 
		}
		for(int i=1;i<=n;i++){
			char c;cin>>c;b[c-'a'+1]++;
		} 
		bool flag=true;
		for(int i=1;i<=26;i++){
			if(a[i]%k!=b[i]%k) flag=false;
			if(a[i]<b[i]) flag=false;
			if(!flag) break;
			a[i+1]+=a[i]-b[i];a[i]=b[i];
		}
		if(!flag) cout<<"No\n";
		else cout<<"Yes\n";
	}	
	return 0;
}