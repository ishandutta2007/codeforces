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
		vector<int>a(n);
		set<int>st;
		for(auto&x:a)
			cin>>x,st.insert(x%2);
		if(st.size()==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}