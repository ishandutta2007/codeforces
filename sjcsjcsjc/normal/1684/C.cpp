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

int n,m,b[200010],is[200010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<vector<int> > a;a.resize(n+1,vector<int>(m+1,0));
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
		bool flag=true;
		int posx=0,posy=0;
		for(int i=1;i<=n;i++){
			is[i]=0;
			for(int j=1;j<=m;j++) b[j]=a[i][j];
			sort(b+1,b+m+1);
			vector<int> v;
			for(int j=1;j<=m;j++) if(b[j]!=a[i][j]) v.push_back(j);
			if(v.size()>=3){
				flag=false;break;
			}
			else if(v.size()==2){
				if(posx==0&&posy==0) posx=v[0],posy=v[1];
				else if(posx!=v[0]||posy!=v[1]){
					flag=false;break;
				}
			}
			else is[i]=1;
		}
		if(!flag) cout<<-1<<'\n';
		else if(posx!=0&&posy!=0){
			for(int i=1;i<=n;i++){
				if(is[i]){
					if(a[i][posx]!=a[i][posy]){
						flag=false;break;
					}
				}
			}
			if(!flag) cout<<-1<<'\n';
			else cout<<posx<<' '<<posy<<'\n';
		}
		else cout<<1<<' '<<1<<'\n';
	}
	return 0;
}