#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 5e5+5;

int main(){
	int n, m; cin >> n >> m;
	vector<pair<int,int>> a(n);
	vector<int> nx(mxN);
	vector<vector<int>> sp(20,vector<int>(n));

	for(auto &x : a)cin >> x.first >> x.second;

	sort(a.begin(), a.end());

	int am = 0;
	pair<int,int> mx = {0,-1};

	for(int i = 0; i < mxN; ++i){
		while(am < n && a[am].first == i){
			mx = max(mx,make_pair(a[am].second,am));
			++am;
		}
		nx[i] = (mx.first <= i ? -1 : mx.second);
	}
	for(int i = 0; i < n; ++i){
		sp[0][i] = nx[a[i].second];
	}
	for(int i = 1; i < 20; ++i){
		for(int j = 0; j < n; ++j){
			if(sp[i-1][j] == -1)sp[i][j] = -1;
			else sp[i][j] = sp[i-1][sp[i-1][j]];
		}
	}
	while(m--){
		int l, r; cin >> l >> r;

		int x = nx[l];
		if(x == -1){
			cout << -1 << '\n';
			continue;
		}

		int ans = 1;
		for(int i = 19; i >= 0; --i){
			int nxt = sp[i][x];
			if(nxt == -1)continue;
			if(a[nxt].second < r){
				ans+=(1<<i);
				x = nxt;
			}
		}
		if(a[x].second >= r){
			cout << ans << '\n';
		}
		else if(sp[0][x] == -1){
			cout << -1 << '\n';
		}
		else{
			cout << ans+1 << '\n';
		}
	}
}