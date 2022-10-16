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

int a[100010],l[100010],r[100010],cnt[100010];

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> v;
	for(int i=2;i<n;i++){
		if(a[i]>a[i-1]&&a[i]>a[i+1]){
			v.push_back(i);
		}
	}
	int mx=0;
	for(int i=0;i<v.size();i++){
		int pos1=1;
		for(int j=v[i]-1;j>=1;j--){
			if(a[j]>a[j+1]){
				pos1=j+1;break; 
			}
		}
		l[i+1]=v[i]-pos1+1;
		mx=max(mx,l[i+1]);
		cnt[l[i+1]]++;
		int pos2=n;
		for(int j=v[i]+1;j<=n;j++){
			if(a[j]>a[j-1]){
				pos2=j-1;break;
			}
		}
		r[i+1]=pos2-v[i]+1;
		mx=max(mx,r[i+1]);
		cnt[r[i+1]]++;
	}
	int pos1=n;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			pos1=i-1;break;
		}
	}
	mx=max(mx,pos1);
	cnt[pos1]++;
	int pos2=1;
	for(int i=n-1;i>=1;i--){
		if(a[i]>a[i+1]){
			pos2=i+1;break;
		}
	}
	mx=max(mx,n-pos2+1);
	cnt[n-pos2+1]++;
	int ans=0;
	for(int i=0;i<v.size();i++){
		if(l[i+1]<3) continue;
		if(r[i+1]<3) continue;
		int maxv=max(l[i+1],r[i+1]);
		if(maxv<mx) continue;
		if(l[i+1]!=r[i+1]) continue;
		if(l[i+1]==r[i+1]){
			if(cnt[mx]>2) continue;
			if(l[i+1]%2==1) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}