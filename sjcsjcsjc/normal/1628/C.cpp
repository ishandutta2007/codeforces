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

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int n,a[1010][1010];
bool vis[1010][1010]; 

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) cin>>a[i][j],vis[i][j]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int cnt=0;
				for(int dir=0;dir<4;dir++){
					int x=i+dx[dir],y=j+dy[dir];
					if(x<=0||y<=0||x>n||y>n) continue;
					if(vis[x][y]) cnt++;
				}
				if(cnt==0){
					for(int dir=0;dir<4;dir++){
						int x=i+dx[dir],y=j+dy[dir];
						if(x<=0||y<=0||x>n||y>n) continue;
						vis[x][y]=1;
					}
					ans^=a[i][j];
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}