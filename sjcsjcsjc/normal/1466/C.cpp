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

string s;

inline bool check(int x,int pos)
{
	if(pos<0||pos>=s.size()) return true;
	if(x==s[pos]-'a'+1) return false;
	else return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int cnt=0; 
		for(int i=0;i<s.size();i++){
			if(i>0&&s[i]==s[i-1]){
				cnt++;
				int now=0;
				for(int j=1;j<=26;j++){
					if(check(j,i-2)&&check(j,i-1)&&check(j,i+1)&&check(j,i+2)){
						now=j;break;
					}
				}
				s[i]=char(now+'a'-1);
			}
			if(i>1&&s[i]==s[i-2]){
				cnt++;
				int now=0;
				for(int j=1;j<=26;j++){
					if(check(j,i-2)&&check(j,i-1)&&check(j,i+1)&&check(j,i+2)){
						now=j;break;
					}
				}
				s[i]=char(now+'a'-1);
			}
		}
		cout<<cnt<<'\n';
	}	
	return 0;
}