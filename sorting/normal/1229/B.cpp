#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const long long MAXN = 1e5 + 7;
const int LOGN = 20;

long long gcd(long long a, long long b){
	while(b){
		long long t = b;
		b = a % b;
		a = t;
	}

	return a;
}

long long x[MAXN], par[MAXN];
vector<int> adj[MAXN];
long long up_ver[MAXN][LOGN], up_gcd[MAXN][LOGN];
long long lvl[MAXN];

void dfs(int u, int p){
	par[u] = p;
	lvl[u] = lvl[p] + 1;
 
	for(int to: adj[u]){
		if(to == p){
			continue;
		}

		dfs(to, u);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 1; i <= n; ++i){
		cin >> x[i];
	}
	for(int i = 0; i < n - 1; ++i){
		int u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);

	for(int i = 1; i <= n; ++i){
		up_ver[i][0] = par[i];
		up_gcd[i][0] = gcd(x[i], x[par[i]]);
	}

	for(int j = 1; j < LOGN; ++j){
		for(int i = 1; i <= n; ++i){
			up_ver[i][j] = up_ver[ up_ver[i][j - 1] ][j - 1];
			up_gcd[i][j] = gcd(up_gcd[i][j - 1], up_gcd[ up_ver[i][j - 1] ][j - 1]);
		}
	}

	long long ans = 0;

	for(int i = 1; i <= n; ++i){
		int curr = i;
		long long curr_gcd = x[i];
		while(true){
			long long cnt = 0;
			int pr = curr;

			for(int j = LOGN - 1; j >= 0; --j){
				if(gcd(curr_gcd, up_gcd[curr][j]) == curr_gcd){
					curr = up_ver[curr][j];
					cnt += (1 << j);
				}
			}

			++cnt;
			cnt = min(cnt, lvl[pr]);
			ans += ((long long)cnt * (curr_gcd % mod)) % mod;
			ans %= mod;

			if(curr == 1){
				break;
			}

			curr = par[curr];
			curr_gcd = gcd(curr_gcd, x[curr]);
		}
		//cout << ans << " ans i " << i << endl;
	}

	cout << ans << "\n";

	return 0;
}