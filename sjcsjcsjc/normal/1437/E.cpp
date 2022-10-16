#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
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

int n,k,cnt,a[500010],b[500010],dp[500010],bit[500010];
map<int,int> mp,pm;

inline int maxv(int p)
{
	int s=-INF;
	while(p>0){
		s=max(s,bit[p]);
		p-=p&(-p);
	}
	return s;
}

inline void add(int p,int v)
{
	while(p<=cnt){
		bit[p]=max(bit[p],v);
		p+=p&(-p);
	}
}

inline int calc(int x,int y)
{
	mp.clear();pm.clear();
	for(int i=x;i<=y;i++){
		mp[a[i]]=1;
	}
	cnt=0;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		cnt++;
		pm[it->first]=cnt;
	}
	for(int i=1;i<=cnt;i++) bit[i]=-INF;
	dp[x]=1;add(pm[a[x]],1);
	for(int i=x+1;i<=y;i++){
		dp[i]=maxv(pm[a[i]])+1;
		add(pm[a[i]],dp[i]);
	}
	return dp[y];
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],a[i]-=i;
	for(int i=1;i<=k;i++) cin>>b[i];
	a[0]=-INF;a[n+1]=INF;
	b[0]=0;b[k+1]=n+1;
	for(int i=0;i<=k;i++){
		if(a[b[i]]>a[b[i+1]]){
			cout<<-1<<endl;
			return 0;
		}
	}
	int ans=0;
	for(int i=0;i<=k;i++){
		ans+=(b[i+1]-b[i]+1)-calc(b[i],b[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}