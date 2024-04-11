#include <bits/stdc++.h>
using namespace std;
int T;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>s;
		map<int,int>mp;
		long long ans=0;
		for(int i=0;i<s.size();i++){
			mp[s[i]-'a']++;
		}
		for(int i=0;i<=26;i++){
			if(mp[i]>=2){
				ans+=2;
			}else if(mp[i]==1){
				ans++;
			}
		}
		cout<<ans/2<<endl;
	}
}