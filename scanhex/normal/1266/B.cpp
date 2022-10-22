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
		 nagai x;
		 cin>>x;
		 if(x%14<=6&&x%14!=0&&x>=14)
			 cout<<"YES\n";
		 else
			 cout<<"NO\n";
	}
	return 0;
}