#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;
const int M = 5e5 + 7;

bool used[N];
pair <int, int> e[M];
vector<int> ans1;

void solve(){
	int n, m;

	cin >> n >> m;

	for(int i = 1; i <= 3 * n; i++){
		used[i] = false;
	}
	ans1.clear();

	for(int i = 0; i < m; i++){
		cin >> e[i].first >> e[i].second;
	}

	int cnt = 0;

	for(int i = 0; i < m && cnt < n; i++){
		if(!used[e[i].first] && !used[e[i].second]){
			cnt++;
			used[e[i].first]++;
			used[e[i].second]++;
			ans1.push_back(i + 1);
		}
	}

	if(cnt == n){
		cout << "Matching\n";
		for(int x: ans1){
			cout << x << " ";
		}
		cout << "\n";
	}
	else{
		cout << "IndSet\n";
		cnt = 0;
		for(int i = 1; i <= 3 * n && cnt < n; i++){
			if(!used[i]){
				cout << i << " ";
				cnt++;
			}
		}
		cout << "\n";
	}

	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;

	while(t--){
		solve();
	}

	return 0;
}