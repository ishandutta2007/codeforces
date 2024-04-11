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

int vis[10][10];
char c[10][10];

signed main()
{
	ios::sync_with_stdio(false);
	int h,w;cin>>h>>w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>c[i][j];
		}
	}
	int x=1,y=1,cnt=0;
	if(c[x][y]=='*') cnt++;
	while(!(x==h&&y==w)){
		if(y<w&&c[x][y+1]=='*'){
			y++;cnt++; 
		}
		else if(x<h&&c[x+1][y]=='*'){
			x++;cnt++;
		}
		else if(y<w) y++;
		else x++;
	}
	cout<<cnt<<endl;
	return 0;
}