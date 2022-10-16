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

int a[100010];

inline int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		set<pair<int,int> > s1,s2;
		vector<int> ans;
		for(int i=1;i<=n;i++) s1.insert(make_pair(i,a[i]));
		for(int i=1;i<n;i++) s2.insert(make_pair(gcd(a[i],a[i+1]),i));
		s2.insert(make_pair(gcd(a[n],a[1]),n));
		int now=1;
		while(s1.size()>1){
			set<pair<int,int> >::iterator it=s2.lower_bound(make_pair(1,now));
			if(it==s2.end()||(it->first)!=1){
				if(now==(s1.begin()->first)) break;
				now=(s1.begin()->first);
			}
			else{
				set<pair<int,int> >::iterator it2=s1.lower_bound(make_pair((it->second),0)),it3,it4;
				it3=it2;it3++;
				if(it3==s1.end()) it3=s1.begin();
				it4=it3;it4++;
				if(it4==s1.end()) it4=s1.begin();
				ans.push_back((it3->first));
				s2.erase(s2.find(make_pair(gcd((it3->second),(it4->second)),(it3->first))));
				s1.erase(it3);
				s2.erase(it);
				s2.insert(make_pair(gcd((it2->second),(it4->second)),(it2->first)));
				now=(it4->first);
			}
		}
		if(s1.size()==1&&(s1.begin()->second)==1) ans.push_back(s1.begin()->first);
		cout<<ans.size()<<" ";
		for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}