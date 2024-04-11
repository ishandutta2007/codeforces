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

int a[200010],b[200010],vis[200010],ok[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) a[i]=0,b[i]=0,vis[i]=0,ok[i]=0;
		for(int i=1;i<=n;i++) cin>>b[i];
		int k=0;
		for(int i=1;i<=n;i++){
			if(!vis[b[i]]) k++,a[i]=b[i],vis[b[i]]=1;
		}
		if(k==n-1){
			int pos1=0,pos2=0;
			for(int i=1;i<=n;i++) if(!a[i]){
				pos1=i;break;
			}
			for(int i=1;i<=n;i++) if(!vis[i]){
				pos2=i;break;
			}
			a[pos1]=pos2;
			if(pos1==pos2){
				int pos3=0;
				for(int i=1;i<=n;i++) if(i!=pos1&&b[i]==b[pos1]){
					pos3=i;break;
				}
				swap(a[pos1],a[pos3]);
			}
			cout<<k<<'\n';
			for(int i=1;i<=n;i++) cout<<a[i]<<' ';
			cout<<'\n';
			continue;
		}
		vector<int> v1,v2,v3;
		for(int i=1;i<=n;i++) if(!a[i]) v1.push_back(i);
		for(int i=1;i<=n;i++) if(!vis[i]) v2.push_back(i);
		for(int i=0;i<v1.size();i++) ok[v1[i]]++,ok[v2[i]]++;
		for(int i=0;i<v1.size();i++) if(ok[v1[i]]==2) v3.push_back(v1[i]);
		if(v3.size()==1){
			int pos=0;
			for(int i=0;i<v2.size();i++) if(v3[0]!=v2[i]){
				pos=i;break;
			}
			a[v3[0]]=v2[pos];
			int pre=0;
			for(int i=0;i<v1.size();i++) if(ok[v1[i]]<2){
				if(pre==pos) pre++;
				a[v1[i]]=v2[pre];pre++;
			}
			cout<<k<<'\n';
			for(int i=1;i<=n;i++) cout<<a[i]<<' ';
			cout<<'\n';
			continue;
		}
		int pre=0;
		for(int i=0;i<v1.size();i++) if(ok[v1[i]]<2){
			while(ok[v2[pre]]==2) pre++;
			a[v1[i]]=v2[pre];pre++;
		}
		int now=1;
		for(int i=0;i<v1.size();i++) if(ok[v1[i]]==2){
			a[v1[i]]=v3[now];
			now=(now+1)%v3.size();
		}
		cout<<k<<'\n';
		for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}