#include <bits/stdc++.h>

using namespace std;
#define maxn 205

int n;
vector<vector<int>> bef(maxn); //what must be done before me
int nums[maxn];
int ans = 0;
bool vis[maxn];

int fspot[maxn], sspot[maxn];

vector<int> ord; //add me after adding all after me

void dfs(int u) {
	vis[u] = true;
	for (int v : bef[u]) {
		if (!vis[v]) {
			dfs(v);
		}
	}
	ord.push_back(u);
}

int main() {
	fill(fspot, fspot+maxn, -1);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < 2*n; i++) {
		cin >> nums[i];
		if (fspot[nums[i]] == -1) {
			fspot[nums[i]] = i;
		}
		else sspot[nums[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (fspot[i] < fspot[j] && sspot[j] < sspot[i]) {
				bef[j].push_back(i);
			}
		}
	}
	vector<int> cur;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) dfs(i);

	}
	for (int i = 0; i < 2*n; i++) {
		cur.push_back(nums[i]);
	}
	for (int val : ord) {
		// cout << "val: " << val << endl;
		int s1 = -1, s2 = -1;
		for (int i = 0; i < cur.size(); i++) {
			if (cur[i] == val) {
				if (s1 == -1) s1 = i;
				else s2 = i;
			}
		}
		// cout << "   " << s2 << " " << s1 << endl;
		ans += s2-s1-1;
		vector<int> v2;
		for (int i = 0; i < cur.size(); i++) {
			if (i == s1 || i == s2) continue;
			v2.push_back(cur[i]);
		}
		cur.clear();
		for (int vc : v2) cur.push_back(vc);
	}
	cout << ans << endl;
	cin >> ans;

}