#include <bits/stdc++.h>

using namespace std;
using nagai = long long;
#define sz(x) int((x).size())

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int b,k;
	cin>>b>>k;
	int cur=0;
	for(int i=0;i<k;++i){
		 int x;
		 cin>>x;
		 cur*=b;
		 cur+=x;
		 cur%=2;
	}
	if(cur==0)cout<<"even\n";else cout<<"odd\n";
	return 0;
}