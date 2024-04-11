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

int n,a[300010],b[300010],dp[300010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	dp[0]=0ll;
	deque<pair<int,pair<int,int> > > q;
	multiset<int> s;
	for(int i=1;i<=n;i++){
		pair<int,pair<int,int> > now=make_pair(a[i],make_pair(b[i],dp[i-1]));
		while(!q.empty()){
			pair<int,pair<int,int> > t=q.back();
			if(t.first>now.first){
				q.pop_back();
				s.erase(s.find(-t.second.first-t.second.second));
				now.second.second=max(now.second.second,t.second.second);
			}
			else break;
		}
		q.push_back(now);
		s.insert(-now.second.first-now.second.second);
		dp[i]=-(*s.begin());
	}
	cout<<dp[n]<<endl;
	return 0;
}