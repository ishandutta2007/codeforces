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

int dist[2010];
vector<int> v[2010];
vector<pair<int,int> > ans;

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	cout<<"? 1"<<'\n';
	fflush(stdout);
	for(int i=1;i<=n;i++) cin>>dist[i],v[dist[i]].push_back(i);
	int cnt0=0,cnt1=0;
	for(int i=1;i<=n;i+=2) cnt0+=v[i].size();
	for(int i=2;i<=n;i+=2) cnt1+=v[i].size();
	if(cnt0<cnt1){
		for(int i=1;i<=n;i+=2){
			for(int j=0;j<v[i].size();j++){
				cout<<"? "<<v[i][j]<<'\n';
				fflush(stdout);
				for(int k=1;k<=n;k++){
					int x;cin>>x;
					if(x==1) ans.push_back(make_pair(k,v[i][j]));
				}
			}
		}
		cout<<"!"<<'\n';
		fflush(stdout);
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<' '<<ans[i].second<<'\n';
			fflush(stdout);
		}
	}
	else{
		for(int i=1;i<=n;i++) if(dist[i]==1){
			ans.push_back(make_pair(1,i));
		}
		for(int i=2;i<=n;i+=2){
			for(int j=0;j<v[i].size();j++){
				cout<<"? "<<v[i][j]<<'\n';
				fflush(stdout);
				for(int k=1;k<=n;k++){
					int x;cin>>x;
					if(x==1) ans.push_back(make_pair(k,v[i][j]));
				}
			}
		}
		cout<<"!"<<'\n';
		fflush(stdout);
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].first<<' '<<ans[i].second<<'\n';
			fflush(stdout);
		}
	}
	return 0;
}