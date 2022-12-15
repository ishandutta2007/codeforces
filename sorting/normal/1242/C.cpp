#include <bits/stdc++.h>

using namespace std;

const long long MAXK = 15 + 1;
const long long MAXN = 5000 + 7;
const long long MAX_MASK = 1 << MAXK;

int k;
long long sum[MAXK], v[MAXK][MAXN], n[MAXK];
long long used[MAXK][MAXN];
map<long long, pair<long long, long long> > pos;

vector<pair<long long, long long> > curr_cycle;

pair<long long, long long> ans[MAXK];
vector<pair<long long, long long> > before_dp[MAX_MASK];
bool dp[MAX_MASK];
int par[MAX_MASK];
vector<pair<long long, long long> > vec;

void dfs(long long i, long long j, long long it){
	used[i][j] = it;

	long long want = v[i][j] + sum[i];
	if(!pos.count(want)){
		return;
	}

	curr_cycle.push_back({i, j});

	pair<long long, long long> p = pos[want];
	if(used[p.first][p.second]){
		if(used[p.first][p.second] == it){
			long long mask = 0;
			vec.clear();

			bool ok = true;
			while(curr_cycle.back() != p){
				if(mask & (1 << curr_cycle.back().first)){
					ok = false;
					break;
				}
				mask += (1 << curr_cycle.back().first);
				vec.push_back(curr_cycle.back());
				curr_cycle.pop_back();
			}
			mask += (1 << p.first);
			vec.push_back(p);
			
			if(ok){
				before_dp[mask] = vec;
			}
		}
		return;
	}

	dfs(p.first, p.second, it);
}

void solve(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;

	long long sum_all = 0;
	for(long long i = 0; i < k; ++i){
		cin >> n[i];
		for(long long j = 0; j < n[i]; ++j){
			long long x;
			cin >> x;

			v[i][j] = x;
			pos[x] = {i, j};
			sum[i] += x;
		}
		sum_all += sum[i];
	}

	if(sum_all % k != 0){
		cout << "No\n";
		return;
	}

	for(long long i = 0; i < k; ++i){
		sum[i] = (sum_all / k) - sum[i];
	}

	long long it = 1;
	for(long long i = 0; i < k; ++i){
		for(long long j = 0; j < n[i]; ++j){
			if(!used[i][j]){
				curr_cycle.clear();
				dfs(i, j, it++);
			}
		}
	}

	dp[0] = true;

	for(int i = 1; i < (1 << k); ++i){
		for(int j = i; j; j = (j - 1) & i){
			if(dp[i - j] && before_dp[j].size()){
				dp[i] = true;
				par[i] = j;
				break;
			}
		}
	}

	if(dp[(1 << k) - 1] == false){
		cout << "No\n";
		return;
	}

	int curr = (1 << k) - 1;
	while(curr){
		for(auto p: before_dp[par[curr]]){
			ans[p.first].first = v[p.first][p.second];
			long long want = v[p.first][p.second] + sum[p.first];
			ans[pos[want].first].second = p.first + 1;
		}
		curr -= par[curr];
	}

	cout << "Yes\n";
	for(int i = 0; i < k; ++i){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
}

int main(){
	solve();
}