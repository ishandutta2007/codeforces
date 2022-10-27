#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin>>t;
	while(t--){
		int n;cin>>n;
		LL cnt=0;
		bool ok=true;
		for(int i=0;i<n;i++){
			LL x;cin>>x;
			x+=cnt;
			if(x<i) ok=false;
			else cnt=x-i;
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
}