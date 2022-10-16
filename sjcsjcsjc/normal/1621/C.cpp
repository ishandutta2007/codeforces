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

int p[10010];
bool vis[10010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) vis[i]=0,p[i]=0;
		for(int i=1;i<=n;i++) if(!vis[i]){
			cout<<"? "<<i<<'\n';fflush(stdout);
			int x;cin>>x;vis[x]=1;
			vector<int> v;v.push_back(x);
			while(true){
				cout<<"? "<<i<<'\n';fflush(stdout);
				cin>>x;
				if(vis[x]) break;
				vis[x]=1;
				v.push_back(x);
			}
			for(int j=0;j<v.size();j++) p[v[j]]=v[(j+1)%v.size()];
		}
		cout<<"!";
		for(int i=1;i<=n;i++) cout<<' '<<p[i];
		cout<<'\n';
		fflush(stdout);
	}
	return 0;
}