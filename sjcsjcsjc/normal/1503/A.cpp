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

char c[200010],a[200010],b[200010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		int cnt=0;
		for(int i=1;i<=n;i++) cin>>c[i],cnt+=(c[i]=='1');
		if(c[1]=='0'||c[n]=='0') cout<<"NO\n";
		else if(cnt%2==1) cout<<"NO\n";
		else{
			cout<<"YES\n";
			int now1=0,now2=0;
			for(int i=1;i<=n;i++){
				if(c[i]=='1'){
					now1++;
					if(now1<=cnt/2){
						a[i]='(';b[i]='(';
					}
					else{
						a[i]=')';b[i]=')';
					}
				}
				else{
					now2++;
					if(now2%2==1){
						a[i]='(';b[i]=')';
					}
					else{
						a[i]=')';b[i]='(';
					}
				}
			}
			for(int i=1;i<=n;i++) cout<<a[i];
			cout<<'\n';
			for(int i=1;i<=n;i++) cout<<b[i];
			cout<<'\n';
		}
	}
	return 0;
}