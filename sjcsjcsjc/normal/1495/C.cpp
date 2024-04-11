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

char c[510][510];
bool ans[510][510];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>c[i][j];
				ans[i][j]=0;
				if(c[i][j]=='X') ans[i][j]=1;
			}
		}
		if(m%3==0){
			for(int i=2;i<=m;i+=3){
				for(int j=1;j<=n;j++) ans[j][i]=1; 
			}
			for(int i=2;i<m-1;i+=3){
				bool flag=false;
				for(int j=1;j<=n;j++){
					if(ans[j][i+1]||ans[j][i+2]){
						ans[j][i+1]=1;ans[j][i+2]=1;flag=true;
						break;
					}
				}
				if(!flag){
					ans[1][i+1]=1;ans[1][i+2]=1;
				}
			}
		}
		else if(m%3==1){
			for(int i=1;i<=m;i+=3){
				for(int j=1;j<=n;j++) ans[j][i]=1;
			}
			for(int i=1;i<m;i+=3){
				bool flag=false;
				for(int j=1;j<=n;j++){
					if(ans[j][i+1]||ans[j][i+2]){
						ans[j][i+1]=1;ans[j][i+2]=1;flag=true;
						break;
					}
				}
				if(!flag){
					ans[1][i+1]=1;ans[1][i+2]=1; 
				}
			}
		}
		else if(m%3==2){
			for(int i=2;i<=m;i+=3){
				for(int j=1;j<=n;j++) ans[j][i]=1;
			}
			for(int i=2;i<m;i+=3){
				bool flag=false;
				for(int j=1;j<=n;j++){
					if(ans[j][i+1]||ans[j][i+2]){
						ans[j][i+1]=1;ans[j][i+2]=1;flag=true;
						break;
					}
				}
				if(!flag){
					ans[1][i+1]=1;ans[1][i+2]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(ans[i][j]) cout<<'X';
				else cout<<'.';
			}
			cout<<'\n';
		}
	}
	return 0;
}