#include <bits/stdc++.h>

using namespace std;

const int kN = 2e5 + 7;

int p[kN], c[kN];
bool vis[kN];

vector<int> dfs(int u){
	vis[u] = true;

	if(vis[p[u]])
		return {u};

	vector<int> curr = dfs(p[u]);
	curr.push_back(u);
	return curr;
}

bool check(const vector<int> &v, int diff){
	for(int i = 0; i < diff; ++i){
		bool ok = true;
		for(int j = i + diff; j < v.size(); j += diff){
			if(c[v[i]] != c[v[j]]){
				ok = false;
				break;
			}
		}
		if(ok)
			return true;
	}
	return false;
}

void solve(){
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i)
		cin >> p[i];
	for(int i = 1; i <= n; ++i)
		cin >> c[i];

	for(int i = 1; i <= n; ++i)
		vis[i] = false;

	int min_cycle = n;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			vector<int> cycle = dfs(i);

			int x = cycle.size();
			for(int j = 1; j * j <= x; ++j){
				if(x % j == 0){
					if(check(cycle, j)){
						min_cycle = min(min_cycle, j);
						break;
					}
					if(check(cycle, x / j))
						min_cycle = min(min_cycle, x / j);
				}
			}
		}
	}

	cout << min_cycle << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();

	return 0;
}