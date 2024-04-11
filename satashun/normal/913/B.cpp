#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

int n;
vi g[1010];
bool lf[1010];

bool dfs(int v)
{
	lf[v] = 1;
	int cnt = 0;

	for (int to : g[v]) {
		lf[v] = 0;
		if (!dfs(to)) {
			return false;
		}
		if (lf[to]) {
			++cnt;
		}
	}

	if (!lf[v] && cnt < 3) {
		return false;
	}
	return true;
}

int main() {
	cin >> n;

	rep(i, n-1) {
		int p;
		cin >> p;
		--p;
		g[p].pb(i+1);
	}

	puts(dfs(0) ? "Yes" : "No"); 

	return 0;
}