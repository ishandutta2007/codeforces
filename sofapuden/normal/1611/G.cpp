#include<bits/stdc++.h>

using namespace std;

const int STORTTAL = 19203890;

void solve(){
	int n, m; cin >> n >> m;
	vector<string> gr(n);
	for(auto &x : gr)cin >> x;
	if(n == 1){
		int ans = 0;
		for(int i = 0; i < m; ++i)ans+=gr[0][i]-'0';
		cout << ans << '\n';
		return;
	}
	multiset<pair<int,int>> ino; // end , start
	multiset<pair<int,int>> ine; // end , start
	int ans = 0;
	for(int i = 0; i < m; ++i){
		vector<pair<int,int>> rem;
		vector<pair<int,int>> ins;
		for(auto &x : ino){
			rem.push_back(x);
			if(x.first-1 >= x.second+1){
				ins.push_back({x.first-1,x.second+1});
				if(ins.back().second-100 <= -STORTTAL)ins.back().second = -STORTTAL;
				if(ins.back().first+100 >= STORTTAL)ins.back().first = STORTTAL;
			}
		}
		for(auto y : rem)ino.erase(ino.find(y));
		for(auto y : ins)ino.insert(y);

		rem.clear();
		ins.clear();
		for(auto &x : ine){
			rem.push_back(x);
			if(x.first-1 >= x.second+1){
				ins.push_back({x.first-1,x.second+1});
				if(ins.back().second-100 <= -STORTTAL)ins.back().second = -STORTTAL;
				if(ins.back().first+100 >= STORTTAL)ins.back().first = STORTTAL;
			}
		}
		for(auto y : rem)ine.erase(ine.find(y));
		for(auto y : ins)ine.insert(y);


		for(int j = 0; j < n; ++j){
			if(gr[j][i] == '0')continue;
			if((i^j)&1){
				auto x = ino.lower_bound({j-1,STORTTAL});
				if(x == ino.end()){
					ans++;
					ino.insert({j,-STORTTAL});
					ino.insert({STORTTAL,j});
					continue;
				}
				while(x != ino.end() && x->second > j)x++;
				if(x != ino.end()){
					while(next(x) != ino.end() && next(x)->first-next(x)->second <= x->first-x->second && next(x)->second <= j)x = next(x);
					ino.insert({x->first,j});
					ino.insert({j,x->second});
					ino.erase(x);
				}
				else{
					ans++;
					ino.insert({j,-STORTTAL});
					ino.insert({STORTTAL,j});
				}
			}
			else{
				auto x = ine.lower_bound({j-1,STORTTAL});
				if(x == ine.end()){
					ans++;
					ine.insert({j,-STORTTAL});
					ine.insert({STORTTAL,j});
					continue;
				}
				while(x != ine.end() && x->second > j)x++;
				if(x != ine.end()){
					while(next(x) != ine.end() && next(x)->first-next(x)->second <= x->first-x->second && next(x)->second <= j)x = next(x);
					ine.insert({x->first,j});
					ine.insert({j,x->second});
					ine.erase(x);
				}
				else{
					ans++;
					ine.insert({j,-STORTTAL});
					ine.insert({STORTTAL,j});
				}
			}
		}
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)solve();
}