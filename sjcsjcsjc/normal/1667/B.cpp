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

int n,cnt,a[500010],dp[500010],pre[500010],bit1[500010],bit2[500010];
long long sum[500010];
map<long long,int> mp,pm;

inline void add1(int p,int v)
{
	while(p<=cnt){
		bit1[p]=max(bit1[p],v);
		p+=p&(-p);
	}
}

inline int mx1(int p)
{
	int s=-INF;
	while(p!=0){
		s=max(s,bit1[p]);
		p-=p&(-p);
	}
	return s;
}

inline void add2(int p,int v)
{
	while(p<=cnt){
		bit2[p]=max(bit2[p],v);
		p+=p&(-p);
	}
}

inline int mx2(int p)
{
	int s=-INF;
	while(p!=0){
		s=max(s,bit2[p]);
		p-=p&(-p);
	}
	return s;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		sum[0]=0ll;
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+1ll*a[i];
		mp.clear();pm.clear();
		for(int i=0;i<=n;i++) mp[sum[i]]=1;
		cnt=0;
		for(map<long long,int>::iterator it=mp.begin();it!=mp.end();it++){
			cnt++;
			pm[it->first]=cnt;
		}
		for(int i=1;i<=cnt;i++) pre[i]=-1,bit1[i]=-INF,bit2[i]=-INF;
		dp[0]=0;
		pre[pm[sum[0]]]=0;
		add1(pm[sum[0]],0);
		add2(cnt-pm[sum[0]]+1,0);
		for(int i=1;i<=n;i++){
			int val=pm[sum[i]];
			dp[i]=max(mx1(val-1)+i,mx2(cnt-val)-i);
			if(pre[val]!=-1) dp[i]=max(dp[i],dp[pre[val]]);
			pre[val]=i;
			add1(val,dp[i]-i);
			add2(cnt-val+1,dp[i]+i);
		}
		cout<<dp[n]<<'\n';
	}
	return 0;
}