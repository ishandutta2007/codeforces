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

pair<int,int> val[510];

signed main()
{
	int n,m;cin>>n>>m;
	for(int i=1;i<=m;i++){
		string s;
		for(int j=1;j<=m;j++) s+='0';
		s[i-1]='1';
		cout<<'?'<<' '<<s<<'\n';
		fflush(stdout);
		int x;cin>>x;
		val[i].first=x;val[i].second=i;
	}
	sort(val+1,val+m+1);
	string now;
	for(int i=1;i<=m;i++) now+='0';
	int sum=0;
	for(int i=1;i<=m;i++){
		now[val[i].second-1]='1';
		cout<<'?'<<' '<<now<<'\n';
		fflush(stdout);
		int x;cin>>x;
		if(x==sum+val[i].first) sum+=val[i].first;
		else{
			now[val[i].second-1]='0';
		}
	}
	cout<<'!'<<' '<<sum<<'\n';
	return 0;
}