#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	string s;
	cin>>n>>k>>s;
	string ans;
	int cnt=0;
	while(true){
		int ii=0;
		for(int i=0;i<s.size()&&i<=ans.size();++i)
			if(ans.substr(ans.size()-i)==s.substr(0,i))
				ii=i;
		ans.push_back(s[ii]);
		if(ans.size()>=s.size()&&ans.substr(ans.size()-s.size())==s)
			++cnt;
		if(cnt==k)
			break;
	}
	cout<<ans<<'\n';
	return 0;
}