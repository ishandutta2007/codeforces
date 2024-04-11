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

int t[100010],x[100010];
bool vis[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int cases;
	cin>>cases;
	while(cases--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) cin>>t[i]>>x[i];
		int now=0,pre=0,pos=0,id=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(abs(pos-now)<=t[i]-pre){
				vis[id]=1;now=pos;pre=t[i];pos=x[i];id=i;
			}
			else{
				if(now<pos){
					if(x[i]>=now&&x[i]<=pos){
						int cur1=now+(t[i]-pre);
						if(x[i]>=cur1){
							if(i+1>n) cnt++;
							else{
								int cur2=now+(t[i+1]-pre);
								if(x[i]<=cur2){
									cnt++;
								}
							}
						}
					}
				}
				else{
					if(x[i]<=now&&x[i]>=pos){
						int cur1=now-(t[i]-pre);
						if(x[i]<=cur1){
							if(i+1>n) cnt++;
							else{
								int cur2=now-(t[i+1]-pre);
								if(x[i]>=cur2){
									cnt++;
								}
							}
						}
					}
				}
			}
		}
		vis[id]=1;
		for(int i=1;i<n;i++) if(vis[i]&&vis[i+1]) cnt++;
		if(vis[n]) cnt++;
		cout<<cnt<<'\n';
	}
	return 0;
}