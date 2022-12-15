#include <bits/stdc++.h>

using namespace std;

const unsigned long long N = 1e6 + 7;
//const unsigned long long mod = 12e8 + 41;
const unsigned long long base = 1e6 + 7;

vector<int> adj[N];

unsigned long long calc_hash(const vector<int> &v, int add = -1){
	unsigned long long ret = 0;

	if(add != -1 && (v.empty() || add < v[0])){
		ret *= base;
		ret += (unsigned long long)add;
	}

	for(int i = 0; i < v.size(); ++i){
		ret *= base;
		ret += (unsigned long long)v[i];
		//ret %= mod;

		if(add != -1 && i != (int)v.size() - 1 && v[i] < add && add < v[i + 1]){
			ret *= base;
			ret += (unsigned long long)add;
		}
	}

	if(!v.empty() && add > v.back()){
		ret *= base;
		ret += (unsigned long long)add;
	}

	return ret;
}

pair<int, int> e[N];
unsigned long long arr[N];
unsigned long long hash_with[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	for(int i = 0; i < m; ++i){
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);

		e[i] = {u, v};
	}

	unsigned long long res = 0;

	for(int i = 1; i <= n; ++i){
		sort(adj[i].begin(), adj[i].end());
		arr[i] = calc_hash(adj[i]);
		hash_with[i] = calc_hash(adj[i], i);
	}

	sort(arr + 1, arr + 1 + n);

	unsigned long long curr = 0;

	for(int i = 1; i <= n; ++i){
		curr++;
		if(i == n || arr[i] != arr[i+1]){
			res += curr * (curr - 1ull) / 2ull;
			curr = 0ull;
		}
	}

	for(int i = 0; i < m; ++i){
		int u = e[i].first, v = e[i].second;

		if(adj[u].size() == adj[v].size() && hash_with[u] == hash_with[v]){
			res++;
		}
	}

	cout << res << "\n";

	return 0;
}