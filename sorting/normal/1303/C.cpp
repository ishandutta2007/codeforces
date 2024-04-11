#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin >> s;

	vector<vector<int>> adj;
	adj.resize(26, vector<int>());
	vector<vector<bool>> edge(26, vector<bool>(26, false));

	for(int i = 0; i < s.size() - 1; ++i){
		edge[s[i] - 'a'][s[i + 1] - 'a'] = true;
		edge[s[i + 1] - 'a'][s[i] - 'a'] = true;
	}

	for(int i = 0; i < 26; ++i){
		for(int j = 0; j < 26; ++j){
			if(edge[i][j])
				adj[i].push_back(j);
		}
	}

	int cnt_end = 0;
	array<int, 2> arr_end;
	for(int i = 0; i < 26; ++i){
		if(adj[i].size() > 2){
			cout << "NO\n";
			return;
		}
		if(adj[i].size() != 2 && cnt_end != 2)
			arr_end[cnt_end++] = i;
	}

	vector<bool> used(26, false);

	string start = "", end = "";

	int curr = arr_end[0], nxt;
	while(true){
		start += curr + 'a';
		used[curr] = true;
		nxt = curr;
		for(int to: adj[curr]){
			if(used[to] || to == arr_end[1])
				continue;
			nxt = to;
		}
		if(nxt == curr)
			break;
		curr = nxt;
	}

	for(int i = 0; i < 26; ++i){
		if(used[i] || adj[i].size() == 2)
			continue;

		curr = i;
		while(true){
			used[curr] = true;
			start += curr + 'a';
			nxt = curr;

			for(int to: adj[curr]){
				if(used[to])
					continue;
				nxt = to;
			}
			if(nxt == curr)
				break;
			curr = nxt;
		}
	}

	if(start.size() != 26){
		cout << "NO\n";
		return;
	}
	if(adj[start.back() - 'a'].size() == 2){
		cout << "NO\n";
		return;
	}
	if(adj[start.back() - 'a'].size() == 1 && adj[start.back() - 'a'][0] != start[24] - 'a'){
		cout << "NO\n";
		return;
	}
	for(int i = 1; i < 25; ++i){
		for(int to: adj[start[i] - 'a']){
			if(to != start[i - 1] - 'a' && to != start[i + 1] - 'a'){
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";
	cout << start << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}