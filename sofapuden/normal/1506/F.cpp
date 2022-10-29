#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<array<int,2>> rc(n);
		for(auto &x : rc)cin >> x[0];
		for(auto &x : rc)cin >> x[1];
		sort(rc.begin(),rc.end());
		int ans = 0;
		int lsx = 1, lsy = 1;
		for(int i = 0; i < n; ++i){
			int ri = rc[i][1]-lsy;
			int le = rc[i][0]-lsx-ri;

			if((lsx+lsy)&1)ri = 0;
			else if(le){
				le--, ri = 0;
			}
			ans+=ri+((le+1)>>1);
			lsx = rc[i][0];
			lsy = rc[i][1];
		}
		cout << ans << "\n";
		
	}
}