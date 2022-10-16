#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
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

int n,w[100010],deg[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++) cin>>w[i],sum+=w[i];
		for(int i=1;i<=n;i++) deg[i]=0;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;deg[x]++;deg[y]++;
		}
		priority_queue<pair<int,int> > q;
		for(int i=1;i<=n;i++){
			deg[i]--;
			if(deg[i]) q.push(make_pair(w[i],i));
		}
		cout<<sum;
		while(!q.empty()){
			pair<int,int> t=q.top();q.pop();
			deg[t.second]--;sum+=t.first;
			cout<<" "<<sum;
			if(deg[t.second]) q.push(t);
		}
		cout<<'\n';
	}
	return 0;
}