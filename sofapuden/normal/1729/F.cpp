#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){
	string s; cin >> s;
	int n = s.size();
	int w, m; cin >> w >> m;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)v[i] = s[i]-'0';
	vector<int> pre(n);
	pre[0] = v[0];
	for(int i = 1; i < n; ++i){
		pre[i] = pre[i-1] + v[i];
	}
	vector<vector<int>> L(9);
	for(int i = 0; i < n; ++i){
		if(i+w-1 >= n)break;
		if(L[(pre[i + w - 1] - (i ? pre[i-1] : 0))%9].size() > 1)continue;
		L[(pre[i + w - 1]  - (i ? pre[i-1] : 0))%9].push_back(i);
	}
	while(m--){
		pair<int,int> bes = {-2,-2};
		int l, r, k; cin >> l >> r >> k;
		int su = pre[r-1] - (l == 1 ? 0 : pre[l-2]);
		su%=9;
		for(int i = 0; i < 9; ++i){
			if(!L[i].size())continue;
			int x = L[i][0];
			for(int j = 0; j < 9; ++j){
				if(!L[j].size() || (j == i && L[j].size() != 2))continue;
				int y;
				if(j == i)y = L[j][1];
				else y = L[j][0];
				if((su*i+j)%9 == k){
					if(bes == make_pair(-2,-2))bes = {x,y};
					else bes = min(bes,{x,y});
				}
			}
		}
		cout << bes.first+1 << ' ' << bes.second+1 << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}