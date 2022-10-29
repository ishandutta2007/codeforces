#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n, m; cin >> n >> m;
	
	set<int> s;
	
	for(int i = 0; i < n; ++i){
		int tmp1, tmp2;cin >> tmp1 >> tmp2;
		for(int j = tmp1; j <= tmp2; ++j){
			s.insert(j);
		}
	}
	cout << abs((int)size(s)-m) << "\n";
	for(int i = 1; i <= m; ++i){
		if(!s.count(i)){
			cout << i << " ";
		}
	}					
}

int main(){
	solve();	
}