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

int a[200010],b[200010],val[200010],num1[200010],num2[200010];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		for(int i=0;i<=n;i++) val[i]=0,num1[i]=0,num2[i]=0;
		vector<pair<int,int> > v1,v2;
		int cnt=1;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]){
				v1.push_back(make_pair(a[i-1],cnt));
				cnt=1;
			}
			else cnt++;
		}
		v1.push_back(make_pair(a[n],cnt));
		cnt=1;
		for(int i=2;i<=n;i++){
			if(b[i]!=b[i-1]){
				v2.push_back(make_pair(b[i-1],cnt));
				cnt=1;
			}
			else cnt++;
		}
		v2.push_back(make_pair(b[n],cnt));
		int pos=v1.size()-1;
		bool flag=true;
		for(int i=v2.size()-1;i>=0;i--){
			while(pos>0&&v1[pos].first!=v2[i].first){
				val[pos]=0;pos--;
			}
			if(pos==-1||v1[pos].first!=v2[i].first){
				flag=false;break;
			}
			val[pos]=v2[i].second;pos--;
		}
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		for(int i=0;i<v1.size();i++){
			num1[v1[i].first]+=val[i];
			num2[v1[i].first]+=v1[i].second;
			if(num1[v1[i].first]>num2[v1[i].first]){
				flag=false;break;
			}
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}