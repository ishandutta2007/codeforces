#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<nagai,nagai>>a(n);
	vector<nagai>b(n);
	for(auto&x:a)cin>>x.first;
	for(auto&x:a)cin>>x.second;
	sort(a.begin(),a.end());
	multiset<nagai>nums;
	nagai ans=0;
	map<nagai,vector<nagai>>v;
	for(auto&x:a)
		v[x.first].push_back(x.second);
	v[(int)1.5e9];
	int last=-1e9;
	nagai sm=0;
	for(auto [x,y]:v){
		for(int i=last;i<x;++i){
			if(nums.size()){
				sm-=*prev(nums.end());
				nums.erase(prev(nums.end()));
			}
			else
				break;
			ans+=sm;
		}
		for(auto x:y)
			nums.insert(x),sm+=x;
		last=x;
	}
	cout<<ans<<'\n';
	return 0;
}