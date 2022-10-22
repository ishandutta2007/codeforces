#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

string s;
int n;
vector<pair<int,int>>v;
const int B=100;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;++i){
		v.emplace_back(i,min(i+B,n));
		for(int k=1;2*k<=B+5;++k){
			if(i+2*k<n&&s[i]==s[i+k]&&s[i]==s[i+k+k])
				v.emplace_back(i,i+2*k);
		}
	}
	sort(v.rbegin(),v.rend());
	int ptr=0;
	set<int>st;
	int mn=1e9;
	nagai ans=0;
	for(int l=n-1;l>=0;--l){
		while(ptr<v.size()&&v[ptr].first==l){
			mn=min(mn,v[ptr].second);
			++ptr;
		}
		ans+=n-mn;
	}
	cout<<ans<<'\n';
	return 0;
}