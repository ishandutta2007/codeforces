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

int a[200010],ans[200010];
vector<int> v[200010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i],v[a[i]].push_back(i);
		set<int> s;
		for(int i=1;i<=n;i++) s.insert(a[i]);
		while(!s.empty()){
			vector<int> res,u;
			for(set<int>::iterator it=s.begin();it!=s.end();it++){
				int x=(*it);
				u.push_back(v[x].back());v[x].pop_back();
				if(v[x].empty()) res.push_back(x);
			}
			for(int i=0;i<u.size();i++){
				int nxt=u[(i+1)%u.size()];
				ans[u[i]]=nxt;
			}
			for(int i=0;i<res.size();i++) s.erase(s.find(res[i]));
		}
		for(int i=1;i<=n;i++) cout<<a[ans[i]]<<' ';
		cout<<'\n';
	}
	return 0;
}