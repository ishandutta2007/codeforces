#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 8e3 + 10;

int n, r_cnt, deg[MAXN], F[MAXN];
bool M[MAXN][MAXN], B[MAXN];
ll ans = 0;

inline bool topolSort(int v, int u) {
	return M[v][u];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j += 4) {
			char c = s[j / 4];
			int k = (c <= '9' ? c - '0' : 10 + (c - 'A'));
			
			deg[j + 1] += M[i][j + 1] = ((k & 8) != 0); 
			deg[j + 2] += M[i][j + 2] = ((k & 4) != 0); 
			deg[j + 3] += M[i][j + 3] = ((k & 2) != 0); 
			deg[j + 4] += M[i][j + 4] = ((k & 1) != 0); 
		}
	}


	bool flag = true;
	while (flag) {
		flag = false;
		for (int v = 1; v <= n; v++) {
			if (B[v]) continue;
			if (deg[v] == n - r_cnt - 1 || deg[v] == 0) {
				flag = true;
				r_cnt++;
				B[v] = true;

				for (int u = 1; u <= n; u++)
					deg[u] -= M[v][u];
				
				ans += n - r_cnt;
				ans += 614ll * (n - r_cnt) * n;
			}
		}

	}

	int r = 0;
	for (int v = 1; v <= n; v++) 
		if (!r || deg[v] > deg[r])
			r = v;
	if (!r) return cout << ans << endl, 0;

	vector<int> q, p;
	for (int v = 1; v <= n; v++) {
		if (!B[v]) { // diam
			if (M[r][v]) p.push_back(v);
			else q.push_back(v);
		}
	}

	sort(all(q), topolSort);
	sort(all(p), topolSort);

	ans += 3ll * q.size() * p.size();
	ans += 3ll * p.size() * (int(p.size()) - 1) / 2;
	ans += 3ll * q.size() * (int(q.size()) - 1) / 2;

	for (int e : p)
		for (int e2 : q)
			F[e] += M[e][e2];

	for (int e : q)
		for (int e2 : p)
			F[e] += M[e][e2];

	for (int i = 0; i < int(p.size()); i++)
		for (int j = i + 1; j < int(p.size()); j++)
			ans += (F[p[i]] == F[p[j]]);
	
	for (int i = 0; i < int(q.size()); i++)
		for (int j = i + 1; j < int(q.size()); j++)
			ans += (F[q[i]] == F[q[j]]);

	cout << ans << endl;
	return 0;
}