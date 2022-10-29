#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve(){
	
	int n, m; cin >> n >> m;
	vector<int> row(m);
	vector<int> col(n);
	int cntc = 0;
	int cntr = 0;
	vector<pair<int,int>> inter;
	for(int i = 0; i < n; ++i){
		inter.push_back(make_pair(-1,-1));
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char tmp; cin >> tmp;
			if(tmp == '.'){
				if(col[i] == 1){
					col[i] = 2;
				}
				if(row[j] == 1){
					row[j] = 2;
				}
			}
			else{
				if(row[j] == 2 || col[i] == 2){
					cout << "-1\n";
					return;
				}
				if(col[i] == 0){
					inter[i].first = j;
				} 
				inter[i].second = j;
				row[j] = 1;
				col[i] = 1;
			}

		}
		if(col[i] == 0){
			cntc++;
		}
	}
	for(int i = 0; i < m; ++i){
		if(row[i] == 0){
			cntr++;
		}
	}
	if((cntr != 0 && cntc == 0)||(cntr == 0 && cntc != 0)){
		cout << "-1\n";
		return;
	}
			
	int ans = 0;
	pair<int,int> curr = make_pair(-1,-1);
	for(int i = 0; i < n; ++i){
		if(curr.first > inter[i].second || curr.second < inter[i].first){
			if(inter[i].first != -1){
				ans++;
			}
		}
		curr.first = inter[i].first;
		curr.second = inter[i].second;
	}
	cout << ans <<"\n";
		
	
	
	return;
}

int main(){
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	
	solve();
		
	return 0;
}