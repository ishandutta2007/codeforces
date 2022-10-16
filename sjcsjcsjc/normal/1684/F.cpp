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

int n,m,cnt,a[200010],val[200010],L[200010],R[200010];
vector<int> v[200010];
map<int,int> mp,pm;

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		cin>>n>>m;
		mp.clear();pm.clear();cnt=0;
		for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]=1;
		for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
			cnt++;
			pm[it->first]=cnt;
		}
		for(int i=1;i<=n;i++) a[i]=pm[a[i]];
		for(int i=1;i<=n;i++) val[i]=0;
		for(int i=1;i<=m;i++){
			int l,r;cin>>l>>r;val[l]=max(val[l],r);
		}
		for(int i=1;i<=n;i++) val[i]=max(val[i],val[i-1]);
		for(int i=1;i<=cnt;i++) v[i].clear();
		for(int i=1;i<=n;i++) v[a[i]].push_back(i);
		for(int i=1;i<=n;i++) L[i]=0,R[i]=0;
		for(int i=1;i<=cnt;i++){
			for(int j=1;j<v[i].size();j++){
				if(val[v[i][j-1]]>=v[i][j]) L[v[i][j]]=1;
			}
			for(int j=0;j<v[i].size();j++){
				int l=j+1,r=(int)v[i].size()-1;
				while(l<=r){
					int mid=(l+r)/2;
					if(val[v[i][j]]>=v[i][mid]){
						R[v[i][j]]=v[i][mid];l=mid+1;
					}
					else r=mid-1;
				}
			}
		}
		int rr=n,ans=n;
		while(rr>=1&&!R[rr]) rr--;
		if(rr==0) ans=0;
		else{
			ans=min(ans,rr);
			for(int i=2;i<=n;i++){
				if(L[i-1]) break;
				rr=max(rr,i);
				if(R[i-1]) rr=max(rr,R[i-1]);
				ans=min(ans,rr-i+1);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}