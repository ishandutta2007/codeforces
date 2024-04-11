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
		set<int>st;
		int n;
		cin>>n;
		vector<int>a(n);
		bool ok=false;
		for(int i=0;i<n;++i)
		{
			 cin>>a[i];
			 if(st.count(a[i]))
				 ok=true;
			 if(i>0)
				 st.insert(a[i-1]);
		}
		if(ok)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}