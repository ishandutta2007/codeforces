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
		string s;
		cin>>s;
		int last=-1;
		int ansich=-1;
		int n=s.size();
		for(int i=0;i<n;++i){
			 if(s[i]=='R'){
				 ansich=max(ansich,i-last);
				 last=i;
			 }
		}
		ansich=max(ansich,n-last);
		cout<<ansich<<'\n';

	}
	return 0;
}