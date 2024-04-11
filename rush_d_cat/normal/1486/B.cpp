#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> x(n),y(n);
		for(int i=0;i<n;i++) cin>>x[i]>>y[i];
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		LL ans=1;
		if(x.size()%2==0) {
			ans = ans*(1LL * x[x.size()/2] - x[x.size()/2 - 1] + 1);
		}
		if(y.size()%2==0) {
			ans = ans*(1LL * y[y.size()/2] - y[y.size()/2 - 1] + 1);
		}
		cout<<ans<<endl;
	}
}