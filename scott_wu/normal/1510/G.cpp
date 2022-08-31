#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> p(n, -1);
	for(int i = 1; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	vector<int> depth(n);
	depth[0] = 0;
	for(int i = 1; i < n; i++){
		depth[i] = depth[p[i]] + 1;
	}
	int best = 0;
	for(int i = 0; i < n; i++){
		if(depth[i] <= k-1){
			if(depth[i] >= depth[best]){
				best = i;
			}
		}
	}
	vector<int> used(n, 0);
	vector<int> res;
	int cur = best;
	while(cur != -1){
		used[cur] = 1;
		res.push_back(cur);
		cur = p[cur];
	}
	reverse(res.begin(), res.end());
	int need = k - (int)res.size();
	for(int i = 0; i < n; i++){
		if(used[i]) continue;
		if(need){
			need--;
			int a = 0;
			while(res[a] != p[i]){
				a++;
			}
			res.insert(res.begin() + a+1, p[i]);
			res.insert(res.begin() + a+1, i);
		}
	}
	cout << ((int)res.size() - 1) << '\n';
	for(int x : res){
		cout << (x+1) << ' ';
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}