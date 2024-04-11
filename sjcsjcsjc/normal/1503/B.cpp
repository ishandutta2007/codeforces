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

vector<pair<int,int> > v1,v2;

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((i+j)%2==0) v1.push_back(make_pair(i,j));
			else v2.push_back(make_pair(i,j));
		}
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n*n;i++){
		int x;cin>>x;
		if(cnt1==v1.size()){
			if(x==1){
				cout<<2<<" "<<v2[cnt2].first<<" "<<v2[cnt2].second<<"\n";
				fflush(stdout);
				cnt2++;
			}
			if(x==2){
				cout<<3<<" "<<v2[cnt2].first<<" "<<v2[cnt2].second<<"\n";
				fflush(stdout);
				cnt2++;
			}
			if(x==3){
				cout<<2<<" "<<v2[cnt2].first<<" "<<v2[cnt2].second<<"\n";
				fflush(stdout);
				cnt2++;
			}
		}
		else if(cnt2==v2.size()){
			if(x==1){
				cout<<3<<" "<<v1[cnt1].first<<" "<<v1[cnt1].second<<"\n";
				fflush(stdout);
				cnt1++;
			}
			if(x==2){
				cout<<1<<" "<<v1[cnt1].first<<" "<<v1[cnt1].second<<"\n";
				fflush(stdout);
				cnt1++;
			}
			if(x==3){
				cout<<1<<" "<<v1[cnt1].first<<" "<<v1[cnt1].second<<"\n";
				fflush(stdout);
				cnt1++;
			}
		}
		else{
			if(x==1){
				cout<<2<<" "<<v2[cnt2].first<<" "<<v2[cnt2].second<<"\n";
				fflush(stdout);
				cnt2++;
			}
			if(x==2){
				cout<<1<<" "<<v1[cnt1].first<<" "<<v1[cnt1].second<<"\n";
				fflush(stdout);
				cnt1++;
			}
			if(x==3){
				cout<<1<<" "<<v1[cnt1].first<<" "<<v1[cnt1].second<<"\n";
				fflush(stdout);
				cnt1++;
			}
		}
	}
	return 0;
}