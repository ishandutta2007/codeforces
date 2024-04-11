#include<bits/stdc++.h>

using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		map<int,int> M;
		M[0]++;
		for(int i = 0; i < n-1; ++i){
			int x; cin >> x;
			M[x]++;
		}
		vector<int> res;
		for(auto x : M)res.push_back(x.second);
		sort(res.begin(),res.end());
		int ans = 0;
		vector<int> cu;
		for(int i = 0; i < res.size(); ++i){
			res[i]-=i+1;
			if(res[i] > 0)cu.push_back(res[i]);
			ans++;
		}
		while(cu.size()){
			sort(cu.rbegin(),cu.rend());
			cu[0]--;
			ans++;
			vector<int> ne;
			for(int i = 0; i < cu.size(); ++i){
				cu[i]--;
				if(cu[i] > 0)ne.push_back(cu[i]);
			}
			cu = ne;
		}
		cout << ans << '\n';
	}
}