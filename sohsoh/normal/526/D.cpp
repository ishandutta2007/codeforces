// \_()_/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, k, F[MAXN], rem, tmp = 0, T = 0, tin[MAXN], tout[MAXN];
string s;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int v) {
	vis[v] = true;
	tin[v] = T++;
	for (int u : adj[v])
		dfs(u);
	tout[v] = T++;
}	

inline bool Check(int ind, int sz) {
	if (ind == sz - 1) return true;
	ind = F[ind];
	return vis[ind] && tin[sz] <= tin[ind] && tout[sz] >= tout[ind];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> s;
	if (k == 1) {
		for (int i = 0; i < n; i++) 
			cout << 1;
		cout << endl;
		return 0;
	}
	
	cout << 0;
	int t = 0;
	for (int i = 1; i < n; i++) {
		while (t && s[t] != s[i])
			t = F[t - 1];
		F[i] = (t += s[t] == s[i]);
		if (t) adj[t - 1].push_back(i);
	}

	for (int i = 0; i < n; i++)
		if (!vis[i])
			dfs(i);

	for (int i = 1; i < n; i++) {
		if (i % k == k - 1) {
			bool flag = true;
			int j = i, p = ((i + 1) / k);
				
			while (j >= p) {
				flag &= Check(j, p);
				j -= p;
			}

			if (flag) rem = p + 1, tmp = 0;
		}
		
		cout << (rem > 0 && Check(i, tmp) ? 1 : 0);
		rem--;
		tmp++;
	}

	cout << endl;
	return 0;
}