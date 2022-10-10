#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int k, cur;
map<ll, int> idx, box;
set<ll> all;
vector<int> v[15];
const int MAX = 16 * 5005;
int to[MAX], seen[MAX], stat[MAX], good[1 << 15], rec[1 << 15];
ll sum[16], num[MAX];
pair<int, int> ans[16];

void dfs(int s) {
	seen[s] = 1;
	if(to[s] == s) {
		good[1 << box[s]] = 1;
		//cout << (1 << box[s]) << " good\n";
		seen[s] = 2;
		rec[1 << box[s]] = -s;
		return;
	}
	if(to[s] != -1 && !seen[to[s]])
		dfs(to[s]);
	if(seen[to[s]] == 1) {
		if(stat[to[s]] == -1)
			stat[s] = to[s];
		else {
			if(stat[to[s]] == s) {
				int u = s;
				ll msk = 0;
				do{
					if(msk == -1 || (msk & (1 << box[u])))
						msk = -1;
					if(msk != -1)
						msk ^= (1 << box[u]);
					seen[u] = 2;
					u = to[u];
				} while(u != s);
				if(msk != -1) {
					good[msk] = 1;
					rec[msk] = -s;
					//cout << msk << " good\n";
				}
			}
			else
				stat[s] = stat[to[s]];
		}
	}
}

void solve(int m) {
	//cout << m << " " << rec[m] << endl;
	if(rec[m] > 0) {
		solve(rec[m]);
		solve(m ^ rec[m]);
		return;
	}
	int s = -rec[m];
	int u = s;
	do {
		ans[box[to[u]]] = {num[to[u]], box[u]};
		u = to[u];
	} while(u != s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	fill(to, to + MAX, -1);
	fill(stat, stat + MAX, -1);
	cin >> k;
	ll tot = 0;
	int vs = 0;
	for(int i = 0; i < k ; i++) {
		int n;
		cin >> n;
		vs += n;
		while(n--) {
			ll x;
			cin >> x;
			tot += x;
			v[i].push_back(x);
			all.insert(x);
			sum[i] += x;
			box[cur] = i;
			num[cur] = x;
			idx[x] = cur++;
		}
	}

	if(tot % k) {
		cout << "No\n";
		return 0;
	}
	ll target = tot / k;

	for(int i = 0; i < k; i++) {
		for(auto x : v[i]) {
			int u = idx[x];
			ll need = target - (sum[i] - x);
			if(!all.count(need))
				continue;
			int w = idx[need];
			if(u != w && box[u] == box[w])
				continue;
			to[u] = w;
			//cout << w << " -> " << u << endl;
		}
	}

	for(int i = 0; i < vs; i++) {
		if(!seen[i])
			dfs(i);
	}

	good[0] = 1;
	for(int msk = 1; msk < (1 << k); msk++) {
		for(int sm = msk; sm > 0; sm = (sm - 1) & msk) {
			if(good[msk])
				break;
			if(good[sm] & good[msk^sm]) {
				good[msk] = 1;
				rec[msk] = sm;
			}
		}
	}
	//cout << good[(1<<k)  - 1] << '\n';
	if(!good[(1 << k) - 1]) {
		cout << "No\n";
		return 0;
	}
	cout << "Yes\n";
	solve((1 << k) - 1);
	for(int i = 0; i < k; i++) {
		cout << ans[i].first << " " << ans[i].second + 1 << '\n';
	}
}