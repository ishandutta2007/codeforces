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

int n,a[300010],b[300010];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<=3*n+5;i++) a[i]=b[i]=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		sort(a+1,a+n+1);reverse(a+1,a+n+1);
		sort(b+1,b+n+1);reverse(b+1,b+n+1);
		int val1=0,val2=0;
		for(int i=1;i<=n-n/4;i++) val1+=a[i],val2+=b[i];
		int id1=n-n/4,id2=n-n/4+1;
		for(int i=n;;i++){
			if(val1>=val2){
				cout<<i-n<<'\n';
				break;
			}
			val1=val1+100-a[id1],id1--;
			int now=(i+1)-(i+1)/4-(i-i/4);
			if(now==1){
				id1++,val1+=a[id1];
				val2+=b[id2],id2++;
			}
		}
	}
	return 0;
}