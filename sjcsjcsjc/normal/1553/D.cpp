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

int nxt[100010][30];

signed main()
{
	ios::sync_with_stdio(false);
	int cases;cin>>cases;
	while(cases--){
		string s,t;cin>>s>>t;
		s+='{';t+='{';
		for(int i=1;i<=27;i++) nxt[s.size()+2][i]=nxt[s.size()+1][i]=-1;
		for(int i=s.size();i>=1;i--){
			for(int j=1;j<=27;j++) nxt[i][j]=nxt[i+2][j];
			nxt[i][s[i-1]-'a'+1]=i;
		}
		bool flag=false;
		int now=nxt[1][t[0]-'a'+1];
		for(int i=2;i<=t.size();i++){
			if(now==-1) break;
			now=nxt[now+1][t[i-1]-'a'+1];
		}
		if(now!=-1) flag=true;
		now=nxt[2][t[0]-'a'+1];
		for(int i=2;i<=t.size();i++){
			if(now==-1) break;
			now=nxt[now+1][t[i-1]-'a'+1];
		}
		if(now!=-1) flag=true;
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}