#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 3e5L + 11;

int start;

int n, m;
int ans[N];
int least_sac[N], suf_sac[N];

vector <int> diff;
vector <vector<int>> s;

int a[N], cnt[N];
int sac = 0;
bool dfs(int idx) {
	
	int now = clock();
	
	if(now - start > 1.8 * CLOCKS_PER_SEC)
		return 0;
	
	//~ cout << "------\n";
	//~ cout << idx << '\n';
	//~ cout << "sac " << sac << '\n';
	//~ for(int i = 0; i < n; i ++)
		//~ cout << a[i] << ' ';
	//~ cout << '\n';
	//~ for(int i = 0; i <= m; i ++)
		//~ cout << cnt[i] << ' ';
	//~ cout << '\n';
	
	if(sac + suf_sac[idx] > 2 * n)
		return 0;
	
	if(idx >= 3 && cnt[idx - 3])
		return 0;
	
	if(idx == diff.size())
		return 1;
	
	int x = diff[idx];
	map <int, set<int>> mp;
	for(int i = 0; i < n; i ++)
		mp[s[i][x]].insert(i);
	
	vector <pair <int, int>> ord;
	for(auto p : mp)
		ord.pb({(int)p.second.size(), p.first});
	sort(ord.begin(), ord.end());
	reverse(ord.begin(), ord.end());
	
	for(auto p : ord) {
		
		ans[x] = p.second;

		sac += n - p.first;
		for(int i : mp[p.second]) {
			cnt[a[i]] --;
			a[i] ++;
			cnt[a[i]] ++;
		}
	
		if(dfs(idx + 1))
			return 1;
	
		sac -= n - p.first;
		for(int i : mp[p.second]) {
			cnt[a[i]] --;
			a[i] --;
			cnt[a[i]] ++;
		}
	
	}
	
	return 0;
}

int main() {
	
	start = clock();
	
	ios :: sync_with_stdio(0);
	cin >> n >> m;
	s = vector <vector<int>> (n, vector <int>(m));
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
			cin >> s[i][j];
	
	vector <pair <int, int>> t_diff;
	for(int j = 0; j < m; j ++) {
		map <int, int> mp;
		for(int i = 0; i < n; i ++)
			mp[s[i][j]] ++;
		ans[j] = s[0][j];
		
		if(mp.size() != 1) {
			int ls = n;
			for(auto p : mp)
				ls = min(ls, n - p.second);
			t_diff.pb({ls, j});
		}
	}
	sort(t_diff.begin(), t_diff.end());
	for(auto p : t_diff) {
		least_sac[diff.size()] = p.first;
		diff.pb(p.second);
	}
	
	for(int i = (int)diff.size() - 1; i >= 0; i --)
		suf_sac[i] = suf_sac[i + 1] + least_sac[i];
	
	
	cnt[0] = n;
	if(dfs(0)) {
		cout << "Yes\n";
		for(int i = 0; i < m; i ++)
			cout << ans[i] << ' ';
		cout << '\n';
	} else
		cout << "No\n";
}