#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000000000000007ll
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

int n,a[200010],b[200010],bit[200010];
deque<int> q[30];

inline void add(int p,int v)
{
	while(p<=n){
		bit[p]+=v;
		p+=p&(-p);
	}
}

inline int sum(int p)
{
	int s=0;
	while(p!=0){
		s+=bit[p];
		p-=p&(-p);
	}
	return s;
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=26;i++){
			while(!q[i].empty()) q[i].pop_back();
		}
		for(int i=1;i<=n;i++){
			char ch;cin>>ch;
			a[i]=ch-'a'+1;
			q[a[i]].push_back(i);
		}
		for(int i=1;i<=n;i++){
			char ch;cin>>ch;
			b[i]=ch-'a'+1;
		}
		long long ans=INF,now=0ll;
		for(int i=1;i<=n;i++) bit[i]=0;
		for(int i=1;i<=n;i++){
			long long val=INF;
			for(int j=1;j<=b[i]-1;j++) if(!q[j].empty()){
				int x=q[j].front();
				val=min(val,1ll*(x-sum(x)-1));
			}
			ans=min(ans,now+val);
			if(q[b[i]].empty()) break;
			int x=q[b[i]].front();
			now+=1ll*(x-sum(x)-1);
			add(x,1);
			q[b[i]].pop_front();
		}
		if(ans==INF) ans=-1ll;
		cout<<ans<<'\n';
	}
	return 0;
}