#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int SQ_C = 55;

vector<int> adj[MAXN];
int n, m;
long long ans = 0;
pair<long long, long long> p[MAXN];
bool used[MAXN];
long long pos[MAXN];
bool one_time[MAXN];

set<pair<int, int> > e;

long long quer[MAXN];

void refresh(){
	for(int i = 1; i <= n; ++i){
		used[i] = false;
	}
}

bool check(int u, int v){
	if(u > v){
		swap(u, v);
	}

	if(e.count({u, v})){
		return true;
	}

	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < m; ++i){
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);

		if(u > v){
			swap(u, v);
		}

		++p[u].second;
		++p[v].first;

		e.insert({u, v});
	}

	for(int i = 1; i <= n; ++i){
		ans += p[i].first * p[i].second;
		pos[i] = i - 1;
	}

	int q;

	cin >> q;

	cout << ans << "\n";

	for(int i = 0; i < q; ++i){
		if(i % SQ_C == 0){
			refresh();
		}

		int v;

		cin >> v;
		quer[i] = v;

		if(!used[v]){
			for(int to: adj[v]){
				if(pos[to] > pos[v]){
					ans -= p[to].first * p[to].second;
					--p[to].first;
					++p[to].second;
					ans += p[to].first * p[to].second;
				}
			}
			ans -= p[v].first * p[v].second;
			p[v].first = (long long)adj[v].size();
			p[v].second = 0;

			used[v] = true;
			pos[v] = i + n;
		}
		else{
			int rem = i % SQ_C;
			if(rem < 0)
				rem += SQ_C;
			if(rem >= SQ_C)
				rem -= SQ_C;

			int pr = i - rem;

			for(int j = pr; j < i; ++j){
				int to = quer[j];
				if(one_time[to]){
					continue;
				}
				one_time[to] = true;
				if(check(v, to)){
					if(pos[to] > pos[v]){
						ans -= p[to].first * p[to].second;
						--p[to].first;
						++p[to].second;
						ans += p[to].first * p[to].second;
					}
				}
			}
			for(int j = pr; j < i; ++j){
				int to = quer[j];
				one_time[to] = false;
			}

			ans -= p[v].first * p[v].second;
			p[v].first = (long long)adj[v].size();
			p[v].second = 0;

			used[v] = true;
			pos[v] = i + n;
		}

		cout << ans << "\n";
	}

	return 0;
}