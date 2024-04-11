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

int k[100010],num[100010],ans[100010];
vector<int> v[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++) num[i]=0;
		for(int i=1;i<=m;i++) ans[i]=0;
		for(int i=1;i<=m;i++){
			cin>>k[i];v[i].clear();
			for(int j=1;j<=k[i];j++){
				int x;cin>>x;v[i].push_back(x);
			}
		}
		for(int i=1;i<=m;i++) if(k[i]==1) num[v[i][0]]++,ans[i]=v[i][0];
		for(int i=1;i<=m;i++) if(k[i]!=1){
			int minv=m+1,pos=0;
			for(int j=1;j<=k[i];j++){
				if(num[v[i][j-1]]<minv){
					minv=num[v[i][j-1]];
					pos=j;
				}
			}
			num[v[i][pos-1]]++;ans[i]=v[i][pos-1];
		}
		bool flag=true;
		for(int i=1;i<=n;i++) if(num[i]>(m+1)/2){
			flag=false;break;
		}
		if(!flag) cout<<"NO\n";
		else{
			cout<<"YES\n";
			for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}