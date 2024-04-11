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

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		int ans=10;
		string s1=s,s2=s;
		for(int i=0;i<10;i++){
			if(s[i]=='?'){
				if(i%2==0) s1[i]='0';
				else s1[i]='1';
			}
		}
		int val0=0,val1=0,rem0=5,rem1=5;
		for(int i=0;i<10;i++){
			if(i%2==0){
				if(s1[i]=='1') val0++;
				rem0--;	
			}
			else{
				if(s1[i]=='1') val1++;
				rem1--;
			}
			if(val0+rem0<val1){
				ans=min(ans,i+1);
				break; 
			}
			if(val1+rem1<val0){
				ans=min(ans,i+1);
				break;
			}
		}
		for(int i=0;i<10;i++){
			if(s[i]=='?'){
				if(i%2==1) s2[i]='0';
				else s2[i]='1';
			} 
		}
		val0=0,val1=0,rem0=5,rem1=5;
		for(int i=0;i<10;i++){
			if(i%2==0){
				if(s2[i]=='1') val0++;
				rem0--;	
			}
			else{
				if(s2[i]=='1') val1++;
				rem1--;
			}
			if(val0+rem0<val1){
				ans=min(ans,i+1);
				break; 
			}
			if(val1+rem1<val0){
				ans=min(ans,i+1);
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}