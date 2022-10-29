#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(int testNum){
	int n, m; cin >> n >> m;
	string s; cin >> s;
	vector<int> v(m,0);
	vector<int> v2(m,0);
	int ans = 0;
	int ls = 0;
	for(int i = 0; i < n*m; ++i){
		if(s[i] == '1'){
			if(!v2[i%m]){
				v2[i%m] = 1;
				ans++;
			}
			for(int j = ls; j < m; ++j){
				v[(i+j)%m]++;
			}
			ls = m;
		}
		cout << ans + v[i%m] << ' ';
		ls--;
		ls = max(ls,0);
	}
	cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//solve(0);return 0;
	int t; cin >> t;
	int cn = 1;
	while(t--){
		solve(cn++);
	}
}