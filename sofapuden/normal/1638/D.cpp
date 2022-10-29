#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
int n, m;
vector<array<int,3>> ou;

int col(int i, int j){
	int cur = -1;
	for(int _i = i; _i < i+2; ++_i){
		for(int _j = j; _j < j+2; ++_j){
			if(v[_i][_j] != -1){
				if(cur == -1)cur = v[_i][_j];
				else if(cur != v[_i][_j])return 0;
			}
		}
	}
	for(int _i = i; _i < i+2; ++_i){
		for(int _j = j; _j < j+2; ++_j){
			v[_i][_j] = -1;
		}
	}
	return cur;
}

void fin(int i, int j){
	if(i >= 0 && j >= 0 && i < n-1 && j < m-1){
		int x = col(i,j);
		if(x <= 0)return;
		ou.push_back({i,j,x});
		for(int _i = i-1; _i < i+2; _i++){
			for(int _j = j-1; _j < j+2; _j++){
				fin(_i,_j);
			}
		}
	}

}



int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	v.resize(n,vector<int>(m));
	for(auto &x : v)for(auto &y : x)cin >> y;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			fin(i,j);
		}
	}
	bool ok = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(v[i][j] != -1){
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ou.size() << '\n';
	reverse(ou.begin(),ou.end());
	for(auto x : ou)cout << x[0]+1 << ' ' << x[1]+1 << ' ' << x[2] << '\n';
}