#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define INF 1000000007
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

int n,a[400010],b[400010],pos[400010],val[400010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]<=n&&b[i]<=n){
			flag=false;
		}
	}
	if(!flag){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=n) pos[a[i]]=b[i],val[a[i]]=0;
		else pos[b[i]]=a[i],val[b[i]]=1;
	}
	int now=INF;
	vector<int> v;
	for(int i=1;i<=n;i++){
		if(pos[i]<now){
			now=pos[i];
		}
		else v.push_back(pos[i]);
	}
	if(!v.empty()){
		for(int i=0;i<v.size()-1;i++){
			if(v[i]<v[i+1]){
				flag=false;break;
			}
		}
	}
	if(!flag){
		cout<<-1<<endl;
		return 0;
	}
	int minv=2*n,ans=0,noww=INF,cnt=0,pre=0;
	for(int i=1;i<=n;i++){
		minv=min(minv,pos[i]);
		if(pos[i]<noww){
			noww=pos[i];cnt+=val[i];
		}
		else{
			cnt+=val[i]^1;
		}
		if(2*n-minv+1==i){
			ans+=min(cnt,i-pre-cnt);
			cnt=0;pre=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}