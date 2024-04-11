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

bool vis[100010];
string s[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>s[i];
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(s[i].size()==1){
				flag=true;break;
			}
			if(s[i].size()==2){
				if(s[i][0]==s[i][1]){
					flag=true;break;
				}
			}
			if(s[i].size()==3){
				if(s[i][0]==s[i][2]){
					flag=true;break;
				}
			}
		}
		if(flag){
			cout<<"YES\n";
			continue;
		}
		for(int i=n;i>=1;i--){
			if(s[i].size()==2){
				int val1=(s[i][1]-'a'+1)*30+(s[i][0]-'a'+1);
				if(vis[val1]){
					flag=true;break;
				}
				for(int j=1;j<=26;j++){
					int val2=j*30*30+(s[i][1]-'a'+1)*30+(s[i][0]-'a'+1);
					if(vis[val2]){
						flag=true;break;
					}
				}
				if(flag) break;
				int val=(s[i][0]-'a'+1)*30+(s[i][1]-'a'+1);
				vis[val]=1;
			}
			if(s[i].size()==3){
				int val1=(s[i][2]-'a'+1)*30*30+(s[i][1]-'a'+1)*30+(s[i][0]-'a'+1);
				if(vis[val1]){
					flag=true;break;
				}
				int val2=(s[i][1]-'a'+1)*30+(s[i][0]-'a'+1);
				if(vis[val2]){
					flag=true;break;
				}
				int val=(s[i][0]-'a'+1)*30*30+(s[i][1]-'a'+1)*30+(s[i][2]-'a'+1);
				vis[val]=1;
			}
		}
		if(flag){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
		for(int i=1;i<=n;i++){
			if(s[i].size()==2){
				int val=(s[i][0]-'a'+1)*30+(s[i][1]-'a'+1);
				vis[val]=0;
			}
			if(s[i].size()==3){
				int val=(s[i][0]-'a'+1)*30*30+(s[i][1]-'a'+1)*30+(s[i][2]-'a'+1);
				vis[val]=0;
			}
		}
	}
	return 0;
}