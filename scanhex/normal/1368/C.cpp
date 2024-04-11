#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>>v;
	v.emplace_back(0,0);
	v.emplace_back(0,1);
	v.emplace_back(1,0);
	v.emplace_back(1,1);
	for(int i=0;i<n;++i){
		v.emplace_back(2+i,1+i);
		v.emplace_back(1+i,2+i);
		v.emplace_back(2+i,2+i);
	}
	cout << v.size() << '\n';
	for(auto&x:v)
		cout << x.first << ' ' <<x.second << '\n';
	return 0;
}