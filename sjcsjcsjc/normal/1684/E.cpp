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

int n,k,cnt,a[100010],bit1[100010],bit2[100010],num[100010],vis[100010],id[100010],u[100010];
map<int,int> mp,pm;

inline void add(int p,int v)
{
	while(p<=cnt){
		bit1[p]+=v;
		bit2[p]++;
		p+=p&(-p);
	}
}

inline int sum1(int p)
{
	int s=0;
	while(p!=0){
		s+=bit1[p];
		p-=p&(-p);
	}
	return s;
}

inline int sum2(int p)
{
	int s=0;
	while(p!=0){
		s+=bit2[p];
		p-=p&(-p);
	}
	return s;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		mp.clear();pm.clear();cnt=0;
		for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]=1;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			cnt++;
			pm[it->first]=cnt;u[cnt]=(it->first);
		}
		for(int i=1;i<=cnt;i++) num[i]=0,id[i]=0,bit1[i]=0,bit2[i]=0;
		for(int i=1;i<=n;i++) num[pm[a[i]]]++;
		vector<pair<int,int> > v;
		for(int i=1;i<=cnt;i++) v.push_back(make_pair(num[i],i));
		sort(v.begin(),v.end());
		for(int i=1;i<=cnt;i++) id[v[i-1].second]=i;
		for(int i=0;i<=n-1;i++) vis[i]=0;
		for(int i=1;i<=n;i++) if(a[i]<=n-1) vis[a[i]]=1;
		for(int i=1;i<=n-1;i++) vis[i]+=vis[i-1];
		int ans=n,o=cnt,tot=0;
		for(int i=n;i>=0;i--){
			int rem=0;
			if(i>0) rem=i-vis[i-1];
			while(o>0&&u[o]>=i){
				add(id[o],num[o]);tot++;o--;
			}
			if(rem>k) continue;
			int l=0,r=cnt,res=0;
			while(l<=r){
				int mid=(l+r)/2;
				if(sum1(mid)<=k){
					res=sum2(mid);l=mid+1;
				}
				else r=mid-1;
			}
			ans=min(ans,tot-res);
		}
		cout<<ans<<'\n';
	}
	return 0;
}