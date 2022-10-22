#include <bits/stdc++.h>

using namespace std;
using nagai=long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>a(n),b(n);
		for(auto&x:a)
			cin>>x;
		for(auto&x:b)
			cin>>x;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(auto&x:a)
			cout<<x<<' ';
		cout<<'\n'; 
		for(auto&x:b)
			cout<<x<<' ';
		cout<<'\n'; 
	}

	return 0;
}