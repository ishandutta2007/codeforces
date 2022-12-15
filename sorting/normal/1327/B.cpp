#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vector<vector<int>> kings(n + 1);
		vector<bool> used(n + 1, false);
		for(int i = 1; i <= n; ++i){
			int sz;
			cin >> sz;

			if(sz)
				kings[i].resize(sz);
			for(int j = 0; j < sz; ++j)
				cin >> kings[i][j];
		}

		int idx_not_found = -1;
		for(int i = 1; i <= n; ++i){
			if(kings[i].empty()){
				idx_not_found = i;
				continue;
			}

			sort(kings[i].begin(), kings[i].end());
			int choice = -1;
			for(int x: kings[i]){
				if(!used[x]){
					choice = x;
					break;
				}
			}

			if(choice != -1){
				used[choice] = true;
				continue;
			}
			else
				idx_not_found = i;
		}

		if(idx_not_found == -1){
			cout << "OPTIMAL\n";
			continue;
		}

		cout << "IMPROVE\n";
		for(int i = 1; i <= n; ++i)
			if(!used[i]){
				cout << idx_not_found << " " << i << "\n";
				break;
			}
	}
}