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

int a[200010];
vector<int> v[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],v[a[i]].push_back(i);
	vector<pair<int,int> > g;
	for(int i=1;i<=n;i++) if(v[i].size()>1){
		g.push_back(make_pair(v[i][0],v[i].back()));
	}
	if(g.empty()){
		cout<<0<<'\n';
		return 0;
	}
	sort(g.begin(),g.end());
	vector<pair<int,int> > u;
	int now=0;
	for(int i=0;i<g.size();i++){
		u.push_back(g[i]);
		int maxv=0,pos=-1;
		now=max(now,i);
		while(now+1<g.size()&&g[now+1].first<g[i].second){
			if(g[now+1].second>maxv){
				maxv=g[now+1].second;pos=now+1;
			}
			now++;
		}
		if(maxv<g[i].second) i=now;
		else i=pos-1;
	}
	int pre=u[0].first,cnt=1,ans=0;
	for(int i=1;i<u.size();i++){
		if(u[i].first>u[i-1].second){
			ans+=u[i-1].second-pre-1;
			ans-=cnt-1;
			pre=u[i].first;
			cnt=1;
		}
		else cnt++;
	}
	ans+=u.back().second-pre-1;
	ans-=cnt-1;
	cout<<ans<<'\n';
	return 0;
}