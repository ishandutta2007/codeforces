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

int cnt[3];
string s[3];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;cin>>s[0]>>s[1]>>s[2];
		cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=0;i<2*n;i++){
			cnt[0]+=(s[0][i]=='1');
			cnt[1]+=(s[1][i]=='1');
			cnt[2]+=(s[2][i]=='1'); 
		}
		bool flag=false;
		for(int i=0;i<3&&!flag;i++){
			for(int j=0;j<3&&!flag;j++) if(i!=j){
				if(cnt[i]>=cnt[j]&&2*n-cnt[j]<=n){
					int now=0;
					for(int k=0;k<2*n;k++){
						if(s[i][k]=='1'){
							while(now<2*n&&s[j][now]!='1'){
								cout<<'0';now++;
							}
							now++;
						}
						cout<<s[i][k];
					}
					while(now<2*n) cout<<s[j][now],now++; 
					for(int k=1;k<=n-2*n+cnt[j];k++) cout<<'0';
					flag=true;
				}
				else if(2*n-cnt[i]>=2*n-cnt[j]&&cnt[j]<=n){
					int now=0;
					for(int k=0;k<2*n;k++){
						if(s[i][k]=='0'){
							while(now<2*n&&s[j][now]!='0'){
								cout<<'1';now++;
							}
							now++;
						}
						cout<<s[i][k];
					}
					while(now<2*n) cout<<s[j][now],now++; 
					for(int k=1;k<=n-cnt[j];k++) cout<<'1';
					flag=true;
				}
			}
		}
		cout<<'\n';
	}
	return 0;
}