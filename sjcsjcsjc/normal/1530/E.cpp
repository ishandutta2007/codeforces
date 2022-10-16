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

int num[30];

signed main()
{
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		for(int i=1;i<=26;i++) num[i]=0;
		for(int i=0;i<s.size();i++) num[s[i]-'a'+1]++;
		int cnt=0;
		for(int i=1;i<=26;i++) cnt+=(num[i]>0);
		if(cnt==1){
			cout<<s<<'\n';
			continue;
		}
		bool flag=false;
		for(int i=1;i<=26;i++) if(num[i]==1){
			cout<<char('a'+i-1);
			for(int j=1;j<=26;j++) if(j!=i){
				for(int k=1;k<=num[j];k++) cout<<char('a'+j-1);
			}
			cout<<'\n';
			flag=true;
			break;
		}
		if(flag) continue;
		int pos=0;
		for(int i=1;i<=26;i++) if(num[i]>0){
			pos=i;break;
		}
		if(s.size()-num[pos]>=num[pos]-2){
			int now=num[pos]-2;
			cout<<char('a'+pos-1)<<char('a'+pos-1);
			for(int i=pos+1;i<=26;i++){
				for(int k=1;k<=num[i];k++){
					cout<<char('a'+i-1);
					if(now) cout<<char('a'+pos-1),now--;
				}
			}
			cout<<'\n';
			continue;
		}
		if(cnt>2){
			int pos1=0,pos2=0;
			for(int i=pos+1;i<=26;i++) if(num[i]>0){
				pos1=i;break;
			}
			for(int i=pos1+1;i<=26;i++) if(num[i]>0){
				pos2=i;break;
			}
			cout<<char('a'+pos-1)<<char('a'+pos1-1);
			for(int i=1;i<=num[pos]-1;i++) cout<<char('a'+pos-1);
			cout<<char('a'+pos2-1);
			for(int i=pos+1;i<=26;i++){
				for(int k=1;k<=num[i];k++){
					if(k==num[i]&&(i==pos1||i==pos2)) break;
					cout<<char('a'+i-1);
				}
			}
			cout<<'\n';
			continue;
		}
		cout<<char('a'+pos-1);
		for(int i=pos+1;i<=26;i++){
			for(int k=1;k<=num[i];k++){
				cout<<char('a'+i-1);
			}
		}
		for(int i=1;i<=num[pos]-1;i++) cout<<char('a'+pos-1);
		cout<<'\n';
	}
	return 0;
}